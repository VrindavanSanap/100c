#include <stdio.h>

struct Point {
  int x;
  int y;
};

int main() {
  struct Point p1 = {10, 20};
  struct Point* p2 = &p1;

  printf("x coordinate: %d\n", p1.x);
  printf("x coordinate: %d\n", p1.y);
  printf("x coordinate: %d\n", (*p2).x);  // Equivalent to (*p2).x
  printf("y coordinate: %d\n", (*p2).y);  // Equivalent to (*p2).y
  printf("x coordinate: %d\n", p2->x);    // Equivalent to (*p2).x
  printf("y coordinate: %d\n", p2->y);    // Equivalent to (*p2).y
  return 0;
}
