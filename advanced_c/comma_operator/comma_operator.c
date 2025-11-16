#include <stdio.h>

int main(void) {
  int a = 69;
  int b = 420;
  /*
  The comma operator in C evaluates the first operand, discards the result,
  then evaluates the second operand and returns its value.
  */
  int c = (a, b);
  printf("c = %d\n", c);

  return 0;
}
