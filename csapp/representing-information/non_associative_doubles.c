#include <stdio.h>

int main() {
  double a = 3.14;
  double b = 1e20;
  double c;
  c = (a + b) - b;
  printf("%f \n", c);
  c = a + (b - b);
  printf("%f \n", c);
}