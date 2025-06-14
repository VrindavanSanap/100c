/*
    https://github.com/gcc-mirror/gcc/blob/master/gcc/ginclude/stdbool.h
    true and false in c are just 0 and 1
*/

#include <stdio.h>
#include <stdbool.h>

int main(void) {
  // this is exactly same as int x = 1
  bool x = true;

  if (x) {
    printf("x is true!\n");
  }
}
