#include <stdio.h>

int main() {
  // Move the cursor to row 10, column 5
  printf("\033[10;5H");
  // Print something at the new position
  printf("Hello, world!\n");
  return 0;
}
