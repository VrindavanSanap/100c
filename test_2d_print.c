#include <stdio.h>

int main()
{
    int array[27][27] = {
        0
    };


    // Print the elements of the array
    for (int i = 0; i < 27; i++)
    {
        for (int j = 0; j < 27; j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
