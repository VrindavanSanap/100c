#include <stdio.h>

int main(){
  printf("Tell how many seconds do you want to set the timmer for? \n");
  printf("N Seconds:");
  int seconds;
  scanf("%d", &seconds);
  printf("Timmer started for %d seconds\n", seconds);

  return 0;
}
