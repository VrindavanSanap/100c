#include <stdio.h>

/*
  This program counts the number of words from a given text file.
  Ussage ./count_words <file_name.txt>
*/

int main(int argc, char *argv[]){
  
  if(argc != 2){
    printf("Ussage ./count_words <file_name.txt> \n");
  }
  char* file_name =  argv[1];
  FILE *file = fopen(file_name, "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  char word[100];  
  int n_words = 0;
  while (fscanf(file, "%99s", word) == 1) {
    //printf("%s\n", word);
    n_words += 1;
  }
  printf("Number of words in %s is %d \n", file_name, n_words);
  fclose(file);
  return 0;
}
