//
//  boilerplate.c 
//  bp 
//
//  Created by Vrindavan sanap on 7/13/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//


//  Code will be used as boiler plate  

#include <stdio.h>
void print_int_arr(int arr[], int len){
    
  printf("[");
  for (int i = 0; i < len; i++){
    printf("%d, ", arr[i]);
  }
  printf("] \n");
}

void print_float_arr(float arr[], int len){

  printf("[");
  for (int i = 0; i < len - 1; i++){
    printf("%.2f, ", arr[i]);
  }
  printf("%.2f] \n", arr[len- 1]);
}

