' ============================================================
' Daily Task Rollover - auto-promotes the next task
' Runs automatically each day at 10:55 before the 11:00 reminder.
'
' NEW BEHAVIOR:
'   1. Find the current task (newest .c in the main folder)
'   2. Task is DONE if a matching .exe exists next to the .c,
'      OR if the .c file itself was edited on a previous day
'      (code written but never compiled -> still counts as done)
'   3. Rollover happens ONLY ON THE NEXT DAY after completing
'      (if the .exe was built / .c edited today, we wait until tomorrow)
'   4. On rollover: MOVE the .c into the GitHub repo folder
'      (VS Code\C) and auto git add/commit/push
'   5. Promote the next task from _queue\ into the main folder
'   6. Write _state.txt so Buffy can read progress instantly
' ============================================================
Option Explicit

Dim fso, objShell, sScriptDir, sDir, sQueueDir, sGithubDir, sDailyDir
Dim objFolder, objFile, sCurrentTask, sBase, sExePath
Dim sNextTask, bPromoted, ts, sState, sGitLog, sMsg
Dim bDone, bRolloverReady, sDoneExe, sCmd, nGitExit
Dim sRaw, sOut, sLine, arrLines, oStream, oBin, oRest, sNl, i
Dim cTaskFile, dCreated, dModified
Dim sQuestions, sHistory, sBackupQueue, oIn, sStateLine
Dim sPromotedName, sPromotedSize, sPromotedSum, sPromotedOn
Dim sLastCompleted, nStreak, nTotalDone, lQSize, lQSum
Dim bContentChanged, sQLog, dCompletion, sDoneHow, dLast, sQOld
Dim sAutomation

Set fso = CreateObject("Scripting.FileSystemObject")
Set objShell = CreateObject("WScript.Shell")

sScriptDir = fso.GetParentFolderName(WScript.ScriptFullName)
sDir = fso.GetParentFolderName(sScriptDir)
sQueueDir = sDir & "\_queue"
sGithubDir = "C:\Users\SERVER\Desktop\VS Code\C"
sDailyDir = sGithubDir & "\Daily-Tasks"
sState = sScriptDir & "\_state.txt"
sGitLog = sScriptDir & "\_git.log"

If Not fso.FolderExists(sGithubDir) Then fso.CreateFolder sGithubDir
If Not fso.FolderExists(sDailyDir) Then fso.CreateFolder sDailyDir
If Not fso.FolderExists(sQueueDir) Then fso.CreateFolder sQueueDir

' --- read previous progress state (streak, total, skeleton hash) ---
sPromotedName = ""
sPromotedSize = ""
sPromotedSum = ""
sPromotedOn = ""
sLastCompleted = ""
nStreak = 0
nTotalDone = 0
sQuestions = sDailyDir & "\_questions.log"
sHistory = sScriptDir & "\_history.log"
sBackupQueue = sDailyDir & "\_queue"
sAutomation = sDailyDir & "\_automation"
If fso.FileExists(sState) Then
    Set oIn = fso.OpenTextFile(sState, 1)
    Do Until oIn.AtEndOfStream
        sStateLine = oIn.ReadLine
        If Left(sStateLine, 9) = "promoted=" Then sPromotedName = Mid(sStateLine, 10)
        If Left(sStateLine, 14) = "promoted-size=" Then sPromotedSize = Mid(sStateLine, 15)
        If Left(sStateLine, 13) = "promoted-sum=" Then sPromotedSum = Mid(sStateLine, 14)
        If Left(sStateLine, 12) = "promoted-on=" Then sPromotedOn = Mid(sStateLine, 13)
        If Left(sStateLine, 15) = "last-completed=" Then sLastCompleted = Mid(sStateLine, 16)
        If Left(sStateLine, 7) = "streak=" Then nStreak = CLng(Mid(sStateLine, 8))
        If Left(sStateLine, 11) = "total-done=" Then nTotalDone = CLng(Mid(sStateLine, 12))
    Loop
    oIn.Close
End If

' --- Step 1: find current task (newest .c in main folder) ---
sCurrentTask = ""
Set objFolder = fso.GetFolder(sDir)
For Each objFile In objFolder.Files
    If LCase(fso.GetExtensionName(objFile.Name)) = "c" Then
        If sCurrentTask = "" Then
            sCurrentTask = objFile.Name
        ElseIf objFile.DateLastModified > fso.GetFile(sDir & "\" & sCurrentTask).DateLastModified Then
            sCurrentTask = objFile.Name
        End If
    End If
Next

bPromoted = False
bDone = False
sDoneExe = ""

If sCurrentTask <> "" Then
    sBase = Left(sCurrentTask, Len(sCurrentTask) - 2)   ' strip ".c"
    sExePath = sDir & "\" & sBase & ".exe"

    ' done check #1: exe with the same base name
    If fso.FileExists(sExePath) Then
        bDone = True
        sDoneExe = sExePath
    End If

    ' done check #2 (fallback): same base name exe exists, even if mtime is odd
    If Not bDone Then
        If fso.FileExists(sExePath) Then
            bDone = True
            sDoneExe = sExePath
        End If
    End If

    ' done check #3 (NO-EXE fallback): did the student actually DO the task?
    '  - Preferred: compare the .c against the skeleton hash recorded when it
    '    was promoted (promoted-size/promoted-sum in _state.txt). Any content
    '    change means real work - opening + saving the file alone can't fool it.
    '  - Legacy: if no hash is recorded yet, use mtime > creation time.
    If Not bDone Then
        Set cTaskFile = fso.GetFile(sDir & "\" & sCurrentTask)
        dCreated = cTaskFile.DateCreated
        dModified = cTaskFile.DateLastModified
        Set cTaskFile = Nothing

        bContentChanged = False
        If sPromotedSum <> "" And sPromotedSize <> "" Then
            ' hash the current file (same method used at promotion time)
            Set oStream = CreateObject("ADODB.Stream")
            oStream.Type = 2
            oStream.Charset = "utf-8"
            oStream.Open
            oStream.LoadFromFile sDir & "\" & sCurrentTask
            sRaw = oStream.ReadText
            oStream.Close
            lQSize = Len(sRaw)
            lQSum = 0
            For i = 1 To lQSize
                lQSum = lQSum + AscW(Mid(sRaw, i, 1))
            Next
            If lQSize <> CLng(sPromotedSize) Or lQSum <> CLng(sPromotedSum) Then
                bContentChanged = True
            End If
        Else
            If dModified > dCreated Then
                bContentChanged = True
            End If
        End If

        If bContentChanged Then
            bDone = True
            sDoneExe = ""   ' no exe involved - done via .c edit
        End If
    End If

    ' NEW: only roll over on the NEXT DAY after completing.
    ' If the .exe was built TODAY (or the .c edited TODAY), wait until tomorrow.
    bRolloverReady = False
    If bDone Then
        If sDoneExe <> "" Then
            ' done via compiled exe: wait a day after the exe was built
            If DateValue(fso.GetFile(sDoneExe).DateLastModified) < DateValue(Now) Then
                bRolloverReady = True
            End If
        Else
            ' done via .c edit (no exe): wait a day after the edit
            If DateValue(dModified) < DateValue(Now) Then
                bRolloverReady = True
            End If
        End If
    End If
    If bRolloverReady Then
        ' --- task done YESTERDAY (or earlier): roll it over ---
            ' --- record completion: date, streak, history ---
            If sDoneExe <> "" Then
                dCompletion = DateValue(fso.GetFile(sDoneExe).DateLastModified)
                sDoneHow = "exe"
            Else
                dCompletion = DateValue(dModified)
                sDoneHow = "c-edit"
            End If
            If sLastCompleted <> "" Then
                dLast = DateSerial(CLng(Mid(sLastCompleted, 1, 4)), CLng(Mid(sLastCompleted, 6, 2)), CLng(Mid(sLastCompleted, 9, 2)))
                If dLast = (dCompletion - 1) Then
                    nStreak = nStreak + 1
                ElseIf dLast <> dCompletion Then
                    nStreak = 1
                End If
            Else
                nStreak = 1
            End If
            nTotalDone = nTotalDone + 1
            On Error Resume Next   ' best effort
            Set ts = fso.OpenTextFile(sHistory, 8, True)
            ts.WriteLine IsoDate(dCompletion) & " | " & sCurrentTask & " | " & sDoneHow & " | streak=" & nStreak & " | total=" & nTotalDone
            ts.Close
            On Error GoTo 0
            sLastCompleted = IsoDate(dCompletion)


            ' Move the completed .c into VS Code\C\Daily-Tasks
            If fso.FileExists(sDailyDir & "\" & sCurrentTask) Then
                fso.DeleteFile sDailyDir & "\" & sCurrentTask
            End If

            ' Clean up the .c: keep the header up to the closing === line,
            ' drop the "You write ALL the code below" / "Stuck?" / "// QUESTION:" lines
            Set oStream = CreateObject("ADODB.Stream")
            oStream.Type = 2
            oStream.Charset = "utf-8"
            oStream.Open
            oStream.LoadFromFile sDir & "\" & sCurrentTask
            sRaw = oStream.ReadText
            oStream.Close
            sNl = vbLf
            If InStr(sRaw, vbCrLf) > 0 Then sNl = vbCrLf
            arrLines = Split(sRaw, sNl)
            sOut = ""
            sQLog = ""
            For Each sLine In arrLines
                ' save the student's real questions instead of losing them
                If (InStr(1, sLine, "Stuck?", vbTextCompare) > 0 Or _
                    InStr(1, sLine, "// QUESTION:", vbTextCompare) > 0) And _
                   Trim(sLine) <> "Stuck? Write below the code:" And _
                   Trim(sLine) <> "// QUESTION: ...your question here..." Then
                    sQLog = sQLog & vbCrLf & Trim(sLine)
                End If
                If InStr(1, sLine, "Stuck?", vbTextCompare) = 0 And _
                   InStr(1, sLine, "// QUESTION:", vbTextCompare) = 0 And _
                   InStr(1, sLine, "write all the code below", vbTextCompare) = 0 Then
                    sOut = sOut & sLine & sNl
                End If
            Next
            ' write the questions to the git-backed log (repo folder, UTF-8)
            If sQLog <> "" Then
                On Error Resume Next   ' best effort
                Set oStream = CreateObject("ADODB.Stream")
                oStream.Type = 2
                oStream.Charset = "utf-8"
                oStream.Open
                If fso.FileExists(sQuestions) Then
                    oStream.LoadFromFile sQuestions
                    sQOld = oStream.ReadText
                Else
                    sQOld = ""
                End If
                oStream.Close
                oStream.Open
                oStream.WriteText sQOld & "[" & IsoDate(Date) & " " & Time & "] " & sCurrentTask & ":" & sQLog & vbCrLf
                oStream.SaveToFile sQuestions, 2
                oStream.Close
                On Error GoTo 0
            End If
            ' tidy: collapse repeated blank lines
            Do While InStr(sOut, sNl & sNl) > 0
                sOut = Replace(sOut, sNl & sNl, sNl)
            Loop
            ' drop blank line(s) right before the closing === ... */ line
            arrLines = Split(sOut, sNl)
            sOut = ""
            For i = 0 To UBound(arrLines)
                sLine = arrLines(i)
                If Trim(sLine) = "" Then
                    If i < UBound(arrLines) Then
                        If InStr(arrLines(i + 1), "====") > 0 And _
                           InStr(arrLines(i + 1), "*/") > 0 Then
                            ' skip blank right before the closing separator
                        Else
                            sOut = sOut & sLine & sNl
                        End If
                    End If
                Else
                    sOut = sOut & sLine & sNl
                End If
            Next
            If sOut <> sRaw Then
                Set oStream = CreateObject("ADODB.Stream")
                oStream.Type = 2
                oStream.Charset = "utf-8"
                oStream.Open
                oStream.WriteText sOut
                oStream.Position = 0
                Set oBin = CreateObject("ADODB.Stream")
                oBin.Type = 1
                oBin.Open
                oStream.CopyTo oBin
                oBin.Position = 3
                Set oRest = CreateObject("ADODB.Stream")
                oRest.Type = 1
                oRest.Open
                oBin.CopyTo oRest
                oRest.SaveToFile sDir & "\" & sCurrentTask, 2
                oRest.Close
                oBin.Close
                oStream.Close
            End If

            fso.MoveFile sDir & "\" & sCurrentTask, sDailyDir & "\" & sCurrentTask

            ' Clean up the compiled .exe (it lives next to the .c in the main folder)
            If fso.FileExists(sDir & "\" & sBase & ".exe") Then
                fso.DeleteFile sDir & "\" & sBase & ".exe"
            End If

            ' backup: mirror _queue into the repo so every future task is versioned
            On Error Resume Next   ' best effort - a locked file must not kill the rollover
            BackupQueue()
            On Error GoTo 0


            ' Auto git add + commit + push (best effort) via helper bat
            sCmd = Chr(34) & sScriptDir & "\push-to-github.bat" & Chr(34) & " " & Chr(34) & sCurrentTask & Chr(34)
            nGitExit = objShell.Run(sCmd, 0, True)

            ' --- promote the lowest-numbered task from the queue ---
            sNextTask = ""
            Set objFolder = fso.GetFolder(sQueueDir)
            For Each objFile In objFolder.Files
                If LCase(fso.GetExtensionName(objFile.Name)) = "c" Then
                    If sNextTask = "" Then
                        sNextTask = objFile.Name
                    ElseIf objFile.Name < sNextTask Then
                        sNextTask = objFile.Name
                    End If
                End If
            Next

            If sNextTask <> "" Then
                fso.MoveFile sQueueDir & "\" & sNextTask, sDir & "\" & sNextTask
                bPromoted = True
                sPromotedName = sNextTask
                sPromotedOn = IsoDate(Date)
                RecordPromotedHash()
            Else
                ' queue is empty - the recorded promoted task is stale now
                sPromotedName = ""
                sPromotedSize = ""
                sPromotedSum = ""
                sPromotedOn = ""
            End If
        End If
ElseIf fso.GetFolder(sQueueDir).Files.Count > 0 Then
    ' no active task at all: promote the first one
    sNextTask = ""
    Set objFolder = fso.GetFolder(sQueueDir)
    For Each objFile In objFolder.Files
        If LCase(fso.GetExtensionName(objFile.Name)) = "c" Then
            If sNextTask = "" Then
                sNextTask = objFile.Name
            ElseIf objFile.Name < sNextTask Then
                sNextTask = objFile.Name
            End If
        End If
    Next
    If sNextTask <> "" Then
        fso.MoveFile sQueueDir & "\" & sNextTask, sDir & "\" & sNextTask
        bPromoted = True
        sPromotedName = sNextTask
        sPromotedOn = IsoDate(Date)
        RecordPromotedHash()
    Else
        sPromotedName = ""
        sPromotedSize = ""
        sPromotedSum = ""
        sPromotedOn = ""
    End If
    ' keep the repo copy of the remaining queue in sync here too
    On Error Resume Next   ' best effort
    BackupQueue()
    On Error GoTo 0
End If

' --- write state file for Buffy ---
Set ts = fso.CreateTextFile(sState, True)
If sCurrentTask <> "" Then
    ts.WriteLine "last-task=" & sCurrentTask
End If
If bDone Then
    ts.WriteLine "done=1"
    If sDoneExe <> "" Then
        ts.WriteLine "done-exe=" & sDoneExe
    Else
        ts.WriteLine "done-by=c-edit"   ' no .exe - done because the .c was edited
    End If
    If bRolloverReady Then
        ts.WriteLine "rollover=ready"
    Else
        ts.WriteLine "rollover=next-day"   ' completed today, moves tomorrow
    End If
End If
If sPromotedName <> "" Then
    ts.WriteLine "promoted=" & sPromotedName
    ts.WriteLine "promoted-size=" & sPromotedSize
    ts.WriteLine "promoted-sum=" & sPromotedSum
    ts.WriteLine "promoted-on=" & sPromotedOn
End If
If nTotalDone > 0 Then
    ts.WriteLine "streak=" & nStreak
    ts.WriteLine "total-done=" & nTotalDone
    ts.WriteLine "last-completed=" & sLastCompleted
End If
ts.WriteLine "queue-count=" & fso.GetFolder(sQueueDir).Files.Count
If bDone Then
    If bRolloverReady Then
        ts.WriteLine "moved-to-github=Daily-Tasks\" & sCurrentTask
        If nGitExit = 0 Then
            ts.WriteLine "git-push=ok"
        Else
            ts.WriteLine "git-push=failed(" & nGitExit & ")"
        End If
    End If
End If
ts.WriteLine "checked=" & Now
ts.Close

' version the automation scripts + fresh state in the repo (best effort)
On Error Resume Next
BackupScripts()
On Error GoTo 0

' --- tiny confirmation popup so you KNOW it rolled over ---
If bPromoted Then
    sMsg = "Task rolled over!" & vbCrLf & vbCrLf & _
        sCurrentTask & " is DONE and pushed to GitHub (Daily-Tasks)." & vbCrLf & _
        "Next up: " & sNextTask & vbCrLf & vbCrLf & _
        "Open VS Code and keep going!"
    If nGitExit <> 0 Then
        sMsg = sMsg & vbCrLf & vbCrLf & "(git push returned code " & nGitExit & " - check _git.log)"
    End If
    MsgBox sMsg, vbOKOnly + vbInformation, "Daily Tasks - Progress!"
End If

' --- helpers ---
Function Pad2(v)
    Pad2 = Right("0" & v, 2)
End Function

Function IsoDate(d)
    IsoDate = Year(d) & "-" & Pad2(Month(d)) & "-" & Pad2(Day(d))
End Function

Sub RecordPromotedHash()
    Dim sTxt, i, nS
    Set oStream = CreateObject("ADODB.Stream")
    oStream.Type = 2
    oStream.Charset = "utf-8"
    oStream.Open
    oStream.LoadFromFile sDir & "\" & sNextTask
    sTxt = oStream.ReadText
    oStream.Close
    sPromotedSize = CStr(Len(sTxt))
    nS = 0
    For i = 1 To Len(sTxt)
        nS = nS + AscW(Mid(sTxt, i, 1))
    Next
    sPromotedSum = CStr(nS)
End Sub

Sub BackupQueue()
    If Not fso.FolderExists(sBackupQueue) Then fso.CreateFolder sBackupQueue
    Set objFolder = fso.GetFolder(sQueueDir)
    For Each objFile In objFolder.Files
        If LCase(fso.GetExtensionName(objFile.Name)) = "c" Then
            fso.CopyFile objFile.Path, sBackupQueue & "\" & objFile.Name, True
        End If
    Next
End Sub

Sub BackupScripts()
    ' version the automation itself: scripts + progress state + history
    If Not fso.FolderExists(sAutomation) Then fso.CreateFolder sAutomation
    Dim aFiles
    aFiles = Array("rollover.vbs", "remind.vbs", "remind-compulsory.vbs", "push-to-github.bat", "_state.txt", "_history.log")
    Dim sName
    For Each sName In aFiles
        If fso.FileExists(sScriptDir & "\" & sName) Then
            fso.CopyFile sScriptDir & "\" & sName, sAutomation & "\" & sName, True
        End If
    Next
End Sub

Set fso = Nothing
Set objShell = Nothing
