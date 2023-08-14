#include <stdio.h>
#include <stdlib.h>
void collatz(int n){
  printf("%d \n", n);
  do{
    if(n%2 == 0){
      n = n/2;
    }else{
      n = 3*n + 1;
    }
    printf("%d \n", n);
  }while(n!= 1);
}

int main(int argc, char *argv[]){
  if (argc != 2){
    printf("usage: collatz n");
  }
  int n = atoi(argv[1]);
 collatz(n);

  return 0;
}
