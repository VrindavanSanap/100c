#include <stdio.h>

void print_binary(int a) {
  unsigned int b = 1;
  b = b << 31;
  for (int i = 0; i < 32; i++) {
    if (i % 4 == 0) {
      printf(" ");
    }
    if (b & a) {
      printf("1");
    } else {
      printf("0");
    }
    b = b >> 1;
  }
  printf("\n");
}
void print_hex(char *bs) {}

int main() {
  int a;
  a = 0x25B9D2;
  print_binary(a);
  a = 0xA8B3D;
  print_binary(a);

  a = 0b1010111001001001;
  printf("%X\n", a);
  a = 0b1100100010110110010110;
  printf("%X\n", a);

  return 0;
}
