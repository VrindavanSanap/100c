#include <stdio.h>

int main()
{

    // declaring values
    int x = 42;
    printf("This is the value of x %d\n", x);
    int* xPtr = &x;
    printf("This is the value of xPtr %p\n", xPtr);
    int** xPtrPtr = &xPtr;
    printf("This is the value of xPtrPtr %p\n", xPtrPtr);

    // dereferencing variables

    printf("This is dereferenced value of xPtr %d\n", *xPtr);
    printf("This is single dereferenced value of xPtrPtr %p\n", *xPtrPtr);
    printf("This is single dereferenced value of xPtrPtr %d\n", **xPtrPtr);
}