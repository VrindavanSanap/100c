#include <stdio.h>

void for_loop(int n){
  for (int i = 0; i < n;i ++){
    printf("%d -", i);
  }
  printf("\n");
}

void while_loop(int n){
  int i = 0;
  while (i < n){
    printf("%d -", i++);
  }
  printf("\n");
}
void do_while(int n){
  int i = 0;
  do{
    printf("%d -", i++);
  }while(i < n);
  printf("\n");
}
int main(){
  for_loop(5);
  while_loop(5);
  do_while(5);
}
