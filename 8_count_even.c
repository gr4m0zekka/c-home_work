

#include <iostream>
int count_even(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}
int main()
{
    int n;
    int a[100];
    scanf_s("%i", &n);
    for (int i = 0; i < n; ++i) {
        scanf_s("%i", &a[i]);
    }
    printf("%i", count_even(a, n));
}

