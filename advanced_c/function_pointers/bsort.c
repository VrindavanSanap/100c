#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utils/utils.h>

int compare_ints(const void *p, const void *q) {
  int num1 = *(const int *)p;
  int num2 = *(const int *)q;
  return num1 - num2;
}
int compare_strs(const void *p, const void *q) {
  char *str1 = *(char **)p;
  char *str2 = *(char **)q;
  return strcmp(str1, str2);
}

// Swap function to exchange two elements
// We use unsigned char to handle byte-wise copying safely for any data type
void swap(void *a, void *b, size_t size) {
  unsigned char *p = a, *q = b, temp;
  for (size_t i = 0; i < size; i++) {
    temp = p[i];
    p[i] = q[i];
    q[i] = temp;
  }
}

void bsort(void *arr, int num, int size,
           int (*compare_elm)(const void *, const void *)) {
  for (int i = 0; i < num; i++) {
    for (int j = 0; j < num - 1 - i; j++) {
      char *elm_1 = (char *)arr + j * size;
      char *elm_2 = (char *)arr + (j + 1) * size;
      if (compare_elm(elm_1, elm_2) > 0) {
        swap(elm_1, elm_2, size);
      }
    }
  }
}

int main() {
  const char *str_arr[] = {"gravity", "diamond", "apple",  "horizon", "flame",
                           "kernel",  "complex", "jungle", "eclipse", "bridge"};
  int num = (int)(sizeof(str_arr) / sizeof(*str_arr));
  print_str_arr(str_arr, num);
  bsort(str_arr, num, sizeof(*str_arr), compare_strs);
  print_str_arr(str_arr, num);
  return 0;
}
