

#include <stdio.h>
int len_search(char a[]) {
    int calc = 0;
    for (int i = 0; a[i]; ++i) {
        calc++;
    }
    return calc;
}
int is_palindrom(char a[]) {
    for (int i = 0; a[i]; ++i) {
        if (a[i] != a[len_search(a) - i]) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    char str[50];
    scanf("%s", str);
    if (is_palindrom) {
        printf("Yes");
    }
    else {
        printf("No");
    }
}

