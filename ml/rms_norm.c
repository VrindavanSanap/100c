//
//  rms_norm.c 
//  100c 
//
//  Created by Vrindavan sanap on 7/13/23.
//


//  Function to calculate rms norm of a array 

#include <stdio.h>
#include <math.h>
#include "print_arr.h"
#include "sum_arr.h"

void rmsnorm(float* o, float* x, float* weight, int size) {

    float ss = 0.0f;
    for (int j = 0; j < size; j++) {
        ss += x[j] * x[j];
    }
    ss /= size;
    ss += 1e-5f;
    ss = 1.0f / sqrtf(ss);
    for (int j = 0; j < size; j++) {
        o[j] = weight[j] * (ss * x[j]);
    }
}
int main(int argc, char *argv[]) {
  float o[5]; 
  float w[5] = {1, 1, 1, 1, 1 }; 
  float x[5] = {111, 2.7, 3.2, 4.0, 5.9}; 

  rmsnorm(o, x ,w, 5);
  printf("x = ");
  print_float_arr(x, 5);
  printf("w = ");
  print_float_arr(w, 5);
  printf("o = ");
  print_float_arr(o, 5);
  float s = sum_float_l2(o, 5);
  printf("sum of output = %.2f", s);

  return 0;
}





