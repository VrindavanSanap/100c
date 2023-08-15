#include <stdio.h>
#include "itos.h"
int main()
{
    int N[27][27] = {0}; 
    for (int i = 0; i < 27; i++){
      for (int j = 0; j < 27; j++){
        if (i == 0 || j == 0){
          printf("  (%c%c) ",itos[i], itos[j]);
        }
        else{
          printf(" (699) ");
        }
      }
      printf("\n");
    } 

   return 0;
}
