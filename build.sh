#!/bin/bash

# Variables
BUILD_DIR="build"
BUILD_TYPE="Release"  # Change to "Debug" if you want debug builds
RUN_EXECUTABLE=""     # Optional: Set the executable name if you want to run it after building
SRC_DIR="src"

# Functions
function print_usage() {
  echo "Usage: ./build.sh [-d|--debug] [-r|--run <executable_name>]"
  echo "  -d, --debug       Build in Debug mode (default is Release)"
  echo "  -r, --run         Run the specified executable after building"
  exit 1
}

# Parse command-line arguments
while [[ "$#" -gt 0 ]]; do
  case $1 in
    -d|--debug) BUILD_TYPE="Debug" ;;
    -r|--run) shift; RUN_EXECUTABLE="$1" ;;
    *) print_usage ;;
  esac
  shift
done

# Create build directory
if [ ! -d "$BUILD_DIR" ]; then
  mkdir "$BUILD_DIR"
fi

# Navigate to the build directory
cd "$BUILD_DIR" || exit

# Run CMake and build the project
echo "Configuring the project with CMake (Build type: $BUILD_TYPE)..."
cmake .. -DCMAKE_BUILD_TYPE="$BUILD_TYPE"
if [ $? -ne 0 ]; then
  echo "CMake configuration failed."
  exit 1
fi

echo "Building the project..."
cmake --build .
if [ $? -ne 0 ]; then
  echo "Build failed."
  exit 1
fi

cd "$SRC_DIR" 
./Crypto
cd ..

echo "Build and execution completed successfully!"
