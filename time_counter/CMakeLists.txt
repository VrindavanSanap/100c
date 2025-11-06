# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Define the project name
project(time_counter C)

# Add an executable target named 'MyApp' 
# from the source file main.c
add_executable(time_counter main.c)