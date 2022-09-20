

#include <iostream>
int sum(int n) {
    int k = 10;
    int sum = 0;
    while (n > 0) {
        sum += (n % k) / (k / 10);
        n -= n % k;
    }
    return sum;
}
int main()
{
    int n = 10;
    int mass[10005];
    for (int i = 0; i < n; ++i) {
        scanf_s("%i", &mass[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (sum(mass[i]) > sum(mass[i + 1])) {
                int now = mass[i + 1];
                mass[i + 1] = mass[i];
                mass[i] = now;
            }
        }
   }
    for (int i = 0; i < n; ++i) {
        printf("%i ", mass[i]);
    }
}

