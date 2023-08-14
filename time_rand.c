//
//  time_rand.c 
//  100c 
//
//  Created by Vrindavan on 3/08/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//


//  Program that uses current time as seed for random numbers





#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main() {
  time_t now;

  now = time(NULL);
  printf("Current timestamp: %ld \n",now);
  srand(now);
  printf("Rand num: %d\n", rand());
  return 0;
}

