@echo off

REM Specify the directory
set "directory=..\cpp\source"

REM Check if the directory exists
if not exist "%directory%" (
  echo Directory not found: %directory%
  exit /b 1
)

if "%~1"=="" (
  for %%I in ("%directory%\*") do (
    REM Check if the file is a regular file
    if exist "%%I" (
      set "file=%%~fI"
      set "file_no_extension=%%~nI"
      g++ -shared -o ..\cpp\!file_no_extension!.so -fPIC !file!
    )
  )
) else (
  set "file=%~1"
  set "file_no_extension=%~n1"
  g++ -shared -o ..\!file_no_extension!.so -fPIC %file%
)
