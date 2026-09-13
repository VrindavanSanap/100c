#include <stdint.h>
#include <stdio.h>
#include <time.h>
double nanos(void) {
  struct timespec ts;

  if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0) {
    fputs("timespec_get failed!", stderr);
    return 0;
  }
  return 1000000000.0 * ts.tv_sec + ts.tv_nsec;
}

int main() {
  double st = nanos();
  for (uint32_t a = 1; a < 4'000'000'000; a++) {
    if ((a & (a - 1)) == 0) {
      printf("%u \n", a);
    }
  }
  double et = nanos();
  printf("4 billion iterations in %f seconds", (et - st) / 1000000000);
  return 0;
}
