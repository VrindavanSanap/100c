#include <stdio.h>
#include <time.h>

double nanos(void) {
  struct timespec ts;

  if (timespec_get(&ts, TIME_UTC) != TIME_UTC) {
    fputs("timespec_get failed!", stderr);
    return 0;
  }
  return 1000000000.0 * ts.tv_sec + ts.tv_nsec;
}

// Function to check if a number is prime
int is_prime(int n) {
  // 0, 1, and negative numbers are not prime
  if (n <= 1) {
    return 0;  // 0 represents false
  }

  // Check for factors from 2 up to the square root of n.
  // If a factor is found, the number is not prime.
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return 0;  // Not prime
    }
  }

  // If no factors were found, the number is prime
  return 1;  // 1 represents true
}

int main() {
  int count = 0;  // How many primes we've found
  int num = 2;    // The number we are currently checking

  printf("The first 100 prime numbers are:\n");
  double st = nanos();
  double et;
  // Loop until we have found 100 primes
  while (count < 1000) {
    if (is_prime(num)) {
      printf("%d %d \n", num, count + 1);
      count++;
    }
    num++;  // Move to the next number
  }
  et = nanos();
  et = et - st;
  printf("It took %f seconds", et / 1000000000);
  return 0;
}
