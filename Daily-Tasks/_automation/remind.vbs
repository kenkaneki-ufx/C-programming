' ============================================================
' Daily Code Reminder - 11:00 AM popup
' "Yes" opens the current task file directly (like double-
' clicking it) so it opens in normal VS Code with no issues.
' "No"/"Cancel" snoozes and schedules the compulsory popup at 12:00.
' ============================================================
Option Explicit

Dim objShell, fso, sScriptDir, sTaskDir, sCodeExe, sAnswer, sCmd
Dim objFolder, objFile, sTaskFile
Dim sState, sStatus, sStreak, sLastDone, sTaskName, sLine2, oIn
Dim dLast, nGap, sDoneFlag, sRollFlag, sMoved, sMsg, sQueueCount

Set objShell = CreateObject("WScript.Shell")
Set fso = CreateObject("Scripting.FileSystemObject")

sScriptDir = fso.GetParentFolderName(WScript.ScriptFullName)
sTaskDir = fso.GetParentFolderName(sScriptDir)
sCodeExe = "C:\Users\SERVER\AppData\Local\Programs\Microsoft VS Code\Code.exe"

' --- personalize the reminder from _state.txt ---
sState = sScriptDir & "\_state.txt"
sStatus = ""
sStreak = ""
sLastDone = ""
sTaskName = "today's task"
sDoneFlag = ""
sRollFlag = ""
sMoved = ""
If fso.FileExists(sState) Then
    Set oIn = fso.OpenTextFile(sState, 1)
    Do Until oIn.AtEndOfStream
        sLine2 = oIn.ReadLine
        If Left(sLine2, 7) = "streak=" Then sStreak = Mid(sLine2, 8)
        If Left(sLine2, 15) = "last-completed=" Then sLastDone = Mid(sLine2, 16)
        If Left(sLine2, 9) = "promoted=" Then sTaskName = Mid(sLine2, 10)
        If Left(sLine2, 5) = "done=" Then sDoneFlag = Mid(sLine2, 6)
        If Left(sLine2, 9) = "rollover=" Then sRollFlag = Mid(sLine2, 10)
        If Left(sLine2, 16) = "moved-to-github=" Then sMoved = Mid(sLine2, 17)
        If Left(sLine2, 12) = "queue-count=" Then sQueueCount = Mid(sLine2, 13)
    Loop
    oIn.Close
End If

' streak line - always celebrate it when it is alive
If sStreak <> "" Then
    If CLng(sStreak) >= 2 Then
        sStatus = sStatus & "You're on a " & sStreak & "-day streak - keep it alive!" & vbCrLf
    End If
End If

' task status line
If sDoneFlag = "1" And sRollFlag = "next-day" Then
    sStatus = sStatus & "Today's task is already done - great job!" & vbCrLf
ElseIf sDoneFlag = "1" And sRollFlag = "ready" Then
    sStatus = sStatus & "Yesterday's task was done and pushed to GitHub." & vbCrLf
Else
    If sLastDone <> "" Then
        dLast = DateSerial(CLng(Mid(sLastDone, 1, 4)), CLng(Mid(sLastDone, 6, 2)), CLng(Mid(sLastDone, 9, 2)))
        nGap = DateDiff("d", dLast, Date)
        If nGap >= 2 Then
            sStatus = sStatus & "You missed " & (nGap - 1) & " day(s) - one task today gets you back on track!" & vbCrLf
        End If
    End If
End If

' queue health - warn before it runs dry
If sQueueCount <> "" Then
    If CLng(sQueueCount) < 3 Then
        sStatus = sStatus & "Only " & sQueueCount & " task(s) left in the queue - ask Buffy to refill soon!" & vbCrLf
    End If
End If

sMsg = "[!] Time for your DAILY CODING TASK!" & vbCrLf & vbCrLf
If sStatus <> "" Then
    sMsg = sMsg & sStatus & vbCrLf
End If
sMsg = sMsg & "Today's task: " & sTaskName & vbCrLf
If sMoved <> "" Then
    sMsg = sMsg & "Completed: " & sMoved & vbCrLf
End If
sMsg = sMsg & vbCrLf & _
    "  Yes    -> Open the task and start now" & vbCrLf & _
    "  No     -> Snooze 1 hour (compulsory at 12:00)" & vbCrLf & _
    "  Cancel -> Snooze 1 hour (same as No)" & vbCrLf & vbCrLf & _
    "15 minutes a day = developer in 6 months. You got this!"

sAnswer = MsgBox(sMsg, vbYesNoCancel + vbExclamation + vbDefaultButton1, "Daily Coding Task")

If sAnswer = vbYes Then
    ' Find the current task: newest .c directly in the main folder
    ' (ignore _queue, _done, exe - they are subfolders, not files)
    sTaskFile = ""
    Set objFolder = fso.GetFolder(sTaskDir)
    For Each objFile In objFolder.Files
        If LCase(fso.GetExtensionName(objFile.Name)) = "c" Then
            If sTaskFile = "" Then
                sTaskFile = objFile.Name
            ElseIf objFile.DateLastModified > fso.GetFile(sTaskDir & "\" & sTaskFile).DateLastModified Then
                sTaskFile = objFile.Name
            End If
        End If
    Next

    ' Open the task file like a double-click (default app = VS Code)
    If sTaskFile <> "" Then
        objShell.Run Chr(34) & sTaskDir & "\" & sTaskFile & Chr(34), 1, False
    Else
        ' No task file found - open VS Code on the folder instead
        objShell.Run Chr(34) & sCodeExe & Chr(34) & " " & Chr(34) & sTaskDir & Chr(34), 1, False
    End If
ElseIf sAnswer = vbNo Or sAnswer = vbCancel Then
    ' Schedule compulsory reminder once at 12:00 PM.
    sCmd = "schtasks /create /tn " & Chr(34) & "Daily Code Compulsory" & Chr(34) & _
           " /tr " & Chr(34) & Chr(34) & "wscript.exe" & Chr(34) & " " & Chr(34) & _
           sScriptDir & "\remind-compulsory.vbs" & Chr(34) & Chr(34) & _
           " /sc once /st 12:00 /f"
    objShell.Run sCmd, 0, True
End If

Set fso = Nothing
Set objShell = Nothing
