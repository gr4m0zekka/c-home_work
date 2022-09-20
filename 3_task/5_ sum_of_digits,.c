

#include <iostream>
int  sum_of_digits(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n = (n - n % 10) / 10;
    }
    return sum;
}
int main()
{
    int n; 
    scanf_s("%i", &n);
    printf("%i", sum_of_digits(n));
}

