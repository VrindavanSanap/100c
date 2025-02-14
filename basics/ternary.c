#include <stdio.h> //for printf

int main(void) // actual stuff happens here
{
  int y = 2;
  int x = 11;

  y += x > 10 ? 17 : 37; // If x > 10, add 17 to y. Otherwise add 37 to y.
  printf("y = %d\n", y);
}
