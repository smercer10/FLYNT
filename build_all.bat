:: Windows build script for all targets
@ECHO OFF

ECHO "Building all targets..."

:: Build engine library
PUSHD engine
CALL build_engine.bat
POPD

IF %ERRORLEVEL% NEQ 0 (
    ECHO "Failed to build engine"
    EXIT /B 1
)

:: Build testbed executable
PUSHD testbed
CALL build_testbed.bat
POPD

IF %ERRORLEVEL% NEQ 0 (
    ECHO "Failed to build testbed"
    EXIT /B 1
)

ECHO "All targets built successfully"
