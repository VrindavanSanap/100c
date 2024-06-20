#include "cJSON.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int *rand_permut() {
  int *array = (int *)malloc(4 * sizeof(int));
  if (array == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  for (int i = 0; i < 4; i++) {
    array[i] = i;
  }

  srand(time(0));

  for (int i = 3; i > 0; i--) {
    int j = rand() % (i + 1);
    swap(&array[i], &array[j]);
  }

  return array;
}

#define CHUNK_SIZE 1024
int main() {
  FILE *fp = fopen("test.json", "r");
  if (fp == NULL) {
    printf("Failed to open JSON file. \n");
    return 1;
  }
  char buffer[CHUNK_SIZE];
  char *file_contents = NULL;
  size_t content_size = 0;
  size_t bytes_read;
  while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
    char *old_contents = file_contents;
    file_contents = realloc(file_contents, content_size + bytes_read + 1);
    if (file_contents == NULL) {
      fprintf(stderr, "Memory allocation failed!! \n");
      free(old_contents);
      fclose(fp);
      return 1;
    }
    memcpy(file_contents + content_size, buffer, bytes_read);
    content_size += bytes_read;
    file_contents[content_size] = '\0';
  }

  cJSON *root = cJSON_Parse(file_contents);
  char *welcome_str = "Welome to Medi-Quiz!!, You will be asked 10 single "
                      "correct mcq questions and will be given score out of 10 "
                      "in the end. \n \n Press Q to quit ******** \n \n";

  printf("%s", welcome_str);
  int total_questions = 5;
  int score = 0;
  for (int i = 0; i < total_questions; i++) {
    int qn = rand() % (1000);

    cJSON *question_obj = cJSON_GetArrayItem(root, qn);
    char *question =
        cJSON_GetObjectItemCaseSensitive(question_obj, "question")->valuestring;
    char *distractor1 =
        cJSON_GetObjectItemCaseSensitive(question_obj, "distractor1")
            ->valuestring;
    char *distractor2 =
        cJSON_GetObjectItemCaseSensitive(question_obj, "distractor2")
            ->valuestring;
    char *distractor3 =
        cJSON_GetObjectItemCaseSensitive(question_obj, "distractor3")
            ->valuestring;
    char *correct_answer =
        cJSON_GetObjectItemCaseSensitive(question_obj, "correct_answer")
            ->valuestring;
    char *support =
        cJSON_GetObjectItemCaseSensitive(question_obj, "support")
            ->valuestring;
 
    printf("Q-%d) %s \n", i + 1, question);
    int* permutation = rand_permut();
    int correct_opt = 0;
    char option [5] = {'A', 'B', 'C', 'D' ,'\0'};

    for (int i = 0 ;i< 4;i++){

      if (permutation[i] == 0){
        printf("%c) %s \n",option[i], correct_answer);
        correct_opt = i;
      }

      if (permutation[i] == 1){
        printf("%c) %s \n",option[i], distractor1);
      }

      if (permutation[i] == 2){
        printf("%c) %s \n",option[i], distractor2);
      }

      if (permutation[i] == 3){
        printf("%c) %s \n",option[i], distractor3);
      }
    }
    bool proper_ans = false;
    char ui;
    int v = 0;
    while(!proper_ans){
      scanf(" %c", &ui);  
      while (getchar() != '\n');  
      ui = tolower(ui);  
     v = ui - 'a';
      if (v >=0 && v< 4){
        proper_ans=  true;
      }else if (v == 16){
        printf("Your pressed Q so quiting.\n");
        exit(0);

      }else{

        printf("Please enter choice correctly \n");
      }
    }
    printf("You choose %c \n", toupper(ui));
    printf("The correct option is %c \n", option[correct_opt]);
 
    if (v == correct_opt){
      printf("Correct Opt YAY!! \n \n");
      score++;
    }else{
      printf("Wrong answer ;( \n \n");
      printf("Reasoning: %s \n", support);
    }
    printf("********* \n \n");
  }

  printf("You scored %d out of %d", score, total_questions);
  fclose(fp);
  return 0;
}
