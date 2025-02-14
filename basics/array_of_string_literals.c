//
//  array_of_string_literals.c
//  100c
//
//  Created by Vrindavan on 3/08/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//

//  This program demonstrates how to use an array of string literals in C.

#include <stdio.h>

int main() {
  // Create an array of strings
  char *names[] = {"Alice", "Bob", "Charlie"};

  // `names` is a char** (a pointer to an array of char*)
  char **p = names;

  // Accessing the strings
  for (int i = 0; i < 3; i++) {
    printf("%s\n", p[i]);
  }

  return 0;
}
