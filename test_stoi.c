//
//  boilerplate.c
//  bp
//
//  Created by Vrindavan sanap on 7/13/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//

//  Code will be used as boiler plate

#include <stdio.h>
#include "stoi.h"
#include "dict.h"
int main(int argc, char *argv[])
{
    Dictionary dict = stoi();
    print_all(&dict);
    return 0;
}
