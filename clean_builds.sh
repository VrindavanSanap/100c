#!/bin/bash

echo "Starting cleanup of build directories..."

# Find and delete IDE build directories (VSCode, CLion, etc.)
echo "Removing build directories..."
find . -depth -type d \( -name "build" -o -name "build-*" -o -name "cmake-build-*" \) -print -exec rm -rf {} \;

echo "Build directory cleanup complete."
