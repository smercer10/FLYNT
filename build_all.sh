#!/bin/bash
# Linux build script for all targets
set echo on

echo "Building all targets..."

# Build engine library
pushd engine
source build_engine.sh
popd

ERRORLEVEL=$?
if [ $ERRORLEVEL -ne 0 ]; then
    echo "Failed to build engine"
    exit 1
fi

# Build testbed executable
pushd testbed
source build_testbed.sh
popd

ERRORLEVEL=$?
if [ $ERRORLEVEL -ne 0 ]; then
    echo "Failed to build testbed"
    exit 1
fi

echo "All targets built successfully"
