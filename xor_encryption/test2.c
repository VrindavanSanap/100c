#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_string_of_size(int size) {
    // Allocate memory for the string
    char* str = (char*)malloc((size + 1) * sizeof(char));

    if (str == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Fill the string with some data
    memset(str, 'A', size);
    str[size] = '\0'; // Null-terminate the string

    return str;
}

int main() {
    int desiredSize = 10;
    char* result = get_string_of_size(desiredSize);

    if (result != NULL) {
        printf("String of size %d: %s\n", desiredSize, result);
        free(result); // Don't forget to free the allocated memory!
    }

    return 0;
}

