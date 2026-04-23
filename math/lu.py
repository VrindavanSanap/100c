import numpy as np
import scipy.linalg as la

A = np.array([
[2, 1, -4],
[2, 2, -2],
[6, 3, -11],
])

print(A)
P, L, U = la.lu(A)

print("Permutation Matrix (P):\n", P)
print("Lower Triangular (L):\n", L)
print("Upper Triangular (U):\n", U)

# Verification
print("Verification (P @ L @ U == A):\n", np.allclose(A, P @ L @ U))
