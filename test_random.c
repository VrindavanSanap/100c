//
//  argmax.c 
//  100c 
//
//  Created by Vrindavan sanap on 7/13/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//


// Code defines a function argmax that returns the index of max value in a float array

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"

int main(int argc, char *argv[]) {
    srand(time(NULL));
    float f;
    unsigned int ui;
    ui = random_u32(); 
    f = random_f32();
    printf("%u %f", ui, f);
    return 0;
}


