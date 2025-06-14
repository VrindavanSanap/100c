#ifndef MY_SORT_HEADER_H
#define MY_SORT_HEADER_H

#include <stdlib.h>

/* Comparison function. Receives two generic (void) pointers to the items under comparison. */
int compare_ints(const void *p, const void *q);

/* Sort an array of n integers, pointed to by a. */
void sort_ints(int *a, size_t n);

#endif // MY_SORT_HEADER_H
