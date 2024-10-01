#include <stdio.h>


int main(){
  char input[100]; // Array to store the input
  char* welcome_msg = "Basic Calc!!\n";
  char* input_format = "Expected input format <number1> <op> <number2>\n";
  char* wrong_format = "Wrong input format \n";
  char* input_msg = "input:";
  printf("%s", welcome_msg);
  printf("%s", input_format);
  printf("%s", input_msg);
  fgets(input, sizeof(input), stdin); 
  printf("You entered: %s", input);
  return 0;
}
