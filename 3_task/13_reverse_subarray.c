

#include <iostream>
void reverse_subarray(int a[], int left, int right) {
    for (int i = 0; i < (right - left) / 2; ++i) {
        int now = a[left];
        a[left + i] = a[right - 1 - i];
        a[right - 1 - i] = now;
    }
}
int main()
{
    int n, left, right;
    scanf_s("%i %i %i", &n, &left, &right);
    int a[100];
    for (int i = 0; i < n; ++i) {
        scanf_s("%i", &a[i]);
    }
    reverse_subarray(a, left, right);
    for (int i = 0; i < n; ++i) {
        printf("%i ", a[i]);
    }
}
