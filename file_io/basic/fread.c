#include <stdio.h>

int main()
{
    // buffer to store data
    char buffer[33];
    int count;
    // FILE object
    FILE *stream;
    stream = fopen("quote.txt", "r"); // opening a file in read mode
    count = fread(&buffer, sizeof(char), 10, stream);
    printf("Data read from the file: %s \n", buffer);
    printf("Number of elements read: %d \n", count);

    count = fread(&buffer, sizeof(char), 10, stream);
    printf("Data read from the file: %s \n", buffer);
    printf("Number of elements read: %d \n", count);
    fclose(stream);

    return 0;
}
