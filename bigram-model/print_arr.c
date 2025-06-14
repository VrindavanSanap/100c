//
//  print_arr.c
//  basics/print_arr
//
//  Created by Vrindavan sanap on 7/13/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//

//  Code used to print arrays in c language

#include <stdio.h>
void print_int_arr(int arr[], int len) {
  printf("[");
  for (int i = 0; i < len; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\b\b] \n");
}

void print_float_arr(float arr[], int len) {
  printf("[");
  for (int i = 0; i < len - 1; i++) {
    printf("%.2f, ", arr[i]);
  }
  printf("%.2f] \n", arr[len - 1]);
}

void print_str_arr(const char* arr[], int len) {
  printf("[");
  for (int i = 0; i < len; i++) {
    printf("%s, ", arr[i]);
  }
  printf("\b\b] \n");
}
