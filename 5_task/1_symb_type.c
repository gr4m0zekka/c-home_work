

#include <iostream>

int main()
{
    char n;
    scanf_s("%c", &n);
    if ('a' <= n && n <= 'z') {
        printf("Lowercase Letter");
    }
    else if ('A' <= n && n <= 'Z') {
        printf("Uppercase Letter");
    }
    else if ('0' <= n && n <= '9') {
        printf("Digit");
    }
    else {
        printf("Other");
    }
}