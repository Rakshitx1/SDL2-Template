#!/bin/bash

# Get the directory where this script is located
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

# Save the current directory
CURRENT_DIR=$(pwd)

# Navigate to the script directory
cd "$SCRIPT_DIR"

# Determine build type based on input argument
if [[ "${1,,}" == "release" || "${1,,}" == "r" ]]; then
    BUILD_TYPE="Release"
    echo "Building in Release mode..."
else
    BUILD_TYPE="Debug"
    echo "Building in Debug mode..."
fi

# Remove existing build directory if it exists
if [ -d "build" ]; then
    rm -rf build
fi

# Create a new build directory
mkdir -p build

# Navigate to the build directory
cd build

# Generate Makefiles and build the project with the specified build type
cmake -DCMAKE_BUILD_TYPE="$BUILD_TYPE" ..

# Build the project
make

# Run the executable
if [ "$BUILD_TYPE" == "Release" ]; then
    ./Release/SDL2Template
else
    ./Debug/SDL2Template
fi

# Return to the initial directory
cd "$CURRENT_DIR"
