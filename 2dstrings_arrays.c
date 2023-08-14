#include <stdio.h>
#include <string.h> // Include this header for string manipulation functions

#define MAX_STRING_LENGTH 100
#define MAX_LINES 10 // Adjust this as needed

void processStrings(char strings[][MAX_STRING_LENGTH], int n_lines)
{
    for (int i = 0; i < n_lines; ++i)
    {
        printf("Line %d: %s\n", i + 1, strings[i]);
    }
}

int main()
{
    char strings[MAX_LINES][MAX_STRING_LENGTH];
    int n_lines;

    printf("Enter the number of lines: ");
    scanf("%d", &n_lines);
    while (getchar() != '\n'); // Clear the input buffer


    processStrings(strings, n_lines);

    return 0;
}
