#include <bigram-model/random.h>

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
  return n - 1;  // in case of rounding errors
}
