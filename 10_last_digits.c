

#include <iostream>
void last_digits(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        a[i] = a[i] % 10;
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
    last_digits(a, n);
    for (int i = 0; i < n; ++i) {
        printf("%i ", a[i]);
    }
}

