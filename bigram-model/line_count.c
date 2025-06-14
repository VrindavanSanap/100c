#include <stdio.h>

int line_count(FILE *file) {
    long start_pos = ftell(file);
    char ch;
    int line_count = 0;
    if (file == NULL) {
        printf("Could not open the file.\n");
        return 1;
    }
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            line_count++;
        }
    }
    fseek(file, start_pos, SEEK_SET);
    return line_count;
}
