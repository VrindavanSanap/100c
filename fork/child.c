#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();

  if (pid < 0) {
    // Error
  } else if (pid == 0) {
    // I am the CHILD process
    printf("Child PID: %d, Parent PID (PPID): %d\n", getpid(), getppid());
  } else {
    // I am the PARENT process
    printf("Parent PID: %d, My Child's PID is: %d\n", getpid(), pid);
  }
  return 0;
}
