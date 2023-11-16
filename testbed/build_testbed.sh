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
target_name="testbed"
compiler_flags="-g3 -fdeclspec -fPIC"
include_flags="-Isrc/ -I../engine/src/"
linker_flags="-L../bin/ -lengine -Wl,-rpath,."
defines="-D_DEBUG -DF_IMPORT"

# Run build
echo "Building $target_name..."
clang $source_files $compiler_flags -o ../bin/$target_name $include_flags $linker_flags $defines
