//  square_array.c 
//  100c 
//
//  Created by Vrindavan Sanap on 31/7/23.
//  Copyright © 2023 Vrindavan Sanap. All rights reserved.


// Function to print and square a int array 



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void print_arr(int arr[], int len){
  
  printf("[");
  for (int i = 0; i < len; i++){
    printf("%d, ", arr[i]);
  }
  printf("] \n");
}

void square_arr(int arr[], int len){
  int square_arr[len];
  for (int i = 0; i < len; i++){
    square_arr[i] = pow(arr[i], 2); 
  }
  print_arr(square_arr, len);
}


int main(){
  srand(time(NULL));
  
  int len = 10;
  int arr[len];

  for (int i = 0; i < len; i++){
    arr[i] = rand() % 100;
  }
  print_arr(arr, len);
  square_arr(arr, len);
  return 0; 
}
