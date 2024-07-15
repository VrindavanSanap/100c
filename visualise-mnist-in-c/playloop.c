#include <stdio.h>

int main() {
    char ch;
    int c;

    while (1) {:wq

        printf("Enter a character: ");
        scanf(" %c", &ch);  // Note the space before %c to skip whitespace characters

        // Flush remaining characters from input buffer
        while ((c = getchar()) != '\n' && c != EOF);

        // Now you have `ch` with the valid character entered
        printf("You entered: %c\n", ch);

        // Add your play loop conditions or exit conditions here
        // Example: break; to exit the loop
    }

    return 0;
}

