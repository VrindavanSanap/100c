#include "print_arr.h"
#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *p, const void *q) {
    int num1 = *(const int *)p;
    int num2 = *(const int *)q;
    return num1 - num2;
}

int main() {
    int arr[] = {3, 7, 1, 9, 5, 2, 8, 4, 10, 6};
    qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), compare_ints);
    print_int_arr(arr, 10);
    return 0;
}
