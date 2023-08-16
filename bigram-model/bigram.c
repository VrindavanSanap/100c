#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <limits.h>
#include "line_count.h"
#include "stoi.h"
#include "dict.h"
#include "plot_N.h"
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
    Dictionary dict= stoi();
    char word[MAX_STRING_LENGTH];
    int N[27][27] = {0};

    for (int i = 0; i < n_words; i++){
        char chs[strlen(words[i]) + 3];
        chs[0] = '.';
        strcpy(chs + 1, words[i]);
        chs[strlen(words[i]) + 1] = '.';
        chs[strlen(words[i]) + 2] = '\0';
 
        for (int j = 0; j < strlen(chs) - 1; j++){
            char ch1[2]; // String to hold ch1
            char ch2[2]; // String to hold ch2
            ch1[0] = chs[j];
            ch1[1] = '\0';
            ch2[0] = chs[j + 1];
            ch2[1] = '\0';
            
            int ix1 = get_value_by_key(&dict, ch1);
            int ix2 = get_value_by_key(&dict, ch2);
            N[ix1][ix2]++;
        }
    }
    plot_N(N);
    return 0;
}

