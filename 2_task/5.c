
#include <iostream>

int main()
{
    int m, n;
    scanf_s("%i %i", &m, &n);
    int a[100][100];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf_s("%i", &a[i][j]);
        }
    }
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            for (int k = 0; k < m - 1; ++k) {
                if (a[k][j] > a[k + 1][j]) {
                    int now = a[k + 1][j];
                    a[k + 1][j] = a[k][j];
                    a[k][j] = now;
                }
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

