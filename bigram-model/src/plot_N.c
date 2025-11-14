#include <bigram-model/itos.h>
#include <stdio.h>
void plot_N(int N[27][27]) {
  for (int i = 0; i < 28; i++) {    // y coord
    for (int j = 0; j < 28; j++) {  // x coord
      if (i == 0 || j == 0) {
        if (j == 0 && i == 0) {
          printf("(    )");
        }
        if (i != 0) {
          printf("(%c  _)", itos[i - 1]);
        }
        if (j != 0) {
          printf("(_  %c)", itos[j - 1]);
        }
      } else {
        printf("(%4d)", N[i - 1][j - 1]);
      }
    }
    printf("\n");
  }
}
void plot_p(float p[27][27]) {
  for (int i = 0; i < 28; i++) {    // y coord
    for (int j = 0; j < 28; j++) {  // x coord
      if (i == 0 || j == 0) {
        if (j == 0 && i == 0) {
          printf("(    )");
        }
        if (i != 0) {
          printf("(%c  _)", itos[i - 1]);
        }
        if (j != 0) {
          printf("(_  %c)", itos[j - 1]);
        }
      } else {
        printf("(%.2f)", p[i - 1][j - 1]);
      }
    }
    printf("\n");
  }
}
