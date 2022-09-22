

#include <iostream>
void sort(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int i = 0; i < n; ++i) {
            if (a[i] < a[i + 1]) {
                int now = a[i];
                a[i] = a[i + 1];
                a[i + 1] = now;
            }
        }
    }
}
int main()
{
    int n;
    scanf_s("%i", &n);
    int a[100];
    for (int i = 0; i < n; ++i) {
        scanf_s("%i", &a[i]);
    }
    sort(a, n);
    for (int i = 0; i < n; ++i) {
        printf("%i ", a[i]);
    }
}

