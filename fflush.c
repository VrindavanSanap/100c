#include <stdio.h>

int main() {
    printf("This will be buffered");
    fflush(stdout);   
    return 0;
}

