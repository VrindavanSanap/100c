//
//  arr_len.c 
//  100c 
//
//  Created by Vrindavan on 3/08/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//


//  Code to calculate length of an array

#include <stdio.h>

int main(){
  int arr[] = {1, 2, 3, 4, 5};
  int len = sizeof(arr)/ sizeof(arr[0]);
  printf("Length of array is %d", len);
  return 0;
}
