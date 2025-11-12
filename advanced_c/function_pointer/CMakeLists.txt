add_executable(bsort bsort.c)
add_executable(qsort qsort.c)
add_executable(predicate predicate.c)

target_link_libraries(bsort utils_lib)
target_link_libraries(qsort utils_lib)
target_link_libraries(predicate utils_lib)
