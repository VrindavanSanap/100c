#include <stdint.h>
#include <stdio.h>

int main() {
  for (uint32_t a = 1; a < 10000; a++) {
    if ((a & (a - 1)) == 0) {
      printf("%d is a power of 2\n", a);
    }
  }
  return 0;
}
