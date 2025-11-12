#include <stdbool.h>
#include <stdio.h>

typedef int (*t_my_func)(int, int);
int foo(int x, int y) { return x + y; }

bool idenitity(int x) { return true; };
bool even(int x) { return x % 2 == 0; };

void print_if(int xs[10], bool (*predicate)(int)) {
  printf("[ ");
  for (int i = 0; i < 10; i++) {
    if (predicate(xs[i])) {
      printf("%d, ", xs[i]);
    }
  }
  printf("]\n");
}

int main(void) {
  // t_my_func f = foo;
  // printf("%d \n", f(2, 3));

  int xs[] = {1, 22, 3, 41, 15, 6, 27, 18, 9, 10};
  printf("Orignal array: ");
  print_if(xs, idenitity);
  printf("Conditionally printed array: ");
  print_if(xs, even);
  return 0;
}
