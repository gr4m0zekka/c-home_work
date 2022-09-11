

#include <iostream>

int main()
{
    int a, b, size, max_size = 1, n = 0;
    scanf_s("%i %i", &a, &b);
    for (int i = a; i <= b; ++i) {
        size = 1;
        int k = i;
        while (k != 1) {
            if (k % 2 == 0) {
                k /= 2;
            }
            else if (k % 2 == 1) {
                k = 3 * k + 1;
            }
            ++size;
        }
        if (max_size < size) {
            max_size = size;
            n = i;
        }
    }
    printf("%i %i", n,  max_size);
    return 0;
}

