#include <math.h>
#include <stdio.h>

float fcube_root(float x) {
    float guess = 1.0f;
    while (fabs(x - guess * guess * guess) > 0.001f) {
        guess = ((x / (guess * guess)) + 2 * guess) / 3;
        printf("%f\n", guess);
    }
    return guess;
}

int main() {
    fcube_root(27);

    return 0;
}
