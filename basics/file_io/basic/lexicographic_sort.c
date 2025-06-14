#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int compare_strings(const void* a, const void* b) {
  const char* str1 = *(const char**)a;
  const char* str2 = *(const char**)b;
  return strcmp(str1, str2);
}
int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Ussage ./lexo_sort <flename>");
    return -1;
  }

  char word[50];
  char* words[120];
  char* file_name = argv[1];
  FILE* file = fopen(file_name, "r");
  if (file == NULL) {
    perror("Error opening file");
    return -1;
  }

  int n_words = 0;
  while (fscanf(file, "%s", word) == 1) {
    words[n_words] = strdup(word);
    if (words[n_words++] == NULL) {
      perror("Memory allocation error");
      return EXIT_FAILURE;
    }
  }

  qsort(words, n_words, sizeof(char*), compare_strings);
  fclose(file);
  char output_file_name[60];
  char prepend[] = "sorted_";
  strcpy(output_file_name, prepend);
  strcat(output_file_name, file_name);

  file = fopen(output_file_name, "w");
  if (file == NULL) {
    perror("Error opening file");
    return -1;
  }

  for (int i = 0; i < n_words; i++) {
    fprintf(file, "%s\n", words[i]);
    free(words[i]);
  }
  fclose(file);
  return 0;
}
