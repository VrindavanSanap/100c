#ifndef TWEET_H
#define TWEET_H

typedef struct {
  char author[25];
  char tweet[100];
  int likes;
} Tweet;

void print_tweet(const Tweet* tweet);

#endif
