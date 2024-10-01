//
//  line_by_line.c
//  100c/strings  
//
//  Created by Vrindavan Sanap on 2024-10-02.
//  Description: Prints the lines in a text file line by line.
//


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  if (argc != 2) {
    printf("Usage ./line_by_line <file_name.txt> \n");
    return 1;
  }

  char* file_name = argv[1];
  FILE *file = fopen(file_name, "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }
  char *line = NULL;
  size_t line_buffer_len;
  int n_lines = 0;
  while (getline(&line, &line_buffer_len, file) != -1){
    printf("%d: %s", n_lines++ , line); 

  }
  fclose(file);
  return 0;




}


