#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print_str(const char* s){
  int l = (int)strlen(s);
  printf("[");
  for (int i = 0; i < l; i++){
    printf("%d ", s[i]);
  }
  printf("] ");
}


char* encrypt(const char* data,const char* key){
  int data_size = (int)strlen(data);  
  int key_size = (int)strlen(key);  
  char* enc= (char*)malloc((data_size + 1) * sizeof(char));
  for (int i = 0; i < data_size; i++){
    char data_i = data[i] ;
    char key_i = key[i%key_size];
    char xor_i = data_i ^ key_i;
    printf("%c, %c, %d \n", data_i, key_i, xor_i);
    enc[i] = xor_i;
  } 
  enc[data_size] = '\0';
  return enc;
}
int main(void){
  const char* data = "qwertyuiopasdfghjklzxcvbnm";
  const char* key = "Doge";
  const char* enc = encrypt(data, key);
  const char* enc_enc = encrypt(enc, key);
  printf("%s", enc_enc);
  return 0;
}


