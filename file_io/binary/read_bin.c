#include <stdio.h>
#include <stdlib.h>

#define FILENAME "data.bin"
#define NUM_INTS 10

int main() {
    FILE *file;
    int numbers[NUM_INTS];
    size_t result;

    // Open the binary file for reading
    file = fopen(FILENAME, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    // Read 10 integers from the file
    result = fread(numbers, sizeof(int), NUM_INTS, file);
    if (result != NUM_INTS) {
        fprintf(stderr, "Error reading file\n");
        fclose(file);
        return 1;
    }

    // Close the file
    fclose(file);

    // Print the integers
    for (int i = 0; i < NUM_INTS; i++) {
        printf("Number %d: %d\n", i + 1, numbers[i]);
    }

    return 0;
}

