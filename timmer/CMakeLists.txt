# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Define the project name and the language(s)
project(timmer C)

# Specify the executable target
# Usage: add_executable(<target_name> <source_files...>)
add_executable(timmer main.c)

# (Optional) Specify standard C flags or compile options
# For example, to enable C11 standard and strict warnings:
# target_compile_features(my_app PRIVATE c_std_11)
# target_compile_options(my_app PRIVATE -Wall -Wextra -pedantic)
