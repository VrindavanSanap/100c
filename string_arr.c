//
//  string_arr.c 
//  100c 
//
//  Created by Vrindavan sanap on 7/13/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//


//  Creating and using a string array 

#include <stdio.h>
void print_fruits(char *names[]){
  for(int i = 0; i<5; i++){
    printf("%d %s \n", i, names[i]);
  }
}
int main(int argc, char *argv[]) {
    
  char *fruits[] = {"Apple", "Banana", "Orange", "Grapes", "Mango"};
  print_fruits(fruits);
  return 0;
}


