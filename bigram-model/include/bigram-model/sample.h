#ifndef SAMPLE_HEADER_H
#define SAMPLE_HEADER_H

// Function to sample an index from an array of probabilities
// probabilities: Pointer to an array of float probabilities (they must sum to
// 1) n: Number of elements in the probabilities array Returns: An integer index
// sampled based on the probabilities
int sample(float* probabilities, int n);

#endif  // SAMPLE_HEADER_H
