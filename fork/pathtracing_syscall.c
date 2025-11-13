#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  fork();
  fork();
  printf("hello\n");
  printf("pid = %d \n", getpid());
  return 0;
}
