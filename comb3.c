#include <stdio.h>
#include <stdlib.h>

void printCombinations(int n) {
    for (int i = 1; i <= n - 2; ++i) {
        for (int j = i + 1; j <= n - 1; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                if (i + j + k == n) {
                    printf("%d + %d + %d = %d\n", i, j, k, n);
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    printf("Combinations of three natural numbers whose sum is %d:\n", n);
    printCombinations(n);

    return 0;
}

