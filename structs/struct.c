// Written by Vrindavan Sanap
// All rights reserved


#include <stdio.h>
#include <string.h>

typedef struct  {
  char author[25];
  char tweet[100];
  int likes;
  int replyLikes[10];
}Tweet;

void printTweet( Tweet tweet){
  printf("Author:%s\n",tweet.author);
  printf("Tweet:%s\n",tweet.tweet);
  printf("Likes:%d\n", tweet.likes);
        
}

int main(void) {
  Tweet banger;
  strcpy(banger.author, "Beff Jezoz");
  strcpy(banger.tweet, "A C C L L E R A T E");
  banger.likes=100;
  printTweet(banger);
  return 0;
}
