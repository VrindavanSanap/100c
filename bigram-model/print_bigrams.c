#include <stdio.h>
#include <string.h>

void print_bigrams(const char *word) {
    int length = strlen(word);
    for (int i = 0; i < length - 1; i++) {
        printf("%c%c\n", word[i], word[i + 1]);
    }
}

int main() {
  char word[100];
  strcpy(word, "harambe");
  print_bigrams(word);

  return 0;
}

