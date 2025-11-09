//
//  dynamic_array.h
//  dynamic_array
//
//  Created by Vrindavan Sanap on 10/11/25.
//

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stddef.h>
typedef struct dynamic_array dynamic_array;

/* function prototypes */

// Operations

// Container
// Creates a dynamic array
dynamic_array *da_build(size_t element_size);

// Static operations (operations which do not modify the size of array)

// Ram model of computation
// memory is array of w-bit words
// key size >= log(capacity) ie all elements need to addressable
// Read/write given an index takes O(1) time
// Takes O(1) time ( memory address(element) = address(da)  + index *
// element_size ) There fore da_get_at and da_set_at take O(1) time

// give element at given index
// this is better than int da_get_at(dynamic_array *da, size_t index, void
// *item); because that forces a copy to item even if strictly wanted to just
// read so its slower Takes O(1) time;

// returns 0 if success otherwise -1
int da_get_at(const dynamic_array *da, size_t index, void *out_element);

// set element at given index
// like python lists if index > dynamic_array.size : index = dyanmic_array.size
// Takes O(1) time;
// returns 0 if success otherwise -1
int da_set_at(dynamic_array *da, const void *element, size_t index);

// Dynamic operations
// These operatoins change the size of the array

// insert element at the start of the array;
// takes O(n) time
// shit all the other element to right by one-index, and then insert the given
// element at first index;
void da_insert_first(dynamic_array *da, const void *element);
// delete first element of the array
// takes O(n) time
// remove the first element and shit all the other element to left by one-index
void da_delete_first(dynamic_array *da);

// insert element at given idnex
// move all elements starting from the given index to right by one index then
// insert at given index takes O(n) time
void da_insert_at(dynamic_array *da, const void *element, size_t index);
// insert element at given idnex
// move all elements starting from the given index+1 to left by one index
// takes O(n) time
void da_delete_at(dynamic_array *da, size_t index);

// insert element at the end of the array;
// takes O(1) amortized time
void da_insert_last(dynamic_array *da, const void *element);
// delete last element of the array
// takes O(1) amortized time
void da_delete_last(dynamic_array *da);

// give # elements present in the array
size_t da_get_size(dynamic_array *da);

#endif /* DYNAMIC_ARRAY_H */
