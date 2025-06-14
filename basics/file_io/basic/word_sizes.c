#include <stdio.h>
#include <string.h>

/*
  This program gives maximum/minimum size of word in text file.
  Also gives average size of word in text file.
  Ussage ./count_words <file_name.txt>
*/

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Ussage ./count_words <file_name.txt> \n");
    }
    char *file_name = argv[1];
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char word[100];
    char max_word[100];
    char min_word[100];
    int n_words = 0;
    int word_size = 0;
    int max_word_size = 0;
    int min_word_size = 999;
    float average_word_size = 0;
    float sum = 0;

    while (fscanf(file, "%99s", word) == 1) {
        n_words += 1;
        word_size = strlen(word);
        printf("%d %s \n", word_size, word);
        if (word_size < max_word_size) {
            strcpy(min_word, word);
            min_word_size = word_size;
        } else {
            strcpy(max_word, word);
            max_word_size = word_size;
        }
        sum = average_word_size * (n_words - 1);
        average_word_size = (sum + word_size) / (n_words);
    }

    printf("Number of words in %s is %d \n", file_name, n_words);
    printf("Max length of word is %d (%s) \n", max_word_size, max_word);
    printf("Min length of word is %d (%s) \n", min_word_size, min_word);
    printf("Average length of word is %f \n", average_word_size);

    fclose(file);
    return 0;
}
