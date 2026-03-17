cmake_minimum_required(VERSION 3.21) # Required for official C23 support
project(100c VERSION 1.0 LANGUAGES C)

# C23 Configuration
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF) # Keeps code portable/standard
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Centralize Output (keeps your build folder clean)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Robust Warning Configuration
if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
    add_compile_options(
        -Wall 
        -Wextra 
        -Wpedantic 
        -Wshadow               # Catch variable shadowing
        -Wstrict-prototypes    # Ensure explicit function signatures
        -Wunused-value         # Catch that comma operator issue!
    )
endif()

# Subdirectories
add_subdirectory(utils)
add_subdirectory(advanced_c)
add_subdirectory(bigram_model)
add_subdirectory(img_vis)
add_subdirectory(math)
add_subdirectory(ml)
add_subdirectory(quiz)