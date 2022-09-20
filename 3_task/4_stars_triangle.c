

#include <iostream>
void triangle(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            printf("*");
        }
        printf("\n");
    }
}
int main()
{
    int n; 
    scanf_s("%i", &n);
    triangle(n);
}

