//
//  sum_arr.c
//  100c
//
//  Created by Vrindavan sanap on 7/13/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//

//  Functions which return sum of all elements of a given array

#include <stdio.h>

float sum_float_l1(float arr[], int size) {
  float s = 0;
  for (int i = 0; i < size; i++) {
    s += arr[i];
  }
  return s;
}

int sum_int_l1(int arr[], int size) {
  int s = 0;
  for (int i = 0; i < size; i++) {
    s += arr[i];
  }
  return s;
}

float sum_float_l2(float arr[], int size) {
  float s = 0;
  for (int i = 0; i < size; i++) {
    s += arr[i] * arr[i];
  }
  return s;
}
