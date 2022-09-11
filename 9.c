

#include <iostream>

int gcd(int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        }
        else {
            b = b % a;
        }
    }
    return (a + b);
}
int main()
{
    int n, k = 0;
    bool flag = true;
    int now[20];
    scanf_s("%i", &n);
    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= n; ++b) {
            for (int c = 1; c <= n; ++c) {
                if (a * a + b * b == c * c && gcd(a, b) == 1) {
                    for (int i = 0; i < k; ++i) {
                        if (c == now[i]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        now[k] = c;
                        ++k;
                        printf("%i %i %i\n ", a, b, c);
                    }
                    flag = true;
                }
            }
        }
    }
return 0;
}
