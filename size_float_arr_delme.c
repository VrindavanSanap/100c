#include <stdio.h>

int main() {
    float floatArray[] = {1.2, 2.5, 3.7, 4.0, 5.8};

    int numberOfElements = sizeof(floatArray) / sizeof(float);
    int totalSizeInBytes = sizeof(floatArray);

    printf("Number of elements in the float array: %d\n", numberOfElements);
    printf("Total size of the float array (in bytes): %d\n", totalSizeInBytes);

    return 0;
}

