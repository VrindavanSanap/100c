
add_library(utils_lib
        src/utils.c
)

target_include_directories(utils_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)