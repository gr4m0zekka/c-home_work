

#include <iostream>
void Bob(int n);
void Alice(int n) {
    n *= 3;
    ++n;
    printf("%i\n", n);
    Bob(n);
}
void Bob(int n) {
    while (n % 2 != 1) {
            n /= 2;
            printf("%i\n", n);
        if (n == 1)
        {
            return ;
        }
    }
        Alice(n);
}
int main()
{
    int n;
    scanf_s("%i", &n);
    Alice(n);

}