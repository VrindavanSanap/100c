#!/bin/bash

c_file=$1

if [ -z "$c_file" ]; then
    echo "Usage: ./run.sh <file_name>"
    exit 1
fi

exec_name="${c_file%.c}"

echo "Compiling $c_file to $exec_name"

clang "$c_file" -o "$exec_name" -I/opt/homebrew/include/SDL2 -L/opt/homebrew/lib -lSDL2 -lSDL2_image

if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

echo "Running ./$exec_name"
./"$exec_name"

status=$?
echo "Exit code was $status"

