#include <stdio.h>
#include <string.h>
#include <unistd.h> // For usleep()

const char* rainbow[8] = { "\033[31m", "\033[91m", "\033[33m", "\033[32m", "\033[34m", "\033[36m",
    "\033[35m", "\033[0m" };

void rainbow_print(const char* str, int offset)
{
    const char* colors[] = {
        "\033[91m", // Bright Red (used for Red and Orange)
        "\033[91m", // Bright Red (Orange)
        "\033[93m", // Bright Yellow
        "\033[92m", // Bright Green
        "\033[94m", // Bright Blue
        "\033[96m", // Bright Cyan (Indigo)
        "\033[95m" // Bright Magenta (Violet)
    };

    const char* reset = "\033[0m";
    int n_colors = sizeof(colors) / sizeof(colors[0]);

    for (int i = 0; i < strlen(str); i++)
    {
        printf("%s%c", colors[(i + offset) % n_colors], str[i]);
    }
    printf("%s\n", reset);
}
int main()
{
    const char* str = "Hello world";
    int i = 0;
    while (i < 100)
    {
        rainbow_print(str, i++);
        usleep(200000);
    }
    return 0;
}
