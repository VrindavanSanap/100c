#include <stdint.h>
#include <stdio.h>
#include <time.h>
double nanos(void) {
  struct timespec ts;

  if (clock_gettime(&ts, CLOCK_MONOTONIC) != CLOCK_MONOTONIC) {
    fputs("timespec_get failed!", stderr);
    return 0;
  }
  return 1000000000.0 * ts.tv_sec + ts.tv_nsec;
}
int main() {
  int s = 0;
  for (uint32_t a = 1; a < 1'000'000'000; a++) {
    if ((a & (a - 1)) == 0) {
      printf("%d \n", a);
    }
  }
  return 0;
}
