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

unsigned int random_u32() {
    unsigned long long rng_seed = rand() ;  
    rng_seed ^= rng_seed >> 12;
    rng_seed ^= rng_seed << 25;
    rng_seed ^= rng_seed >> 27;
    return (rng_seed * 0x2545F4914F6CDD1Dull) >> 32;
}

float random_f32() { 
    return (random_u32() >> 8) / 16777216.0f;
}

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

