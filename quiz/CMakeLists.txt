
list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")
find_package(cJSON REQUIRED)
add_executable(quiz quiz.c)
target_link_libraries(quiz PUBLIC cjson)
add_custom_command(
        TARGET quiz POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/test.json
        $<TARGET_FILE_DIR:quiz>/test.json
        COMMENT "Copying test.json to build directory"
)

