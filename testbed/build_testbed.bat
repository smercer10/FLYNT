:: Build script for testbed executable
@ECHO OFF
SETLOCAL EnableDelayedExpansion

:: Get list of source files
SET source_files=
FOR /R %%f IN (*.c) DO (
    SET source_files=!source_files! %%f
)

:: Define build arguments
SET target_name=testbed
SET compiler_flags=-g3
SET include_flags=-Isrc -I../engine/src/
SET linker_flags=-L../bin/ -lengine.lib
SET defines=-D_DEBUG -DF_IMPORT

:: Run build
ECHO "Building %target_name%..."
clang %source_files% %compiler_flags% -o ../bin/%target_name%.exe %include_flags% %linker_flags% %defines%
