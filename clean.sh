#!/bin/bash

echo "Starting cleanup..."

# Find and delete all build directories
echo "Removing build directories..."
find . -type d -name "build" -print -exec rm -rf {} \;

# Find and delete common compiled file types
echo "Removing compiled files (.o, .a, .out)..."
find . -type f \( -name "*.o" -o -name "*.a" -o -name "*.out" \) -print -exec rm -f {} \;

# Find and delete all compiled executables
echo "Finding and removing executables..."
find . -type f \( -perm -u+x -o -perm -g+x -o -perm -o+x \) -not -path "./.git/*" -not -name "*.sh" -not -name "*.py" -exec sh -c '
    for file do
        if file "$file" | grep -qE "Mach-O|ELF"; then
            echo "Removing executable: $file"
            rm "$file"
        fi
    done
' sh {} \;

echo "Cleanup complete."
