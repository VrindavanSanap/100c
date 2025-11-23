add_executable(collatz collatz.c)
add_executable(collatz_recursive collatz_recursive.c)
add_executable(goldbach goldbach.c primes.c)
add_executable(inv_sqrt inv_sqrt.c)
add_executable(newtons_method newtons_method.c)


list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")
find_package(cJSON REQUIRED)
find_package(CURL REQUIRED)
add_executable(cheat_pi100 cheat_pi100.c)
target_link_libraries(cheat_pi100 PUBLIC cjson curl)