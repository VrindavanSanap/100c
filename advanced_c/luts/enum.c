#include <stdio.h>

int main() {
  enum LEVEL {
    A = 20,
    B,
    C = 11,
    D,
    E,
  };

  printf("%d %d %d %d %d\n", A, B, C, D, E);

  return 0;
}
