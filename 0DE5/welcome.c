#include <stdio.h>

int make_it_higher(int n){
  return n + 100 + 20 + 7;
}

int main(){
  int name = 0;

  while (1){
    name = make_it_higher(name);
    printf("Welcome to %04X\n", name);
  }

}
