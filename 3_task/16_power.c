

#include <iostream>
#define MAX 20
void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            float now = 0;
            for (int j = 0; j < n; ++j) {
                now += A[i][j] * B[j][k];
            }
            C[i][k] = now;
        }
    }
}
void assign(int A[MAX][MAX], int B[MAX][MAX], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = B[i][j];
        }
    }
}
void  power(int A[MAX][MAX], int C[MAX][MAX], int n, int k) {
    int B[MAX][MAX];
    assign(B, A, n);
    for (int i = 0; i < k - 1; ++i) {
        multiply(A, B, C, n);
        assign(A, C, n);
    }
}
int main()
{
    int n, k;
    scanf_s("%i %i", &n, &k);
    int C[MAX][MAX];
    int A[MAX][MAX];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf_s("%i", &A[i][j]);
        }
    }
    power(A, C, n, k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%i ",C[i][j]);
        }
        printf("\n");
    }
}

