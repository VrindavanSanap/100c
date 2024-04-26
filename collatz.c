//
//  collatz.c 
//  100c 
//
//  Created by Vrindavan sanap on 7/13/23.
//


//  Code demonstrating the collatz conjecture 


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
  }while(n != 1);
}

int main(int argc, char *argv[]){
  if (argc < 3){
    printf("usage: collatz n");
    return 0;
  }

  int n = atoi(argv[1]);
  collatz(n);

  return 0;
}
