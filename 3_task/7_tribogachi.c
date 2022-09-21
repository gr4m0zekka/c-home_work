

#include <iostream>
int trichi(int n) {
    int mass[100];
    mass[0] = mass[1] = 0;
    mass[2] = 1;
    for (int i = 3; i <= n; ++i) {
        mass[i] = mass[i - 1] + mass[i - 2] + mass[i - 3];
    }
    return mass[n];
}
int main()
{
    int n;
    scanf_s("%i", &n);
    printf("%i", trichi(n));
}

