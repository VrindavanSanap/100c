#include <stdio.h>

void matmul(float* xout, float* x, float* w, int n, int d) {
    // W (d,n) @ x (n,) -> xout (d,)
    // by far the most amount of time is spent inside this little function
    int i;
    for (i = 0; i < d; i++) {
        float val = 0.0f;
        for (int j = 0; j < n; j++) {
            val += w[i * n + j] * x[j];
        }
        xout[i] = val;
    }
}

int main() {
    // Test the matmul function
    int n = 3; // Number of columns in W and size of x
    int d = 2; // Number of rows in W and size of xout

    float w[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f}; // Sample weight matrix (d x n)
    float x[] = {1.0f, 2.0f, 3.0f}; // Sample input vector (n,)
    float xout[d]; // Output vector (d,)

    matmul(xout, x, w, n, d);

    // Print the result
    printf("Resulting vector xout:\n");
    for (int i = 0; i < d; i++) {
        printf("%.2f ", xout[i]);
    }
    printf("\n");

    return 0;
}

