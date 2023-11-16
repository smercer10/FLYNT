:: Windows build script for engine library
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

:: Configure build options
SET target_name=engine
SET compiler_flags=-g3 -shared -Wall -Wextra -Werror -Wvarargs
SET include_flags=-Isrc -I%VULKAN_SDK%/Include
SET linker_flags=-luser32 -lvulkan-1 -L%VULKAN_SDK%/Lib
SET defines=-D_DEBUG -D_CRT_SECURE_NO_WARNINGS -DF_EXPORT

:: Run build
ECHO "Building %target_name%..."
clang %source_files% %compiler_flags% -o ../bin/%target_name%.dll %include_flags% %linker_flags% %defines%
