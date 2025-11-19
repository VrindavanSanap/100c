#include <stdio.h>

int main(void) {
  int a = 69;
  int b = 420;
  /*
  The comma operator in C evaluates the first operand, discards the result,
  then evaluates the second operand and returns its value.
  */
  printf("int a = %d\n", a);
  printf("int b = %d\n", b);

  printf("int c = (a, b);\n");
  int c = (a, b);
  printf("c = %d\n", c);

  return 0;
}
