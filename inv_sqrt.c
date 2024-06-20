#include <stdio.h>
#include <math.h>
/*
  Calculate the square root of 2 
  using newtons method
*/

float inv_sqrt(float number) {
  return 1.0F / sqrtf(number);
}

int main(){

  float guess = 1;
  float x = 2;  
  printf("Expected inv square root of %f is %f \n", x, inv_sqrt(x));

  for (int i = 0;i < 10;i++) {
    guess = ( (guess / 2.0F )  * (3.0F - (x * guess * guess)));
    printf("%f \n", guess);
  }

  return 0;
}
