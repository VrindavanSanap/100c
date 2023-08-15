//
//  test_stoi.c
//  100c 
//
//  Created by Vrindavan sanap on 7/13/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//

//  Testing stoi.c (strings to integer)  
//  To be used in bigram model

#include <stdio.h>
#include "stoi.h"
#include "dict.h"
int main(int argc, char *argv[]){
    Dictionary dict = stoi();
    print_all(&dict);
    return 0;
}
