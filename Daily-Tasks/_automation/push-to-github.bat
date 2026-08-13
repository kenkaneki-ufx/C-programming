@echo off
cd /d "C:\Users\SERVER\Desktop\VS Code\C" || exit /b 1
git add "Daily-Tasks" >> "%~dp0_git.log" 2>&1 || exit /b 1
git commit -m "Daily task: %~n1" >> "%~dp0_git.log" 2>&1 || exit /b 1
git push >> "%~dp0_git.log" 2>&1
