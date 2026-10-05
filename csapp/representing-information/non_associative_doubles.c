#include <stdio.h>

int main() {
  double a = 3.14;
  double b = 1e20;
  double c;

  /*
     Floats and doubles are not real numbers but
     finite representations of real numbers.
     Hence, they don't strictly follow the properties
     of real numbers, such as associativity.

     The operations on them are, however, deterministic.
     They may not generate the expected result, but the result
     is at least consistent.
  */

  c = (a + b) - b;
  printf("%f \n", c);
  c = a + (b - b);
  printf("%f \n", c);
}