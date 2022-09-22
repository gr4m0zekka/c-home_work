

#include <iostream>
int fact(int n) {
    int fact = 1;
    if (n) {
        for (int i = 1; i <= n; ++i) {
            fact *= i;
        }
    }
    else {
        return 1;
    }
    return fact;
}
void factorial(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        a[i] = fact(a[i]);
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
    factorial(a, n);
    for (int i = 0; i < n; ++i) {
        printf("%i ", a[i]);
    }
}
