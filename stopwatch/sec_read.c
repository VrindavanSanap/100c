#include <stdio.h>
#define SECONDS_IN_MINUTE 60
#define MINUTES_IN_HOUR 60
#define SECODNS_IN_HOUR (SECONDS_IN_MINUTE * MINUTES_IN_HOUR)

void int_read(int given_seconds, int *seconds, int *minutes, int *hours) {
  if (given_seconds < 0) {
    *seconds = 0;
    *minutes = 0;
    *hours = 0;
    return;
  }
  *seconds = given_seconds % SECONDS_IN_MINUTE;
  *minutes = (given_seconds / (SECONDS_IN_MINUTE)) % MINUTES_IN_HOUR;
  *hours = (given_seconds / (SECODNS_IN_HOUR));
}

int main() {
  int given_seconds;
  printf("Enter time in seconds \n");
  if (scanf("%d", &given_seconds) != 0) {
    printf("Error reading seconds");
    return 1;
  }
  int seconds = 0;
  int minutes = 0;
  int hours = 0;
  int_read(given_seconds, &seconds, &minutes, &hours);
  printf("%d hours %d minutes %d seconds \n", hours, minutes, seconds);
  return 0;
}
