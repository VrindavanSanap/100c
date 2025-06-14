#include <stdio.h>

int main() {
    char msg[] = "Hello";

    // returns size of msg in bytes
    int msg_size = sizeof(msg);
    printf("Size of msg: %s is %d bytes", msg, msg_size);

    return 0;
}
