//
//  dynamic_array.c
//  dynamic_array
//
//  Created by Vrindavan Sanap on 10/11/25.
//
#include "dynamic_array.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Don't declare this in the header file, because the user of the
// dynamic array API does not need to know the internals of the
// dynamic array.
struct dynamic_array {
  void *data;           // pointer to the first element
  size_t num_elements;  // number of elements currently stored
  size_t capacity;      // total number of elements that fit before resizing
  size_t element_size;  // size of each element in bytes
};

/*
Unlike dynamic arrays in Python 3 (lists), which merely store pointers to
the objects in the array contiguously, letting the objects themselves be
non-contiguous, this implementation stores objects themselves contiguously.
The Python approach allows for heterogeneous objects, but this comes at a
performance cost as they have poor spatial cache locality. This
implementation, however, has better spatial cache locality but requires
homogeneous objects.
*/
dynamic_array *da_build(size_t element_size) {
  if (element_size == 0) {
    fprintf(stderr, "Error : element_size cannot be 0\n");
    return NULL;
  }

  dynamic_array *da = malloc(sizeof(dynamic_array));
  if (!da) {
    fprintf(stderr, "Error : Dynamic array allocation failed\n");
    return NULL;
  }
  *da = (dynamic_array){
      .data = NULL,
      .num_elements = 0,
      .capacity = 0,
      .element_size = element_size,
  };
  return da;
}

// Internal function.
// return 0 if success
// return -1 if fail
int _da_resize(dynamic_array *da) {
  // TODO:
  // Implement two separate functions:
  // grow and shrink,
  // and use them according to need.

  int growth_factor = 2;
  void *new_data;
  size_t new_size = da->capacity;
  if (new_size == 0) {
    new_size = 1;
    new_data = calloc(new_size, da->element_size);
  } else {
    new_size *= growth_factor;
    new_data = realloc(da->data, new_size * da->element_size);
  }
  if (new_data == NULL) {
    fprintf(stderr, "Error : Dynamic array reallocation failed \n");
    return -1;
  } else {
    da->data = new_data;
    da->capacity = new_size;
  }
  return 0;
}

int da_get_at(const dynamic_array *da, size_t index, void *out_element) {
  // Returns 0 on success.
  // Returns -1 on failure.

  // Takes O(1) time.
  if (!da || !out_element) {
    fprintf(stderr, "Invalid parameters passed\n");
    return -1;
  }
  if (index >= da->num_elements) {
    fprintf(stderr, "IndexError: list index out of range\n");
    return -1;
  }

  char *base_ptr = (char *)da->data;
  char *source_ptr = base_ptr + index * da->element_size;
  memcpy(out_element, source_ptr, da->element_size);
  return 0;
}
int da_set_at(dynamic_array *da, const void *element, size_t index) {
  if (!da || !element) {
    fprintf(stderr, "Invalid parameters passed\n");
    return -1;
  }
  if (index >= da->num_elements) {
    fprintf(stderr, "IndexError: list index out of range\n");
    return -1;
  }

  char *base_ptr = (char *)da->data;
  char *destination_ptr = base_ptr + index * da->element_size;
  memcpy(destination_ptr, element, da->element_size);
  return 0;
}

int da_insert_at(dynamic_array *da, const void *element, size_t index) {
  // Input validation.
  if (!da || !element) {
    fprintf(stderr, "Invalid parameters passed\n");
    return -1;
  }
  // Index clamping.
  // Like Python lists, if index > size, then index = size.
  if (index > da->num_elements) {
    index = da->num_elements;
  }

  if (da->num_elements == da->capacity) {
    if (_da_resize(da) == -1) {
      return -1;
    }
  }

  // Step 1:
  // `da[index+1:capacity+1] = da[index:capacity]`
  char *base_ptr = (char *)da->data;
  char *destination_ptr = base_ptr + (index + 1) * (da->element_size);
  char *source_ptr = base_ptr + (index) * (da->element_size);

  size_t n_bytes = (da->num_elements - index) * (da->element_size);
  memmove(destination_ptr, source_ptr, n_bytes);

  // Step 2:
  // `da[index] = element`
  memcpy(source_ptr, element, da->element_size);
  // Step 3:
  // Update `num_elements`.
  da->num_elements++;
  return 0;
}
void da_delete_at(dynamic_array *da, size_t index) {
  // Input validation.
  if (!da || index >= da->num_elements) {
    fprintf(stderr, "Invalid parameters passed\n");
    return;
  }
  // Step 1:
  // Remove `da[index]`.

  // Step 2:
  // `da[index:capacity - 1] = da[index+1:capacity]`
  char *base_ptr = (char *)da->data;
  char *destination_ptr = base_ptr + (index) * (da->element_size);
  char *source_ptr = base_ptr + (index + 1) * (da->element_size);
  size_t n_bytes = (da->num_elements - index - 1) * (da->element_size);
  memmove(destination_ptr, source_ptr, n_bytes);

  // Step 3:
  // Update `num_elements`.
  da->num_elements--;
  // Optional step:
  // `_da_resize(da)`
}

int da_insert_first(dynamic_array *da, const void *element) {
  return da_insert_at(da, element, 0);
}
void da_delete_first(dynamic_array *da) { da_delete_at(da, 0); }

int da_insert_last(dynamic_array *da, const void *element) {
  // Takes O(1) amortized time.
  if (!da || !element) {
    fprintf(stderr, "Invalid parameters passed\n");
    return -1;
  }
  if (da->num_elements == da->capacity) {
    if (_da_resize(da) == -1) {
      return -1;
    }
  }

  char *base_ptr = (char *)da->data;
  char *destination_ptr = base_ptr + (da->num_elements) * (da->element_size);
  memcpy(destination_ptr, element, da->element_size);

  da->num_elements++;
  return 0;
}
void da_delete_last(dynamic_array *da) {
  // Takes O(1) amortized time.
  if (!da || da->num_elements == 0) {
    return;
  }
  da->num_elements--;
};

size_t da_get_size(dynamic_array *da) {
  if (!da) {
    fprintf(stderr, "Invalid parameters passed\n");
    return 0;
  }
  return da->num_elements;
}
void da_free(dynamic_array *da) {
  if (!da) {
    return;
  }
  free(da->data);
  free(da);
}