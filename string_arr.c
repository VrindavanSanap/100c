//
//  boilerplate.c 
//  bp 
//
//  Created by Vrindavan sanap on 7/13/23.
//  Copyright © 2023 Vrindavan. All rights reserved.
//


//  Code will be used as boiler plate  

#include <stdio.h>
void print_names(char *names[]){
  for(int i = 0; i<5; i++){
    printf("%d %s \n", i, names[i]);
  }
}
int main(int argc, char *argv[]) {
    
  char *fruits[] = {"Apple", "Banana", "Orange", "Grapes", "Mango"};
  print_names(fruits);
  return 0;
}


