//
//  prob_dist.c
//  100c
//
//  Created by Vrindavan sanap on 7/13/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//

//  Code will be used as boiler plate

#include <bigram-model/print_arr.h>
#include <bigram-model/sum_arr.h>
#include <stdio.h>

void prob_dist(float *x, int size) {
  float sum = sum_float_l1(x, size);
  for (int i = 0; i < size; i++) {
    x[i] /= sum;
  }
}
