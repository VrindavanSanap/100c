#include <stdio.h>

unsigned long long rng_seed = 123456789; // Initialize the rng_seed with a non-zero value
unsigned int random_u32() {
    // xorshift rng: https://en.wikipedia.org/wiki/Xorshift#xorshift.2A
    rng_seed ^= rng_seed >> 12;
    rng_seed ^= rng_seed << 25;
    rng_seed ^= rng_seed >> 27;
    return (rng_seed * 0x2545F4914F6CDD1Dull) >> 32;
}
float random_f32() { // random float32 in [0,1)
    return (random_u32() >> 8) / 16777216.0f;
}
int sample(float *probabilities, int n) {
    // sample index from probabilities (they must sum to 1!)
    float r = random_f32();
    float cdf = 0.0f;
    for (int i = 0; i < n; i++) {
        cdf += probabilities[i];
        if (r < cdf) {
            return i;
        }
    }
    return n - 1; // in case of rounding errors
}
void print_array(int *a, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d %d \n", i, a[i]);
    }
}
int main() {
    float probs[] = {0.1f, 0.35f, 0.55f};
    int s = 0;
    int a[3] = {0};
    for (int i = 0; i < 100; i++) {
        s = sample(probs, 3);
        a[s] += 1;
        printf("%d ", s);
    }
    printf("\n");
    print_array(a, 3);
    return 0;
}
