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
  size_t num_elements;  // number of elements currently stored
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
      .num_elements = 0,
      .capacity = 0,
      .element_size = element_size,
  };
  return da;
}

// internal function
void _da_resize(dynamic_array *da) {
  int growth_factor = 2;
  void *new_data;
  size_t new_size = da->num_elements;
  if (new_size == 0) {
    new_size = 1;
    new_data = calloc(new_size, da->element_size);
  } else {
    new_size *= growth_factor;
    new_data = realloc(da->data, new_size * da->element_size);
  }
  if (new_data == NULL) {
    fprintf(stderr, "Error : Dynamic array reallocation failed \n");
    return;
  } else {
    da->data = new_data;
    da->num_elements = new_size;
  }
}

void da_insert_at(dynamic_array *da, const void *element, size_t index) {
  // input validation
  if (!da || !element) {
    return;
  }
  // like python lists if index > size -> index = size
  if (index > da->num_elements) {
    index = da->num_elements;
  }
  if (da->num_elements == da->capacity) {
    _da_resize(da);
    if (!da->data) {
      fprintf(stderr, "Dynamic array data initialization failed\n");
      return;
    }
  }

  // step1
  // Move all da[index:capacity] -> da[index+1:capcity+1]
  char *base_pointer = (char *)da->data;
  char *desination_ptr = base_pointer + (index + 1) * (da->element_size);
  char *source_ptr = base_pointer + (index) * (da->element_size);
  size_t n_bytes = (da->num_elements - index) * (da->element_size);
  // memmove(desination,const source, n_bytes)
  memmove(desination_ptr, source_ptr, n_bytes);
  // step2
  // da[index] = element
  // memcpy(dest, source, n_bytes)
  memcpy(source_ptr, element, da->element_size);
  da->num_elements++;
}

void da_insert_first(dynamic_array *da, const void *element) {}
void da_insert_last(dynamic_array *da, const void *element) {}