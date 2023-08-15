//
//  rms_norm.c 
//  100c 
//
//  Created by Vrindavan sanap on 7/13/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//


//  Function to calculate rms norm of a array 

#include <stdio.h>

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
int main(int argc, char *argv[]) {
  float o[5]; 
  float x[5] = {1.5, 2.7, 3.2, 4.0, 5.9}; 

  rmsnorm(o, x, )

  return 0;
}





