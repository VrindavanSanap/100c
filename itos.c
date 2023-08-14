#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *itos()
{
    char *itos= (char *)malloc(28 * sizeof(char)); // Allocate memory for 27 characters
    if (itos== NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Fill the array with some data
    strcpy(itos, "abcdefghijklmnopqrstuvwxyz.");
    return itos;
}



