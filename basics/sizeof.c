#include <stdio.h>
int main()
{
    int a = 42;

    // %zu is the format specifier for type size_t

    printf("size of int a = 42; is %zu\n bytes",
        sizeof a); // Prints 4 on my system
    printf("size of 2+7; is %zu\n bytes", sizeof(2 + 7)); // Prints 4 on my system
    printf("size of 3.14; is %zu\n bytes", sizeof(3.14)); // Prints 8 on my system

    printf("%d", a);
    // If you need to print out negative size_t values, use %zd
}