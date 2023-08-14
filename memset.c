#include <stdio.h>
#include <string.h>

int main() {
    int buffer[10];
    size_t num_elements = sizeof(buffer) / sizeof(buffer[0]);
    int value = 42;

    memset(buffer, value, num_elements * sizeof(buffer[0]));

    for (size_t i = 0; i < num_elements; i++) {
        printf("buffer[%zu] = %d\n", i, buffer[i]);
    }

    return 0;
}

