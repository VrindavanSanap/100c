#include <stdio.h>

#define PI 3.14159
#define SQUARE(x) (x * x)

int main()
{
    int s = 7;
    int s_sq = SQUARE(s);
    printf("%d", s_sq);
}
