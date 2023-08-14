#include <stdio.h>
#include "argmax.h"
int main() {
    float float_arr[] = {1.2, 2.5, 3.7, 4.0, 5.8};
    //expected answer 5.8

    int n = sizeof(float_arr)/ sizeof(float);
    int max;
    max = argmax(float_arr, n);
    printf("%d", max);
    return 0;
}

