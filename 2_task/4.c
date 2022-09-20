
#include <iostream>

int main()
{
    int m, n;
    scanf_s("%i %i", &m, &n);
    int a[100];
    for (int i = 0; i < m * n; ++i) {
        scanf_s("%i", &a[i]);
    }

    for (int i = 0; i < n; ++i) {
        int k = i;
        int sum = 0;
        while (k < m * n) {
            sum += a[k];
            k += n;
        }
        printf("%i ", sum);
    }

}