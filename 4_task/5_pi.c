

#include <iostream>
#include <cmath>
float pi(int n) {
    float pi = 0;
    for (int i = 1; i <= n; ++i) {
        pi += 4 * pow(-1, i + 1) / (2 * i - 1);
    }
    return pi;
}
int main()
{
    int n;
    scanf_s("%i", &n);
    printf("%f", pi(n));
}

