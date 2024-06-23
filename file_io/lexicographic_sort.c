#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int compare_strings(const void *a , const void *b){ 
  const char*str1 = *(const char **)a;
  const char*str2 = *(const char **)b;
  return strcmp(str1, str2);
}
int main() {
  char word[50];
  char *words[120];

  FILE *file = fopen("unsorted.txt", "r");
  if (file == NULL) {
    perror("Error opening file");
    return -1;
  }

  int n_words = 0;
  while (fscanf(file, "%s", word) == 1){
    words[n_words] = strdup(word);
    if (words[n_words++] == NULL) {
      perror("Memory allocation error");
      return EXIT_FAILURE;
    }
  }

  qsort(words, n_words, sizeof(char *), compare_strings);
  fclose(file);
  file = fopen("sorted.txt", "w");
  if (file == NULL) {
      perror("Error opening file");
      return -1;
  }

  for (int i=0;i< n_words;i++){
    fprintf(file, "%s\n", words[i]);
    free(words[i]);
  }
  fclose(file);
  return 0;
}
