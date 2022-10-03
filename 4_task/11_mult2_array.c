

#include <iostream>
void mult2_array(int* p, size_t n) {
    for (int i = 0; i < n; ++i) {
        *p *= 2;
        ++p;
    }
}
int main()
{
    int a[15];
    size_t n = 10;
    for (size_t i = 0; i < n; ++i) {
        a[i] = i;
    }
    int* p = &a[0];
    mult2_array(p, n);
    for (size_t i = 0; i < n; ++i) {
        printf("%i ", a[i]);
    }
}

