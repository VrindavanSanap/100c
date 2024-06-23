#include <stdio.h>
#include <unistd.h>


pid_t getpid(void);
pid_t getppid(void);
  


int main(){
  int a = getpid();
  int b = getppid();
  printf("%d %d", a,b );
  return 0;
}
