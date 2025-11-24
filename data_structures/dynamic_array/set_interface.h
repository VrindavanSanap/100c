/*
  Set interface implementation using dynamic-array datastruture
  Operations
    All these operatoins have time complexity of O(n)
    Container
      build(A) :build a set given iterable A
    Static
      find(k)
    Dynamic
      insert(k)
      delete(k)
    Order
      find_min()
      find_max()
      find_prev(k)
      find_next(k)
*/

#include <stdint.h>

#include "../dynamic_array.h"
#include "stdbool.h"

typedef struct set set;

// Container
set *set_build(dynamic_array *da);

// Static
bool set_find(set *s, void *key);

// Dynamic
void set_insert(set *s, void *key);
void set_insert_entry(set *s, void *key, uint64_t hash);
void set_delete(set *s, void *key);

// Order
void find_min(set *s, void *out_key);
void find_max(set *s, void *out_key);
void find_prev(set *s, void *in_key, void *out_key);
void find_prev_entry(set *s, uint64_t hash, void *out_key);
void find_next(set *s, void *in_key, void *out_key);
void find_next_entry(set *s, uint64_t hash, void *out_key);