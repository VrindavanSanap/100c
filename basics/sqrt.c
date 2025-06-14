#include <math.h>
#include <stdio.h>

float my_sqrt(float x) {
    float guess = 1;
    while (fabs((guess * guess) - x) > 0.001f) {
        guess = .5 * (guess + (x / guess));
        printf("%f \n", guess);
    }
}

int main() {
    float n = 2;
    my_sqrt(n);
}
