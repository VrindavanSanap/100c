//
//  ms_rand.c
//  100c
//
//  Created by Vrindavan sanap on 7/13/23.
//

//  Microsofts implementation of random

#include <stdio.h>
int seed = 1;
int rand() { return ((seed = seed * 214013 + 2531011) >> 16) & 32767; }
int main(int argc, char *argv[]) {
  for (int i = 0; i < 10; i++) {
    int r = rand();
    printf("%d \n", r);
  }
  return 0;
}
