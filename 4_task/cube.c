

#include <iostream>
#include <math.h>
float cube(float* p) {
    return pow(*p, 3);
}
int main()
{
    float a;
    scanf_s("%f", &a);
    float* p = &a;
    printf("%f", cube(p));
}

