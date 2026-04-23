import numpy as np

# Define the Lower triangular matrix L
L = np.array([
    [1, 0, 0],
    [1, 1, 0],
    [3, 0, 1]
])

# Define the Upper triangular matrix U
U = np.array([
    [2, 1, -4],
    [0, 1, 2],
    [0, 0, 1]
])

# Define the original matrix A for comparison
A_original = np.array([
    [2, 1, -4],
    [2, 2, -2],
    [6, 3, -11]
])

# Perform matrix multiplication LU
A_computed = L @ U

print("Computed LU:")
print(A_computed)

# Verify if the computed matrix matches the original
matches = np.allclose(A_computed, A_original)
print(f"\nDoes LU equal A? {matches}")
