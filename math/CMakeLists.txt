
add_executable(collatz_recursive collatz_recursive.c)

add_executable(inv_sqrt inv_sqrt.c)
target_link_libraries(inv_sqrt PRIVATE m)

add_executable(newtons_method newtons_method.c)
target_link_libraries(newtons_method PRIVATE m)

add_executable(collatz collatz.c)

add_executable(goldbach goldbach.c primes.c)
target_include_directories(goldbach PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")
find_package(cJSON REQUIRED)
find_package(CURL REQUIRED)
add_executable(cheat_pi100 cheat_pi100.c)
target_link_libraries(cheat_pi100 PUBLIC cjson curl)