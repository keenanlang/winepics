:: Get this scripts location
set TEMP=%~dp0
set TEMP=%TEMP:~0,-1%

:: Get all the programs
set PATH=%PATH%;%TEMP%\utils\gnuwin32\bin
set PATH=%PATH%;%TEMP%\utils\perl\c\bin
set PATH=%PATH%;%TEMP%\utils\perl\perl\bin
set PATH=%PATH%;%TEMP%\utils\Xming

:: @START XLaunch -run %TEMP%\utils\Xming\config.xlaunch
