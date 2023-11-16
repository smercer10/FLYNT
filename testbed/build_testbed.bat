:: Windows build script for testbed executable
@ECHO OFF
SETLOCAL EnableDelayedExpansion

:: Create bin directory if it doesn't exist
IF NOT EXIST ../bin/ (
    MKDIR ../bin/
)

:: Get list of source files
SET source_files=
FOR /R %%f IN (*.c) DO (
    SET source_files=!source_files! %%f
)

:: Set build options
SET target_name=testbed
SET compiler_flags=-g3
SET include_flags=-Isrc/ -I../engine/src/
SET linker_flags= -lengine.lib -L../bin/
SET defines=-D_DEBUG -DF_IMPORT

:: Run build
ECHO "Building %target_name%..."
clang %source_files% %compiler_flags% -o ../bin/%target_name%.exe %include_flags% %linker_flags% %defines%
