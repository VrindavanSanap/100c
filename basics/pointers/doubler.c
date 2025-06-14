#include <stdio.h>

void doubler(int *x) { *x *= 2; }

int main() {

    int x = 10;

    printf("before x = %d \n", x);
    doubler(&x);
    printf("after x = %d \n", x);

    return 0;
}
