
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

uint64_t nanos(void) {
    // return given time in nano seconds
    struct timespec ts;

    if (timespec_get(&ts, TIME_UTC) != TIME_UTC) {
        fputs("timespec_get failed!", stderr);
        return 0;
    }
    return 1000000000 * ts.tv_sec + ts.tv_nsec;
}

int main(void) {
    for (int i = 0; i < 10; i++) {

        printf("Current time (nanosec) is %jd \n", nanos());
    }
    return 0;
}
