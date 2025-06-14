#include <stdint.h>
#include <stdio.h>

int main()
{
    int n = 10;
    int arr[10];
    for (uint32_t i = 0; i < 10; i++)
    {
        arr[i] = i + 2049;
    }

    FILE* file = fopen("data.bin", "wb");
    if (file == NULL)
    {
        perror("Failed to open file");
        return -1;
    }

    size_t written = fwrite(arr, sizeof(uint32_t), n, file);

    fclose(file);
    if (written == n)
    {
        printf("Written successfully");
    }
    else
    {
        printf("Write failed");
    }

    return 0;
}
