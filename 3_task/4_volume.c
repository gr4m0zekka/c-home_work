

#include <iostream>
#include <math.h>
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
float volume(int n) {
    if (n % 2) {
        return 2 * fact((n - 1) / 2) * pow(4 * 3.1415926, (n - 1) / 2) / fact(n);
    }
    else {
        return pow(3.1415926, n / 2) / fact(n / 2);
    }
}
int main()
{
    int n;
    scanf_s("%i", &n);
    printf("%f", pow(2, n) / volume(n));
}

