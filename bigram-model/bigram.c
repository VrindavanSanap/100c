#include "dict.h"
#include "line_count.h"
#include "plot_N.h"
#include "print_arr.h"
#include "prob_dist.h"
#include "sample.h"
#include "stoi.h"
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>  // macOS prefers string.h

#define MAX_STRING_LENGTH 100

void min_max(const char words[][MAX_STRING_LENGTH], int n_words, int *min_ptr,
             int *max_ptr) {
  int max = 0;
  int min = 999;
  int length;
  for (int i = 0; i < n_words; i++) {
    length = strlen(words[i]);
    if (max < length) {
      max = length;
    }
    if (min > length) {
      min = length;
    }
  }
  *min_ptr = min;
  *max_ptr = max;
}

void read_strings(FILE *file, char strings[][MAX_STRING_LENGTH], int n_words) {
  int i = 0;
  while (i < n_words && fgets(strings[i], MAX_STRING_LENGTH, file)) {
    int length = strlen(strings[i]);
    if (length > 0 && strings[i][length - 1] == '\n') {
      strings[i][length - 1] = '\0';
    }
    i++;
  }
}

int main(int argc, char *argv[]) {
  srand(time(NULL));
  char *file_name = "./names.txt";
  if (argc == 2) {
    file_name = argv[1];
  }

  FILE *file = fopen(file_name, "r");
  if (file == NULL) {
    perror("Error opening file");
    return 1;
  }

  int n_words = line_count(file);
  printf("n-words = %d \n\n", n_words);

  char words[n_words][MAX_STRING_LENGTH];
  read_strings(file, words, n_words);
  fclose(file);

  int min, max;
  min_max(words, n_words, &min, &max);
  printf("min_l = %d \nmax_l = %d \n\n", min, max);

  // Calculate bigram frequency matrix
  Dictionary dict = stoi();
  char word[MAX_STRING_LENGTH];
  int N[27][27] = {0};
  for (int i = 0; i < n_words; i++) {
    char chs[strlen(words[i]) + 3];
    chs[0] = '.';
    strcpy(chs + 1, words[i]);
    chs[strlen(words[i]) + 1] = '.';
    chs[strlen(words[i]) + 2] = '\0';

    for (int j = 0; j < strlen(chs) - 1; j++) {
      char ch1[2];
      char ch2[2];
      ch1[0] = chs[j];
      ch1[1] = '\0';
      ch2[0] = chs[j + 1];
      ch2[1] = '\0';

      int ix1 = get_value_by_key(&dict, ch1);
      int ix2 = get_value_by_key(&dict, ch2);
      N[ix1][ix2]++;
    }
  }

  // Calculate probability matrix
  float p[27][27];
  for (int i = 0; i < 27; i++) {
    for (int j = 0; j < 27; j++) {
      p[i][j] = (float)N[i][j];
    }
    prob_dist(p[i], 27);
  }

  // Sample from the model
  for (int i = 0; i < 10; i++) {
    int ix = 0;
    while (1) {
      ix = sample(p[ix], 27);
      if (ix == 0) {
        break;
      }
      printf("%c", itos[ix]);
    }
    printf("\n");
  }

  // Calculate probablity matrix loss
  printf("\n");
  float log_likelihood = 0.0;
  int n = 0;
  for (int i = 0; i < n_words; i++) {
    char chs[strlen(words[i]) + 3];
    chs[0] = '.';
    strcpy(chs + 1, words[i]);
    chs[strlen(words[i]) + 1] = '.';
    chs[strlen(words[i]) + 2] = '\0';
    for (int j = 0; j < strlen(chs) - 1; j++) {
      char ch1[2];
      char ch2[2];
      ch1[0] = chs[j];
      ch1[1] = '\0';
      ch2[0] = chs[j + 1];
      ch2[1] = '\0';

      int ix1 = get_value_by_key(&dict, ch1);
      int ix2 = get_value_by_key(&dict, ch2);
      float prob = p[ix1][ix2];
      float logprob = log(prob);

      log_likelihood += logprob;
      n += 1;
    }
  }
  printf("log_likelihood %.2f \n", log_likelihood);
  printf("loss %.2f", -log_likelihood / (float)n);
  return 0;
}
