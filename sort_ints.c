//
//  sort_int.c 
//  100c 
//
//  Created by Vrindavan on 3/08/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//


//  Code to sort integer array 



#include <stdlib.h>

int compare_ints(const void *p, const void *q) {
    int x = *(const int *)p;
    int y = *(const int *)q;

    if (x < y)
        return -1;  
    else if (x > y)
        return 1;  

    return 0;
    return (x > y) - (x < y);
}

void sort_ints(int *a, size_t n) {
    qsort(a, n, sizeof(*a), compare_ints);
}

