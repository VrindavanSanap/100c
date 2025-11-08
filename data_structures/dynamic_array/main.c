#include <stdio.h>

#include "dynamic_array.h"
typedef struct {
  int x;
  int y;
} point;

int main() {
  dynamic_array *da = da_build(sizeof(point));
  return 0;
}