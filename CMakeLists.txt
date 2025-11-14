cmake_minimum_required(VERSION 3.12)
#[=[
    We have multiple projects in this single folder
    To keep things clean we will be using "out of source" build
    We will also have utils (utilities) ie common functions that will
    be used by many of the other projects

    Structure of the project will look something like this
    my_workspace/
    ├── CMakeLists.txt        <-- 1. ROOT: Defines project, adds subdirectories
    │
    ├── utils/                <-- SOURCE: Your 'utils_lib' library
    │   ├── CMakeLists.txt    <-- 3. Defines 'utils_lib' target
    │   ├── include/
    │   │   └── utils/
    │   │       └── utils.h
    │   └── src/
    │       └── utils.cpp
    │
    ├── projectA/             <-- SOURCE: Your 'projectA' executable
    │   ├── CMakeLists.txt    <-- 4. Defines 'projectA' target, links to 'utils_lib'
    │   └── mainA.cpp
    │
    ├── projectB/             <-- SOURCE: Your 'projectB' executable
    │   ├── CMakeLists.txt    <-- 5. Defines 'projectB' target, links to 'utils_lib'
    │   └── mainB.cpp
    │
    └── build/                <-- 2. BUILD: All generated files go here
        ├── CMakeCache.txt
        ├── ... (other cmake/make files) ...
        │
        ├── utils/            <-- Build folder for 'utils_lib'
        │   ├── ... (build files) ...
        │   └── libutils_lib.a  <-- (or .so / .dll) The compiled library
        │
        ├── projectA/         <-- Build folder for 'projectA'
        │   ├── ... (build files) ...
        │   └── projectA      <-- The compiled 'projectA' executable
        │
        └── projectB/         <-- Build folder for 'projectB'
            ├── ... (build files) ...
            └── projectB      <-- The compiled 'projectB' executable
]=]#
cmake_minimum_required(VERSION 3.15)
project(100c VERSION 1.0 LANGUAGES C)

add_subdirectory(utils)
add_subdirectory(advanced_c)
add_subdirectory(bigram-model)
