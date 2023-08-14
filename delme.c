#include <stdio.h>

int *createIntArray(int size){
    int *arr = (int *)malloc(size * sizeof(int)); // Allocate memory for the array
    for (int i = 0; i < size; i++)
    {
        arr[i] = i * 2; // Fill the array with some data (just an example)
    }
    return arr; // Return the array
}

int main()
{
    int arraySize = 5;
    int *resultArray = createIntArray(arraySize);

    printf("Array elements: ");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d ", resultArray[i]);
    }

    free(resultArray); // Don't forget to free the allocated memory
    return 0;
}
