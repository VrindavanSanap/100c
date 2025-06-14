//
//  boilerplate.c
//  bp
//
//  Created by Vrindavan sanap on 7/13/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//

//  Code will be used as boiler plate

#include "itos.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 0; i < 27; i++) {
        printf("%d %c \n", i, itos[i]);
    }
}
