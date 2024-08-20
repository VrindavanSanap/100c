#include <stdio.h>

int main() {
    // Create an array of strings
    char* names[] = {"Alice", "Bob", "Charlie"};

    // `names` is a char** (a pointer to an array of char*)
    char** p = names;

    // Accessing the strings
    for (int i = 0; i < 3; i++) {
        printf("%s\n", p[i]);
    }

    return 0;
}

