

#include <iostream>

int main()
{
    char w1[30];
    char w2[20];
    scanf("%s", w1);
    scanf("%s", w2);
    int i = 0;
    while (w1[i] && w2[i]) {
        printf("%c%c", w1[i], w2[i]);
        ++i;
    }
    if (w1[i]) {
        while (w1[i]) {
            printf("%c", w1[i]);
            ++i;
        }
    }
    else if (w2[i]) {
        while (w2[i]) {
            printf("%c", w2[i]);
            ++i;
        }
    }
}

