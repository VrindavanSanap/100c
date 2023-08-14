#include <stdio.h>
#include <stdlib.h>

int is_prime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int nth_prime(int n) {
    if (n <= 0)
        return -1;
    int count = 0;
    int num = 2; 
    while (count < n) {
        if (is_prime(num)) {
            count++;
        }
        num++;
    }
    return num - 1;
}

void goldbach(int n){
  int i = 0;
  int p = 0;
  while(1){
    p = nth_prime(++i); 
    if(p>(n/2)){
      break;
    }
    if(is_prime(n - p)){
      printf("%d = %d + %d \n",n ,p ,n-p);
    } 
  }
}

int main(int argc, char *argv[]){
  if (argc != 2){
    printf("usage: goldbach n");
    return -1;
  }
  int n = atoi(argv[1]);
  goldbach(n);
  
  return 0;
}

