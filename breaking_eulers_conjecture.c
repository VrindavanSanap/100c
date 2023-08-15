//
//  breaking_eulers_conjecture.c 
//  100c 
//
//  Created by Vrindavan sanap on 7/13/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//


//  Code breaking the eulers conjecture ie x^4 + y^4 + z^4 = w^4 
//  have no non trivial solutions

#include <stdio.h>
#include <math.h>

unsigned long long max(int a, int b, int c) {
    unsigned long long  max = a; 
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}
long long power(long long base, long long exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}


int test_conjecture(long long x, long long y, long long z,long long  w){

  if (power(x, 5) + power(y, 5) + power(z, 5) == power(w, 5) ){

    return true;
  }
  return false;
}
   unsigned long long solx = :wq

    unsigned long long y; 
    unsigned long long z; 
    unsigned long long w; 
  
int main(int argc, char *argv[]) {
    unsigned long long x; 
    unsigned long long y; 
    unsigned long long z; 
    unsigned long long w; 
    for (x = 0; x < 10;x ++){
      for (y = 0; y < 10;y ++){
        for (z = 0; z < 10;z ++){
          for (w = max(x, y, z); w < 10;w ++){
          printf("%llu %llu %llu  = %llu \n",x, y, z, w );
          printf("%llu = %llu \n", pow(x, 5) + pow(y, 5) + pow(z, 5), pow(w, 5));
        }
      }
    }
    return 0;
  }
}









