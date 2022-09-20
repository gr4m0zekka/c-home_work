#include <iostream>

int main()
{
    int n;
    int f_matrix[20][20];
    int s_matrix[20][20];
    scanf_s("%i", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf_s("%i", &f_matrix[i][j]);
        }
    }
    int n_1;
    scanf_s("%i", &n_1);
    for (int i = 0; i < n_1; ++i) {
        for (int j = 0; j < n_1; ++j) {
            scanf_s("%i", &s_matrix[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int sum = 0;
            for (int k = 0; k < n; ++k) {
                sum += f_matrix[i][k] * s_matrix[k][j];
            }
            printf("%i ", sum);
        }
        printf("\n");
    }
}
