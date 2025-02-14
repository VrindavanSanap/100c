#include <stdbool.h>
#include <stdio.h>

int foo(int x, int y) { return x + y; }

bool even(int x) { return x % 2 == 0; }

void print_if(int xs[10], bool (*predicate)(int)) {
  for (int i = 0; i < 10; i++) {
    if (predicate(xs[i])) {
      printf("%d \n", xs[i]);
    }
  }
}

int main(void) {
  int xs[] = {1, 22, 3, 41, 15, 6, 27, 18, 9, 10};
  int (*f)(int, int) = foo;
  print_if(xs, even);
  return 0;
}
