/*
 * Created by Vrindavan Sanap
 * lu_decomposition.c
 * Goal:
 *   To find LU decomposition of every 3x3 matrix A
 *   Given that A has non-zero leading principal minors.
 *   We are purposely solving a specific version of the general problem
 *   so as to grok the concepts so that we can later generalize this concept
 * over to n-dimensional matrices and matrices which require a permutation
 * matrix to be decomposed into LU.
 */

#include <stdio.h>
#include <string.h>
void row_elemination(float A[3][3], int start_i, int end_i, int multiplier) {
  // A[row start_i] = A[row start_ i] - A[row end_i] * multipler
  for (int i = 0; i < 3; i++) {
    A[start_i][i] = A[start_i][i] - multiplier * A[end_i][i];
  }
}
void decompose_3x3(const float A[3][3], float L[3][3], float U[3][3]) {
  // preserve A
  memcpy(U, A, sizeof(float) * 3 * 3);

  // Logic to populate L and U
  float l21;
  float l31;
  float l32;

  // Start with identity matrices
  memset(L, 0, sizeof(float) * 3 * 3);
  for (int i = 0; i < 3; i++) {
    L[i][i] = 1;
  }

  l21 = U[1][0] / U[0][0];
  L[1][0] = l21;
  row_elemination(U, 1, 0, l21);

  l31 = U[2][0] / U[0][0];
  L[2][0] = l31;
  row_elemination(U, 2, 0, l31);

  l32 = U[2][1] / U[1][1];
  L[2][1] = l32;
  row_elemination(U, 2, 1, l32);
}

void print_matrix(float matrix[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%.1f ", matrix[i][j]);
    }
    printf("\n");
  }
}
int main() {
  float A[3][3] = {{2, 1, -4}, {2, 2, -2}, {6, 3, -11}};

  float L[3][3], U[3][3];

  /*
   * Expected Result (LU Decomposition):
   * [ 2  1  -4 ]   [ 1  0  0 ]   [ 2  1  -4 ]
   * [ 2  2  -2 ] = [ 1  1  0 ] * [ 0  1   2 ]
   * [ 6  3 -11 ]   [ 3  0  1 ]   [ 0  0   1 ]
   * (A)            (L)           (U)
   */

  decompose_3x3(A, L, U);

  printf("A:\n");
  print_matrix(A);
  printf("L:\n");
  print_matrix(L);
  printf("U:\n");
  print_matrix(U);

  return 0;
}