//
//  open_text.c 
//  100c 
//
//  Created by Vrindavan on 3/08/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//


//  Code to open a text file 




#include <stdio.h>


int main(int argc, char *argv[]){
  FILE *file;
  file = fopen("text.txt", "r");
    if (file == NULL)
    {
        printf("Failed to open file\n");
        return 1;
    }
    char ch;
    int count = 0;
    while ((ch = fgetc(file)) != EOF)
    {
        printf("%c", ch);
    }
    return 0;
}
