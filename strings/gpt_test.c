#include <stdio.h>
#include <string.h>

int main() {
  char str[7]; // Array of size 7 to hold 6 characters plus null terminator

  // Fill the first 3 characters with spaces
  memset(str, ' ', 3);
  str[3] = '\0'; // Null-terminate after the spaces

  // Append the rest of the characters using strcat
  strcat(str, "abc");

  // Print the string to verify
  printf("'%s'\n", str);

  return 0;
}
