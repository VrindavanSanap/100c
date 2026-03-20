#include "set_interface.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dynamic_array.h"
struct set {
  dynamic_array *elements;
  int (*compare)(const void *a, const void *b);
};

set *set_build(size_t element_size,
               int (*compare)(const void *a, const void *b)) {
  if (element_size == 0) {
    fprintf(stderr, "Error : element_size cannot be 0\n");
    return NULL;
  }
  if (!compare) {
    fprintf(stderr, "Error: compare function cannot be NULL\n");
    return NULL;
  }
  set *s = malloc(sizeof(*s));
  if (!s) {
    fprintf(stderr, "Error: Set allocation failed\n");
    return NULL;
  }
  dynamic_array *elements = da_build(element_size);
  if (!elements) {
    fprintf(stderr, "Error: Set elements array allocation failed\n");
    free(s);  // Prevent memory leak!
    return NULL;
  }

  *s = (set){.elements = elements, .compare = compare};

  return s;
}
void set_insert(set *s, const void *element) {
  if (!s || !element) return;
  // insert only if the set does not already have the element
  if (set_find(s, element)) {
    return;
  }
  da_insert_last(s->elements, element);
}
bool set_find(set *s, const void *element) {
  // returns true if the element exists in the set
  size_t element_size = get_element_size(s->elements);
  size_t num_elements = da_get_size(s->elements);
  for (size_t i = 0; i < num_elements; i++) {
    char temp_buffer[element_size];
    da_get_at(s->elements, i, temp_buffer);
    if (s->compare(temp_buffer, element) == 0) {
      return true;
    }
  }
  return false;
}
void set_delete(set *s, const void *element) {
  if (!s || !element) return;
  size_t element_size = get_element_size(s->elements);
  for (size_t i = 0; i < da_get_size(s->elements); i++) {
    char temp_buffer[element_size];
    da_get_at(s->elements, i, temp_buffer);
    if (s->compare(temp_buffer, element) == 0) {
      da_delete_at(s->elements, i);
      return;
    }
  }
}
size_t set_get_size(set *s) { return da_get_size(s->elements); }
void set_free(set *s) {
  if (!s) {
    return;
  }
  da_free(s->elements);

  free(s);
}