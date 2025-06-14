#include <stdio.h>
#include <string.h>

int main() {
    char *words[] = {"example", "translation", "code"};
    int num_words = sizeof(words) / sizeof(words[0]);

    for (int i = 0; i < num_words; i++) {
        char chs[strlen(words[i]) + 3];
        chs[0] = '.';
        strcpy(chs + 1, words[i]);
        chs[strlen(words[i]) + 1] = '.';
        chs[strlen(words[i]) + 2] = '\0';

        for (int j = 0; j < strlen(chs) - 1; j++) {
            char ch1[2];
            char ch2[2];
            ch1[0] = chs[j];
            ch1[1] = '\0';
            ch2[0] = chs[j + 1];
            ch2[1] = '\0';
            printf("ch1: %s, ch2: %s\n", ch1, ch2);
        }
    }

    return 0;
}
