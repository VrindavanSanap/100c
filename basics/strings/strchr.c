#include <stdio.h>
#include <string.h>

int main() {
    const char *str = "Hello, world!";
    int dff  = strchr(str, 'd') - str;
    printf("index of 'o'in  %s is %d", str, dff);
    return 0;
}

