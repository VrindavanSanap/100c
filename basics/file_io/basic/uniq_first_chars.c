#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Set {
  char elements[MAX_SIZE];
  int size;
};

void init_set(struct Set* set) { set->size = 0; }

bool contains(struct Set* set, int value) {
  for (int i = 0; i < set->size; ++i) {
    if (set->elements[i] == value) {
      return true;
    }
  }
  return false;
}

int add(struct Set* set, char element) {
  if (!contains(set, element)) {
    if (set->size < MAX_SIZE) {
      set->elements[set->size++] = element;
    } else {
      return -1;
    }
  } else {
    return 0;
  }
}

int remove_element(struct Set* set, char element) {
  for (int i = 0; i < set->size; i++) {
    if (set->elements[i] == element) {
      for (int j = i; j < set->size - 1; ++j) {
        set->elements[j] = set->elements[j + 1];
      }
      set->size--;
      return 1;
    }
  }
  return 0;
}

void print_set(struct Set* set) {
  printf("{ ");
  for (int i = 0; i < set->size; ++i) {
    printf("%c ", set->elements[i]);
  }
  printf("}\n");
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Ussage ./uniq_first_chars <file_name.txt> \n");
  }

  char* file_name = argv[1];
  FILE* file = fopen(file_name, "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }
  struct Set my_set;
  init_set(&my_set);
  char word[100];
  while (fscanf(file, "%99s", word) == 1) {
    add(&my_set, word[0]);
  }
  print_set(&my_set);
  printf("Number of unique first characters is %d", my_set.size);
  return 0;
}
