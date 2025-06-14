#include <stdio.h>

float dot(float* a, float* b, int size) {
  float c = 0;
  for (int i = 0; i < size; i++) {
    c += a[i] * b[i];
  }
  return c;
}

int main() {
  int s = 4;
  float a[] = {1, 2, 3, 4};
  float b[] = {5, 6, 7, 8};
  float c = dot(a, b, s);

  printf("%f", c);
}
