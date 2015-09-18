:: Init Script for cmd.exe
:: Sets some nice defaults
:: Created as part of cmder project

:: Find root dir
@if not defined CMDER_ROOT (
    for /f %%i in ("%ConEmuDir%\..\..") do @set CMDER_ROOT=%%~fi
)

:: Change the prompt style
@prompt $E[1;32;40m%username%@%userdomain%:$E[1;36;40m$P$E[1;37;40m$$$S$E[0m

:: Pick right version of clink
@if "%PROCESSOR_ARCHITECTURE%"=="x86" (
    set architecture=86
) else (
    set architecture=64
)

:: Run clink
@"%CMDER_ROOT%\vendor\clink\clink_x%architecture%.exe" inject --quiet --profile "%CMDER_ROOT%\config"

:: I do not even know, copypasted from their .bat
@set PLINK_PROTOCOL=ssh
@if not defined TERM set TERM=xterm


:: Add aliases
@doskey /macrofile="%CMDER_ROOT%\..\..\aliases"

:: Set home path
@if not defined HOME set HOME=%USERPROFILE%

@if defined CMDER_START (
    @cd /d "%CMDER_START%"
) else (
    @if "%CD%\" == "%CMDER_ROOT%" (
        @cd /d "%HOME%"
    )
)

@SET PATH=%PATH%;%CMDER_ROOT%\bin

:: MinGW specific
@SET PATH=%PATH%;%CMDER_ROOT%\..\minGW\bin
@SET CPATH=%CMDER_ROOT%\..\minGW\include
@SET LD_LIBRARY_PATH=%CMDER_ROOT%\..\minGW\lib

@SET EPICS_HOST_ARCH=win32-x86-mingw

@ECHO OFF
@CALL %CMDER_ROOT%\..\..\profile.bat