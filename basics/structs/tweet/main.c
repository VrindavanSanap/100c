// Written by Vrindavan Sanap
// All rights reserved


#include <stdio.h>
#include <string.h>
#include "tweet.h"



int main(void) {
  Tweet banger;
  snprintf(banger.author, sizeof(banger.author), "Beff Jezoz");
  snprintf(banger.tweet, sizeof(banger.tweet), "A C C L L E R A T E");
  banger.likes=100;
  print_tweet(&banger);
  return 0;
}
