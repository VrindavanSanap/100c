# Dynamic Array

A [dynamic array](https://grokipedia.com/page/Dynamic_array) is a data structure that specifies *how* operations are performed.

• Our goal: Hide memory management details
behind an Application Program Interface (API)
• Each element is accessible in O(1)
• Dynamic array can change capacity

## Implementations

- [CPython listobject.c](https://github.com/python/cpython/blob/main/Objects/listobject.c)
- [OpenJDK ArrayList.java](https://github.com/openjdk/jdk/blob/master/src/java.base/share/classes/java/util/ArrayList.java)

## How to Run

1. Create a build directory:
   ```bash
   mkdir build
   ```
2. Navigate to the build directory:
   ```bash
   cd build
   ```
3. Run CMake and build the project:
   ```bash
   cmake ..
   make
   ```
4. Run the executable:
   ```bash
   ./dynamic_array
   ```
