#include <stdio.h>
#include <math.h> // Include the math library for the expf function
#include <stdlib.h>
// Define rand_float() function here or include the appropriate header if it's from a library
float rand_float() {
    return (float)rand();
}
void softmax(float* x, int size) {
    float max_val = x[0];
    for (int i = 1; i < size; i++) {
        if (x[i] > max_val) {
            max_val = x[i];
        }
    }

    float sum = 0.0f;
    for (int i = 0; i < size; i++) {
        x[i] = expf(x[i] - max_val);
        sum += x[i];
    }

    for (int i = 0; i < size; i++) {
        x[i] /= sum;
    }
}

int main() {
    int size = 5;
    float floats [] = {1.0, 2.0,3,4,5};

    // Initialize floats array with random values
    printf("softmax.c \n");
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%f,", floats[i]);
    }
    printf("] \n");

    // Apply softmax to the initialized floats array
    softmax(floats, size);
    // Print the softmax-transformed values
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%f,", floats[i]);
    }
    printf("] \n");

    return 0;
}

