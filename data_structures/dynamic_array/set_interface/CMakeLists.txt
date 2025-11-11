add_library(set_interface_lib
    set_interface.c
)

target_include_directories(set_interface_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(set_interface_lib
    PUBLIC
        dynamic_array_lib
)
