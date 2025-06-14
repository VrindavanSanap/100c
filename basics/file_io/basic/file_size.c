//
//  file_size.c
//  100c
//
//  Created by Vrindavan on 3/08/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//

//  Function to calculate size of file

#include <stdio.h>

long file_size(FILE *fp) {
    if (fp == NULL) {
        printf("File Not Found!\n");
        return -1;
    }
    fseek(fp, 0L, SEEK_END);
    long int res = ftell(fp);
    fclose(fp);

    return res;
}
