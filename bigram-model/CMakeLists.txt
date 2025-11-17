add_library(bigram_model_lib
    src/dict.c
    src/itos.c
    src/line_count.c
    src/plot_N.c
    src/prob_dist.c
    src/random.c
    src/sample.c
    src/stoi.c
    src/sum_arr.c
)
target_include_directories(bigram_model_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
add_executable(bigram-model
    app/bigram.c
)
add_custom_command(
    TARGET bigram-model POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_SOURCE_DIR}/names.txt
    $<TARGET_FILE_DIR:bigram-model>/names.txt
    COMMENT "Copying names.txt to build directory"
)

target_link_libraries(bigram-model
    PRIVATE
        bigram_model_lib
        # utils_lib
)
