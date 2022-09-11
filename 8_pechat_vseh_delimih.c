

#include <iostream>

int main()
{
    int a, b, c, now;
    scanf_s("%i %i %i", &a, &b, &c);
    for (int i = a; i <= b; ++i) {
        if (i % c == 0) {
            now = i;
            break;
        }
    }
    while (now <= b) {
        printf("%i ", now);
        now += now;
    }
    return 0;
}

