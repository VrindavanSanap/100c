#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "dict.h"
#include "stoi.h"
#include "itos.h"
#include "line_count.h"
#define MAX_STRING_LENGTH 100

void min_max(const char words[][MAX_STRING_LENGTH], int n_words, int *min_ptr, int *max_ptr){
    int max = 0;    
    int min = 999;
    int length;

    for (int i = 0; i < n_words; i++){
        length = strlen(words[i]);
        if (max < length){
            max = length;
        }
        if (min > length){
            min = length;
        }
    }
  *min_ptr = min;
  *max_ptr = max;
}

int main() {
   
    FILE *file = fopen("names.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int n_words = line_count(file);
    printf("n-words= %d \n", n_words);
    char strings[n_words][MAX_STRING_LENGTH];
    int i = 0;

    while (fgets(strings[i], MAX_STRING_LENGTH, file)) {
        int length = strlen(strings[i]);
        if (length > 0 && strings[i][length - 1] == '\n') {
            strings[i][length - 1] = '\0';
        }
        i++;
    }
    fclose(file);
    int min, max;
    min_max(strings, n_words, &min, &max);
    printf("min_l = %d \nmax_l = %d", min, max);
    return 0;
}

