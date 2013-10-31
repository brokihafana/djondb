@echo off
setlocal enabledelayedexpansion

if [%1] ==[] goto usage

call ..\setenv.bat
call :parseArguments %*

REM call :checkrequired prepareDir.sh found
call :checkrequired python.exe pythonpath

set PATH="%PATH%;%python%;%svnpath%"

if "%pythonpath%" == "" (
   echo python version 2.7 is not in your PATH, if it's installed please add the path using the parameter -python [PYTHON PATH]
   GOTO Exit
)
call :checkrequired svn.exe svnexepath
if "%svnpath%" == "" (
   echo svn.exe is not in your PATH, if it's installed please add the path using the parameter -svnpath [SUBVERSION PATH]
   echo You can get the command line tool from: http://www.sliksvn.com/en/download
   GOTO Exit
)

if "%x32%" == "true" (
	echo starting win32
	SET PLATFORM=Win32
)

if "%x64%" == "true" (
	echo starting x64
	SET PLATFORM=x64
)

call :checkrequired unzip.exe unzippath

@rem %unzippath% -o patch-2.5.9-7-bin.zip -d patch

TarTool v8.tar.gz
cd v8

if NOT EXIST third_party\cygwin (
	echo Getting cygwin from chromium
	"%svnexepath%" co http://src.chromium.org/svn/trunk/deps/third_party/cygwin@66844 third_party\cygwin
)

@rem ..\patch\bin\patch --binary -R -p1 build\common.gypi ..\v8_mt.patch

set msversion=2010

if "%VS%" == "VS2008" (
   set msversion=2008
)

if "%x64%" == "true" (
echo Executing python
	@rem "%pythonpath%" build\gyp_v8 -Dtarget_arch=x64 -Dcomponent=static_library -G msvs_version=2010
	"%pythonpath%" build\gyp_v8 -Dtarget_arch=x64 -Dcomponent=shared_library -G msvs_version=%msversion%
	@rem "%pythonpath%" build\gyp_v8 -Dtarget_arch=x64 -G msvs_version=2010
)
if "%x32%" == "true" (
echo Executing python
	@rem "%pythonpath%" build\gyp_v8 -Dtarget_arch=ia32 -Dcomponent=static_library -G msvs_version=2010
	"%pythonpath%" build\gyp_v8 -Dtarget_arch=ia32 -Dcomponent=shared_library -G msvs_version=%msversion%
	@rem "%pythonpath%" build\gyp_v8 -Dtarget_arch=ia32 -G msvs_version=2010
)

%PATH_MSBUILD%\msbuild build\all.sln /p:Configuration=Release /p:Platform=%PLATFORM%

copy /Y build\Release\v8.dll ..\libs\v8.dll

call :findfile build\Release\lib v8.lib file
copy /Y %file% ..\libs\v8.lib

call :findfile build\Release\lib v8_base*.lib file
copy /Y %file% ..\libs\v8_base.lib

call :findfile build\Release\lib v8_nosnapshot*.lib file
copy /y %file% ..\libs\v8_nosnapshot.lib

call :findfile build\Release\lib v8_snapshot*.lib file
copy /y %file% ..\libs\v8_snapshot.lib

copy /y include\*.h ..\includes\

GOTO END

:usage

Echo Usage: %0 [-x32] [-x64] [-python PYTHON_DIR] [-svnpath SVN_PATH]
goto exit

:END

Echo Done!

goto Exit

:getArg
set valname=%~1
echo arg: !%valname%!
goto:eof

:parseArguments
rem ----------------------------------------------------------------------------------
@echo off

:loop
IF "%~1"=="" GOTO cont

set argname=%~1
set argname=%argname:~1,100%
set value=%~2

@rem if the next value starts with - then it's a new parameter
if "%value:~0,1%" == "-" (
   set !argname!=true
   SHIFT & GOTO loop
)

if "%value%" == "" (
   set !argname!=true
   SHIFT & GOTO loop
)

set !argname!=%~2

@rem jumps first and second parameter
SHIFT & SHIFT & GOTO loop

:cont

goto:eof

:findfile
@rem this will look for a file. call :findfile DIR file result

for /R %~1 %%f in (%~2) do (
	set "%~3=%%f"
)

goto:eof

:checkrequired 
set pathfound=

set list=%PATH%
set list=%list:"=%

:nextreq
FOR /f "tokens=1* delims=;" %%a IN ("%list%") DO (
  if exist %%a\%~1 (
     set pathfound=%%a\%~1
  )
  if not "%pathfound%" == "" (
    goto exitloopreq
  )
  set list=%%b
  goto nextreq
)
:exitloopreq
set "%~2=%pathfound%"

goto:eof

rem ----------------------------------------------------------------------------------

:Exit
