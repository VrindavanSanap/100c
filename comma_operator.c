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

  /*
  The comma operator has the lowest precedence of all C operators.
  In this case, 'a' is assigned to 'd' because the assignment operator has
  higher precedence. The expression 'b' is evaluated, but its result is
  discarded.
  */
  int d = a, b;
  printf("d = %d\n", d);

  /*
  For example, in the following macro, the return value of assert() is
  discarded. The macro then returns the value of _Py_CAST(PyListObject *, (op)).
  #define _PyList_CAST(op) \
    (assert(PyList_Check(op)), _Py_CAST(PyListObject *, (op)))

  */

  return 0;
}
