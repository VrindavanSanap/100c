#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* allocateString(int len) {
    char* allocatedString = (char*)malloc(len* sizeof(char));

    if (allocatedString != NULL) {
        memset(allocatedString, 'a', len - 1);
        allocatedString[len- 1] = '\0'; // Null-terminate the string
    }

    return allocatedString;
}

int main(){
  char* s = allocateString(5);
  printf("%s", s);

}
