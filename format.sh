find . -type f \( -name '*.c' -o -name '*.cpp' -o -name '*.h' -o -name '*.hpp' \) \
          -not -path '*/build/*' \
          -not -path '*/cmake-build-*/*' \
          -exec clang-format -i -style=file {} +

