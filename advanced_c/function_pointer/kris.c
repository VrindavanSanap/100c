#include <stdio.h>
#include <stdint.h>


int64_t add(int64_t, int64_t);
int64_t sub(int64_t, int64_t);

int main(){
  const char *str = "static";
  printf("str: %p \n", str);
  printf("main: %p \n", main);
  printf("add: %p \n", add);
  printf("sub: %p \n", sub);

}

int64_t add(int64_t a, int64_t b){

  return a + b;
}
int64_t sub(int64_t a, int64_t b){

  return a - b;
}
