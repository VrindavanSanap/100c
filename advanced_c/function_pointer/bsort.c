#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "print_arr.h"

int compare_ints(const void* p, const void* q) {
  int num1 = *(const int*)p;
  int num2 = *(const int*)q;
  return num1 - num2;
}
int compare_strs(const void* p, const void* q) {
  char* str1 = *(char**)p;
  char* str2 = *(char**)q;
  return strcmp(str1, str2);
}

// Swap function to exchange two elements
// We use unsigned char to handle byte-wise copying safely for any data type
void swap(void* a, void* b, size_t size) {
  unsigned char *p = a, *q = b, temp;
  for (size_t i = 0; i < size; i++) {
    temp = p[i];
    p[i] = q[i];
    q[i] = temp;
  }
}

void bsort(void* arr, int num, int size,
           int (*compare_elm)(const void*, const void*)) {
  for (int i = 0; i < num; i++) {
    for (int j = 0; j < num - 1 - i; j++) {
      if (compare_elm(arr + j * size, (arr + (j + 1) * size)) > 0) {
        swap(arr + (j * size), arr + (j + 1) * size, size);
      }
    }
  }
}

int main() {
  const char* str_arr[] = {"gravity", "diamond", "apple",  "horizon", "flame",
                           "kernel",  "complex", "jungle", "eclipse", "bridge"};
  int num = (int)(sizeof(str_arr) / sizeof(*str_arr));
  print_str_arr(str_arr, num);
  bsort(str_arr, num, sizeof(*str_arr), compare_strs);
  print_str_arr(str_arr, num);
  return 0;
}
