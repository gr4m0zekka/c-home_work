

#include <iostream>
#include <stdio.h>
void delete_chars(char* str, char c) {
    for (int i = 0; str[i]; ++i) {
        if (str[i] == c) {
            for (int j = i; str[j]; ++j) {
                str[j] = str[j + 1];
            }
        }
    }
}
int main()
{
    char a[100];
    char c;
    scanf("%c", &c);
    scanf("%s", a);
    delete_chars(a, c);
    for (int i = 0; a[i]; ++i) {
        printf("%c", a[i]);
    }

}

