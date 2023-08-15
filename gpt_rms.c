#include <stdio.h>
#include <math.h>

void rmsnorm(float* o, float* x, float* weight, int size) {
    // calculate sum of squares
    float ss = 0.0f;
    for (int j = 0; j < size; j++) {
        ss += x[j] * x[j];
    }
    ss /= size;
    ss += 1e-5f;
    ss = 1.0f / sqrtf(ss);
    // normalize and scale
    for (int j = 0; j < size; j++) {
        o[j] = weight[j] * (ss * x[j]);
    }
}

int main() {
    // Define input, output, and weight arrays
    float input[] = {2.0, 2.0, 120.0};
    float output[3];
    float weights[] = {0.5, 0.7, 0.9};
    int size = sizeof(input) / sizeof(input[0]);

    // Apply rmsnorm function
    rmsnorm(output, input, weights, size);

    // Print the normalized and scaled values
    printf("Input: ");
    for (int i = 0; i < size; i++) {
        printf("%f ", input[i]);
    }
    printf("\nNormalized and Scaled Output: ");
    float f = 0;
    for (int i = 0; i < size; i++) {
        printf("%f ", output[i]*output[i]);
        f+=  output[i]*output[i];
    }
    
        printf("\n%f", f);
    return 0;
}

