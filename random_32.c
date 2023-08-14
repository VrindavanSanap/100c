#include <stdio.h>

unsigned int random_u32() {
    // xorshift rng: https://en.wikipedia.org/wiki/Xorshift#xorshift.2A
    unsigned long long rng_seed;  
    rng_seed ^= rng_seed >> 12;
    rng_seed ^= rng_seed << 25;
    rng_seed ^= rng_seed >> 27;
    return (rng_seed * 0x2545F4914F6CDD1Dull) >> 32;
}

float random_f32() { // random float32 in [0,1)
    return (random_u32() >> 8) / 16777216.0f;
}

int main(){
    unsigned int u32 = random_u32();
    float f32 = random_f32();
    printf("u32 = %u \n", u32);
    printf("f32 = %f", f32);
   return 0;
}
