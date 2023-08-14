#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <limits.h>
#include "line_count.h"
#define MAX_STRING_LENGTH 100

void min_max(const char words[][MAX_STRING_LENGTH], int n_words, int *min_ptr, int *max_ptr){
    int max = 0;    
    int min = 999;
    int length;

    for (int i = 0; i < n_words ; i++){
        length = strlen(words[i]);
        if (max < length){
            max = length;
        }
        if (min > length){
            min = length;
            printf("%d %s \n", min, words[i]);
        }
    }
    *min_ptr = min;
    *max_ptr = max;
}

void read_strings(FILE *file, char strings[][MAX_STRING_LENGTH], int n_words){
    int i = 0;
    while (i < n_words && fgets(strings[i], MAX_STRING_LENGTH, file)){
        int length = strlen(strings[i]);
        if (length > 0 && strings[i][length - 1] == '\n'){
            strings[i][length - 1] = '\0';
        }
        i++;
    }
}
void find_min_max_lengths(char strings[][MAX_STRING_LENGTH], int n_words, int *min, int *max){
    *min = INT_MAX;
    *max = 0;

    for (int i = 0; i < n_words; i++)
    {
        int length = strlen(strings[i]);
        if (length < *min)
        {
            *min = length;
        }
        if (length > *max)
        {
            *max = length;
        }
    }
}

int main(int argc, char *argv[]) {
    char *file_name = "names.txt";
    if (argc == 2){
        file_name = argv[1];
    }
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int n_words = line_count(file);
    printf("n-words = %d \n", n_words);
    char words[n_words][MAX_STRING_LENGTH];
    read_strings(file, words, n_words);
    fclose(file);
    int min, max;
    min_max(words, n_words, &min, &max);
    printf("min_l = %d \nmax_l = %d \n", min, max);
    char word[MAX_STRING_LENGTH];
    for (int i = 0; i < n_words; i++){
        strcpy(word, words[i]);
        printf("%d %s \n",i ,word);
    }
    return 0;
}

