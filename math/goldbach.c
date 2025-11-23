#include <stdio.h>
#include <stdlib.h>

#include "primes.h"

void goldbach(const int n) {
  int i = 0;
  int p = 0;
  while (1) {
    p = nth_prime(++i);
    if (p > (n / 2)) {
      break;
    }
    if (is_prime(n - p)) {
      printf("%d = %d + %d \n", n, p, n - p);
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("usage: goldbach n");
    return -1;
  }
  const int n = atoi(argv[1]);
  goldbach(n);

  return 0;
}
