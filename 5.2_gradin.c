

#include <iostream>
#include <limits.h>

int main()
{
    int n, size = 1, max;
    scanf_s("%i", &n);
    printf("%i ", n);
    max = n;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        }
        else if (n % 2 == 1) {
            n = 3 * n + 1;
        }
        if (n > max) {
            max = n;
        }
        ++size;
        printf("%i ", n);
    }
    printf("\n");
    printf("Length = %i, Max = %i", size, max);
    return 0;
}

