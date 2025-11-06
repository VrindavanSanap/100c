# Specifies the minimum required CMake version
cmake_minimum_required(VERSION 3.10) 
# Defines the project name and specifies C as the language
project(stopwatch C) 
# Creates an executable target named MyCProject from main.c

find_package(Curses REQUIRED)

add_executable(stopwatch main.c) 
target_link_libraries(stopwatch PRIVATE ${CURSES_LIBRARIES})
target_include_directories(stopwatch PRIVATE ${CURSES_INCLUDE_DIRS})


