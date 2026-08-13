' ============================================================
' Daily Code Compulsory - 12:00 PM follow-up popup
' You snoozed at 11:00. No more excuses - open the task NOW.
' Opens the current task file directly (like a double-click).
' ============================================================
Option Explicit

Dim objShell, fso, sScriptDir, sTaskDir, sCodeExe
Dim objFolder, objFile, sTaskFile
Dim sState, sStreak, sLine2, oIn, sMsg2

Set objShell = CreateObject("WScript.Shell")
Set fso = CreateObject("Scripting.FileSystemObject")

sScriptDir = fso.GetParentFolderName(WScript.ScriptFullName)
sTaskDir = fso.GetParentFolderName(sScriptDir)
sCodeExe = "C:\Users\SERVER\AppData\Local\Programs\Microsoft VS Code\Code.exe"

' --- read the streak so the nudge can mention it ---
sState = sScriptDir & "\_state.txt"
sStreak = ""
If fso.FileExists(sState) Then
    Set oIn = fso.OpenTextFile(sState, 1)
    Do Until oIn.AtEndOfStream
        sLine2 = oIn.ReadLine
        If Left(sLine2, 7) = "streak=" Then sStreak = Mid(sLine2, 8)
    Loop
    oIn.Close
End If

sMsg2 = "NO MORE EXCUSES!" & vbCrLf & vbCrLf & _
    "You snoozed at 11:00 - now it is COMPULSORY." & vbCrLf & vbCrLf & _
    "Your task file is opening in VS Code now." & vbCrLf & _
    "Write SOME code. Even 5 minutes counts."
If sStreak <> "" Then
    If CLng(sStreak) >= 2 Then
        sMsg2 = sMsg2 & vbCrLf & vbCrLf & "You're on a " & sStreak & "-day streak - don't break it now!"
    End If
End If
MsgBox sMsg2, vbOKOnly + vbExclamation, "Daily Coding Task - COMPULSORY"

' Find the current task: newest .c directly in the main folder
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

Set fso = Nothing
Set objShell = Nothing
