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

// Static operations (operations that do not modify the size of the array)

// RAM model of computation
// memory is an array of w-bit words
// key size >= log(capacity), i.e., all elements need to be addressable
// Read/write for a given index takes O(1) time
// Takes O(1) time (memory address(element) = address(da)  + index *
// element_size). Therefore da_get_at and da_set_at take O(1) time

// Gives the element at the given index
// This is better than int da_get_at(dynamic_array *da, size_t index, void
// *item); because that forces a copy to item even if we only wanted to read,
// so it's slower. Takes O(1) time;

// returns 0 on success, otherwise -1
int da_get_at(const dynamic_array *da, size_t index, void *out_element);

// Sets the element at the given index
// Like Python lists, if index > dynamic_array.size, index =
// dyanmic_array.size Takes O(1) time;
// returns 0 on success, otherwise -1
int da_set_at(dynamic_array *da, const void *element, size_t index);

// Dynamic operations
// These operations change the size of the array

// Inserts an element at the start of the array.
// Takes O(n) time
// Shifts all other elements to the right by one index, and then inserts the
// given element at the first index.
int da_insert_first(dynamic_array *da, const void *element);
// Deletes the first element of the array.
// Takes O(n) time
// Removes the first element and shifts all other elements to the left by one
// index.
void da_delete_first(dynamic_array *da);

// Inserts an element at the given index.
// Moves all elements starting from the given index to the right by one index,
// then inserts at the given index. Takes O(n) time.
int da_insert_at(dynamic_array *da, const void *element, size_t index);
// Deletes an element at the given index.
// Moves all elements starting from index + 1 to the left by one index.
// Takes O(n) time.
void da_delete_at(dynamic_array *da, size_t index);

// Inserts an element at the end of the array.
// Takes O(1) amortized time.
int da_insert_last(dynamic_array *da, const void *element);
// Deletes the last element of the array.
// Takes O(1) amortized time.
void da_delete_last(dynamic_array *da);

// Gives the number of elements present in the array.
size_t da_get_size(dynamic_array *da);

void da_free(dynamic_array *da);
#endif /* DYNAMIC_ARRAY_H */
