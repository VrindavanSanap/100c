#include <stdio.h>
#include "file_size.h"
#include "sort_ints.h"

int main(int argc, char *argv[]){
    if (argc != 2){
      printf("Ussage sort_char <filename>");
      return 1;
    }
    FILE *file;
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Failed to open file\n");
        return 1;
    }

    int c;
    long fs = file_size(file);

    file = fopen(argv[1], "r");
    
    int chars[fs];
    for(int i = 0; i < fs; i++){ 
           c = fgetc(file);
           chars[i] = c;
    }
   
    for(int i = 0; i < fs; i++){ 
      c = chars[i];
    }
    sort_ints(chars, fs);

    for(int i = 0; i < fs; i++){ 
      c = chars[i];
      if(c != 10){
      printf("%c",c);
      }
    }
}
