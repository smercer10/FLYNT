#!/bin/bash
# Linux build script for engine library
set echo on

# Create bin directory if it doesn't exist
if [ ! -d "../bin/" ]; then
    mkdir ../bin/
fi

# Get list of source files
source_files=$(find . -type f -name "*.c")

# Configure build options
target_name="engine"
compiler_flags="-g3 -shared -fdeclspec -fPIC"
include_flags="-Isrc/ -I$VULKAN_SDK/include/"
linker_flags="-lvulkan -lxcb -lX11 -lX11-xcb -lxkbcommon -L$VULKAN_SDK/lib/ -L/usr/X11R6/lib/"
defines="-D_DEBUG -DF_EXPORT"

# Run build
echo "Building $target_name..."
clang $source_files $compiler_flags -o ../bin/lib$target_name.so $include_flags $linker_flags $defines
