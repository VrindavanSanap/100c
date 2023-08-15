//
//  arg_max.c 
//  100c 
//
//  Created by Vrindavan sanap on 7/13/23.
//


// Code defines a function argmax that returns the index of max value in a float array

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"

int argmax(float* v, int n) {
    
    int max_i = 0;
    float max_p = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > max_p) {
            max_i = i;
            max_p = v[i];
        }
    }
    return max_i;
}


int main() {

    srand(time(NULL));
    int size = 20;
    float floats[size];
    for (int i = 0; i < size; i++) {
        floats[i] = random_f32();
        printf("Element %d = %f \n", i, floats[i]);
    }
    int max_i = argmax(floats, size);
    printf("max_i = %d", max_i);
    return 0;
}

