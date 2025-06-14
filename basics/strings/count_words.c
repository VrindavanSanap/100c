//
//  count_words.c
//  100c
//
//  Created by Vrindavan Sanap on 2024-10-02.
//  Description: Returns the number of words in a text file.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_words(const char* s)
{
    //
    // Returns the number of words in a given string
    //
    //

    // Get the first token
    char* str_copy = strdup(s);
    char* token = strtok(str_copy, " \n\r\t");
    int n_words = 0;

    // Walk through other tokens
    while (token != NULL)
    {
        token = strtok(NULL, " \n\r\t");
        n_words++;
    }
    return n_words;
}

int main(int argc, char* argv[])
{

    if (argc != 2)
    {
        printf("Usage ./count_words <file_name.txt> \n");
        return 1;
    }

    char* file_name = argv[1];
    FILE* file = fopen(file_name, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }
    char* line = NULL;
    size_t line_buffer_len;
    int n_lines = 0;
    int total_words = 0;
    while (getline(&line, &line_buffer_len, file) != -1)
    {
        int n_words = count_words(line);
        printf("%d (%d words): %s", n_lines++, n_words, line);
        total_words += n_words;
    }

    fclose(file);
    printf("Total words in %s file are %d", file_name, total_words);
    return 0;
}
