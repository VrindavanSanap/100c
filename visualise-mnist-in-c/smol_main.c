#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  char* file_name =
      "/Users/vrindavan/Datasets/mnist_for_c/d4fdde61aca9f72d5fe2315410bb46a5";
  FILE* file;
  uint32_t magic_number;
  uint32_t num_items;
  size_t result;

  file = fopen(file_name, "rb");
  if (file == NULL) {
    printf("Error opening file\n");
    exit(1);
  }
  result = fread(&magic_number, sizeof(magic_number), 1, file);
  magic_number = __builtin_bswap32(magic_number);
  if (result != 1) {
    printf("Error reading magic number\n");
    fclose(file);
    exit(1);
  }
  printf("Magic number: %d\n", magic_number);
  result = fread(&num_items, sizeof(num_items), 1, file);
  num_items = __builtin_bswap32(num_items);
  if (result != 1) {
    printf("Error num items\n");
    fclose(file);
    exit(1);
  }
  printf("Num items: %d\n", num_items);

  uint8_t label;
  for (int i = 0; i < 10; i++) {
    result = fread(&label, sizeof(label), 1, file);
    if (result != 1) {
      printf("Error label number\n");
      fclose(file);
      exit(1);
    }
    printf("%d\n", label);
  }
  fclose(file);
  return 0;
}
