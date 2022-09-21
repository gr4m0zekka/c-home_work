

#include <iostream>
void dec(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        a[i] -= 1;
    }
}
int main()
    {
        int n;
        scanf_s("%i", &n);
        int a[50];
        for (int i = 0; i < n; ++i) {
            scanf_s("%i", &a[i]);
        }
        dec(a, n);
        for (int i = 0; i < n; ++i) {
            printf("%i ", a[i]);
        }
    }


