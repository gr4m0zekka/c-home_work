﻿

#include <iostream>
#define MAX 100

void assign(int A[MAX][MAX], int B[MAX][MAX], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = B[i][j];
        }
    }
}
int main()
{
    int n;
    scanf_s("%i", &n);
    int B[MAX][MAX];
    int A[MAX][MAX];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf_s("%i", &B[i][j]);
        }
    }
    assign(A, B, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%i", A[i][j]);
        }
    }
}

