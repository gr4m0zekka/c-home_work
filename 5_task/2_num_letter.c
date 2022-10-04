

#include <iostream>

int main()
{
    char n;
    scanf_s("%c", &n);
    if ('a' <= n && n <= 'z') {
        printf("%hhi", n - 'a' + 1);
    }
    else if ('A' <= n && n <= 'Z') {
        printf("%hhi", n - 'A' + 1);
    }
    else {
        printf("Not a letter");
    }
}
