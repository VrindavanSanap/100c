#include <stdio.h>

int main() {
    for (int j = 1231; j < 1300; j++) {
        printf("%d ", j);
        for (int i = sizeof(j) * 8 - 1; i >= 0; i--) {
            printf("%d", (j >> i) & 1);
        }
        printf("\n");
    }
}
