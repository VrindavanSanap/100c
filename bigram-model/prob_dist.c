//
//  prob_dist.c 
//  100c 
//
//  Created by Vrindavan sanap on 7/13/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//


//  Code will be used as boiler plate  

#include <stdio.h>

void prob_dist(float* x, int size){
  float sum = 0;
  for(int i = 0; i< size; i++){
    sum += x[i];
  } 
  printf(sum);
}
int main(int argc, char *argv[]) {
  
  prob_dist(x);
}


