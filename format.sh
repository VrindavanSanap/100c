find . -type f -name "*.cpp" -o -name "*.h" -name "*.c" -exec clang-format -i {} \;

