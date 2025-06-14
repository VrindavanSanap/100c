#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool clear_input_buffer() {
    int c;
    // returns 1 if y is char;
    bool contains_q = false;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (c == 'q') {
            contains_q = true;
        }
    };
    return contains_q;
}

void guess_the_number() {
    printf("Guess the number between 1 and 100 (both inclusive)\n");
    printf("Enter q to quit \n");
    srand(time(0));
    int n = (rand() % 100) + 1;
    int user_input;
    while (true) {
        printf("You guess the number:");
        if (scanf("%d", &user_input) != 1) {
            if (clear_input_buffer()) {
                return;
            };
            printf("Invalid input. Please enter a number.\n");
            continue;
        } else {
            printf("You guessed: %d \n", user_input);
        }
        if (user_input < 1 || user_input > 100) {
            printf("Th number is between 1 and 100 (both inclusive)");
        } else if (user_input > n) {
            printf("The number is LOWER than your guess");
        } else if (user_input < n) {
            printf("The number is HIGHER than your guess");
        } else if (user_input == n) {
            printf("WOW! you guessed correctly %d \n", n);
            return;
        }
        printf("\n");
    }
}

int main() {
    char ch;
    while (true) {
        guess_the_number();
        printf("Play again? (Enter y for yes) \n");
        ch = getchar();
        if (ch == 'y') {
            continue;
        } else {
            break;
        }
    }
    return 0;
}
