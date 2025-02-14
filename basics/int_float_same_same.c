#include <stdio.h>

void processNumber(float num) { printf("Received number: %f\n", num); }

int main() {
  int intValue = 5;
  float floatValue = 3.14;

  processNumber(intValue);   // Passing an int
  processNumber(floatValue); // Passing a float

  return 0;
}
