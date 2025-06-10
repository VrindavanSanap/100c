cmake_minimum_required(VERSION 3.13)  # CMake version check
project(extern_example)               # Create project "simple_example"

# Add main.cpp file of the project root directory as a source file
set(SOURCE_FILES src/main.c src/a.c)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(extern_example ${SOURCE_FILES})
