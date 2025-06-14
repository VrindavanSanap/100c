//  basic.c
//  100c
//
//  Created by Vrindavan Sanap on 31/7/23.
//  Copyright © 2023 Vrindavan Sanap. All rights reserved.

//  Basics of pointers

#include <stdio.h>

int main(void) {
    int x = 10;
    int *int_ptr = &x;
    int **ptr_to_ptr = &int_ptr;

    printf("x = %d \n", x);
    printf("Pointer to x = %p \n", int_ptr);
    printf("Pointer to pointer to x = %p \n", ptr_to_ptr);
    printf("Dereferencing pointer pointer = %p \n", *ptr_to_ptr);
    printf("Dereferencing dereferenced pointer pointer = %d \n", **ptr_to_ptr);
    return 0;
}
