#include <arm_neon.h> // Include the NEON header
#include <stdio.h>

// Function to add two arrays using NEON
void add_float_neon(float *a, float *b, float *result, int n) {
  int i;
  for (i = 0; i < n; i += 4) { // Process 4 floats at a time
    // Load data from the arrays into NEON registers
    float32x4_t va = vld1q_f32(&a[i]); // Load 4 floats from array a
    float32x4_t vb = vld1q_f32(&b[i]); // Load 4 floats from array b

    // Perform the addition of two NEON registers
    float32x4_t vresult = vaddq_f32(va, vb); // Add them together

    // Store the result back to the result array
    vst1q_f32(&result[i], vresult); // Store 4 floats into result
  }
}

int main() {
  // Sample arrays
  float a[8] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
  float b[8] = {8.0, 7.0, 6.0, 5.0, 4.0, 3.0, 2.0, 1.0};
  float result[8];

  // Call the NEON add function
  add_float_neon(a, b, result, 8);

  // Print the results
  for (int i = 0; i < 8; i++) {
    printf("result[%d] = %f\n", i, result[i]);
  }

  return 0;
}
