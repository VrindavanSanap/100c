//
//  dynamic_array.c
//  dynamic_array
//
//  Created by Vrindavan Sanap on 10/11/25.
//
#include "dynamic_array.h"

#include <stdio.h>
#include <stdlib.h>
// dont declare this in the header file, beacuse the user of
// dynamic array api does not need to know the internal of the
// dynamic array
struct dynamic_array {
  void *data;           // pointer to the first element
  size_t size;          // number of elements currently stored
  size_t capacity;      // total number of elements that fit before resizing
  size_t element_size;  // size of each element in bytes
};

/*
unlike dynamic arrays in python3 (lists) which merely store pointers to
the objects in the array contigously letting the objects themselves be
non-contigious, which allows the objects to be non-homoginious
this though comes at a performance hit as they have poor spatical
cache locality but gives the advantage of veritaility

*/
dynamic_array *da_build(size_t element_size) {
  dynamic_array *da = malloc(sizeof(dynamic_array));
  *da = (dynamic_array){
      .data = NULL,
      .size = 0,
      .capacity = 0,
      .element_size = element_size,
  };
  return da;
}
