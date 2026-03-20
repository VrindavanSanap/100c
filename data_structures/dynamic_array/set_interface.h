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

#include "dynamic_array.h"
#include "stdbool.h"

typedef struct set set;

// Container
/*
  cmp_func:
    returns 0 if a and b are equal
    returns a positive value if a > b
    returns a negative value if a < b
*/
set *set_build(size_t element_size,
               int (*compare)(const void *a, const void *b));

// Static
bool set_find(set *s, const void *element);
size_t set_get_size(set *s);

// Dynamic
void set_insert(set *s, const void *element);
void set_delete(set *s, const void *element);

// Order
/*
TODO
void find_min(set *s, void *out_key);
void find_max(set *s, void *out_key);
void find_prev(set *s, void *in_key, void *out_key);
void find_prev_entry(set *s, uint64_t hash, void *out_key);
void find_next(set *s, void *in_key, void *out_key);
void find_next_entry(set *s, uint64_t hash, void *out_key);
*/