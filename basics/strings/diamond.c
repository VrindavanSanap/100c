#include <stdio.h>
#include <string.h>
void diamond(char* s) {
  /*
    prints a string in diamond format
    For example, diamond("DAISY") should print:
    D
    DA
    DAI
    DAIS
    DAISY
     AISY
      ISY
       SY
        Y
  */
  int len = (int)strlen(s);
  char buffer[len + 1];
  for (int i = 1; i < len + 1; i++) {
    strncpy(buffer, s, i);
    buffer[i] = '\0';
    printf("%s\n", buffer);
  }

  for (int i = 0; i < len - 1; i++) {
    buffer[i] = ' ';
    printf("%s\n", buffer);
  }
}
int main() {
  diamond("DAISY");
  return 0;
}
