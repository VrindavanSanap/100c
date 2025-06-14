
#include "tweet.h"
#include <stdio.h>
void print_tweet(const Tweet* tweet)
{
    printf("Author:%s\n", tweet->author);
    printf("Tweet:%s\n", tweet->tweet);
    printf("Likes:%d\n", tweet->likes);
}
