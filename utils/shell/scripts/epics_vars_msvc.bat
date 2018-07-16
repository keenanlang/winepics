:: Init Script for msvc
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

:: Runs the vsvars32 for the newest version of Visual Studio
@FOR /F "tokens=*" %%i IN ('%CMDER_ROOT%\..\perl\perl\bin\perl %CMDER_ROOT%\scripts\version.pl') DO @CALL "%%i\vcvarsall.bat" x86

:: You can choose a different version by uncommenting the correct version
:: @CALL "%VS90COMNTOOLS%..\..\VC\vcvarsall.bat" x86	&:: VS2008
:: @CALL "%VS100COMNTOOLS%..\..\VC\vcvarsall.bat" x86	&:: VS2010
:: @CALL "%VS110COMNTOOLS%..\..\VC\vcvarsall.bat" x86	&:: VS2013
:: @CALL "%VS120COMNTOOLS%..\..\VC\vcvarsall.bat" x86   &:: VS2014

@SET EPICS_HOST_ARCH=win32-x86

@ECHO OFF
@CALL %CMDER_ROOT%\..\..\profile.bat
