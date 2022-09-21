

#include <iostream>
void print_binary(int n) {
    int a;
    if (n != 0) {
        a = n % 2;
        print_binary(n / 2);
        printf("%i", a);
    }
 

}
int main()
{
    int n;
    scanf_s("%i", &n);
    print_binary(n);
}

