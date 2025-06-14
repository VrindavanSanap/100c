#include <math.h>
#include <stdio.h>

// https://math.mit.edu/~stevenj/18.335/newton-sqrt.pdf

float sqrt_taylor_series(float x) {
    x -= 1;
    return 1 + (x / 2) - ((x * x) / 8) + ((x * x * x) / 16);
}

float my_sqrt(float x) {
    // returns square root of x using newtons method
    float guess = sqrt_taylor_series(x);
    const float tolerance = 0.00001;

    while (fabs(guess * guess - x) >= tolerance) {
        guess = .5 * (guess + (x / guess));
        printf("%f\n", guess);
    }
    return guess;
}

int main() {
    float x = 4;
    float exp_ans = sqrt(x);
    printf("Expected square root of %f is %f \n", x, exp_ans);
    my_sqrt(x);
}
