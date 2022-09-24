

#include <iostream>
#define MAX 20

void multiply(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int n) {
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            int now = 0;
            for (int j = 0; j < n; ++j) {
                now += A[i][j] * B[j][k];
            }
            C[i][k] = now;
        }
    }
}
int main()
{
    int n;
    scanf_s("%i", &n);
    float A[MAX][MAX];
    float B[MAX][MAX];
    float C[MAX][MAX];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf_s("%f", &A[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf_s("%f", &B[i][j]);
        }
    }
    multiply(A, B, C, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%.0f ", C[i][j]);
        }
        printf("\n");
    }
}

