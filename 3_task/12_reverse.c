

#include <iostream>
void reverse(int a[], int n) {
    for (int i = 0; i < n / 2; ++i) {
        int now = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = now;
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
    reverse(a, n);
    for (int i = 0; i < n; ++i) {
        printf("%i ", a[i]);
    }
}

