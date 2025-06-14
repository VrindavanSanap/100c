#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
const char charset[] = ".,-~:;=!*#$@";

// Define the size of the character set
#define CHARSET_SIZE (sizeof(charset) - 1)

char map_value_to_char(int value) {
  // Ensure the value is in the range 0-255
  if (value < 0 || value > 255) {
    return '?';  // Return '?' for out-of-range values
  }
  // Map the value to an index in the character set
  int index = (value * CHARSET_SIZE) / 256;
  return charset[index];
}

void read_and_print_uint32(FILE* file, uint32_t* value,
                           const char* error_message, const char* label) {
  size_t result = fread(value, sizeof(*value), 1, file);
  *value = __builtin_bswap32(*value);
  if (result != 1) {
    printf("%s\n", error_message);
    fclose(file);
    exit(1);
  }
  printf("%s: %u\n", label, *value);
}

void visualize_number(FILE* file, int index) {
  int base_pose = 16;

  fseek(file, base_pose + (index * 784), SEEK_SET);
  size_t result;
  for (int i = 0; i < 28; i++) {
    for (int j = 0; j < 28; j++) {
      uint8_t pixel;
      result = fread(&pixel, sizeof(pixel), 1, file);
      if (result != 1) {
        printf("Error reading pixel\n");
        fclose(file);
        exit(1);
      }
      printf("%c ", map_value_to_char(pixel));
    }
    printf("\n");
  }
}
int get_label(FILE* file, int index) {
  int base_pose = 8;

  fseek(file, base_pose + (index - 1), SEEK_SET);
  size_t result;
  uint8_t pixel;
  result = fread(&pixel, sizeof(pixel), 1, file);
  if (result != 1) {
    printf("Error reading pixel\n");
    fclose(file);
    exit(1);
  }
  return (int)pixel;
}

char* train_image_file_name = "train-images-idx3-ubyte";
char* train_label_file_name = "train-labels-idx1-ubyte";
// Smaller
char* test_image_file_name = "t10k-images-idx3-ubyte";
char* test_label_file_name = "t10k-labels-idx1-ubyte";

FILE* train_image_file;
FILE* train_label_file;
FILE* test_image_file;
FILE* test_label_file;
FILE* image_file;
FILE* label_file;

uint32_t magic_number;
uint32_t num_items;
uint32_t n_rows;
uint32_t n_cols;
size_t result;

bool train_set = true;

void switch_set() {
  if (train_set) {
    image_file = test_image_file;
    label_file = test_label_file;
  } else {
    image_file = train_image_file;
    label_file = train_label_file;
  }

  fseek(image_file, 0, SEEK_SET);
  read_and_print_uint32(image_file, &magic_number,
                        "failed to read magic number", "Magic number");
  read_and_print_uint32(image_file, &num_items, "failed to read num_items",
                        "Num items");
  read_and_print_uint32(image_file, &n_rows, "failed to read n rows",
                        "Num rows");
  read_and_print_uint32(image_file, &n_cols, "failed to read num_cols",
                        "Num cols");
  train_set = !train_set;
}

int main() {
  int index = 0;
  char c;

  train_image_file = fopen(train_image_file_name, "rb");
  train_label_file = fopen(train_label_file_name, "rb");
  test_image_file = fopen(test_image_file_name, "rb");
  test_label_file = fopen(test_label_file_name, "rb");

  if (!train_image_file || !train_label_file || !test_image_file ||
      !test_label_file) {
    printf("Error opening one or more files\n");
    return 1;
  }

  switch_set();
  while (true) {
    printf("\n\n\n * MNIST visualisation *\n\n");
    if (train_set) {
      printf("Type 't' to switch to test set\n");
    } else {
      printf("Type 't' to switch to train set\n");
    }
    printf("Type 'q' to quit\n");
    printf("Please enter a number index (1 - %u):", num_items);
    char input[10];
    scanf("%s", input);
    if (input[0] == 't') {
      // handle switching
      switch_set();
      continue;
    } else if (input[0] == 'q') {
      fclose(train_image_file);
      fclose(train_label_file);
      fclose(test_image_file);
      fclose(test_label_file);
      return 0;
    } else {
      index = atoi(input);
    }
    while ((c = getchar()) != '\n' && c != EOF);
    if (index <= 0 || index > num_items) {
      printf("Oops, the number should be between 1 and %u\n", num_items);
    } else {
      printf("You entered: %d\n", index);
      visualize_number(image_file, index - 1);
      int label = get_label(label_file, index);
      printf("Label: %d \n", label);
    }
  }
  return 0;
}
