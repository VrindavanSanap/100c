#include <stdio.h>

#include "dynamic_array.h"
typedef struct {
  int x;
  int y;
} point;

int main() {
  dynamic_array *da = da_build(sizeof(point));
  size_t size;

  size = da_get_size(da);
  printf("size = %zu \n", size);

  for (int i = 0; i < 10; i++) {
    point p = {i, i + i};
    da_insert_last(da, &p);
  }
  size = da_get_size(da);
  printf("size = %zu \n", size);

  for (int i = 0; i < 10; i++) {
    point p;
    da_get_at(da, i, &p);
    printf("%d %d \n", p.x, p.y);
  }

  for (int i = 0; i < 10; i++) {
    point p;
    da_delete_last(da);
  }
  size = da_get_size(da);
  printf("size = %zu \n", size);

  return 0;
}