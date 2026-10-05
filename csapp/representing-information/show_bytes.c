#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_unsigned_char_bits(unsigned char c){
  unsigned char j;
  j = 128;
  for (int i = 0; i< 8; i++){
    if (j & c){
      printf("1");
    }else{
      printf("0");
    }
    j = j >> 1;
  }
  printf(" ");
}

void show_bits(byte_pointer start, size_t len){
  for (int i = len-1; i>= 0;i--){
    unsigned char c = start[i];
    show_unsigned_char_bits(c);
  }
  printf("\n");
}

void show_bytes(byte_pointer start, size_t len){
  for (int i = len-1; i>= 0;i--){
    printf("%.2x", start[i]);
  }
  printf("\n");
}


void show_int(int x){
  show_bytes((byte_pointer) &x, sizeof(int));
  show_bits((byte_pointer) &x, sizeof(int));
}

void show_float(float x){
  show_bytes((byte_pointer) &x, sizeof(float));
  show_bits((byte_pointer) &x, sizeof(float));
}



int main(){
  int a = 100;
  float b = 3.14;
  show_int(a);
  show_float(b);
  return 0;
}
