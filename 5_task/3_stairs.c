

#include <iostream>

int main()
{
    char w[100];
    scanf_s("%s", &w);
    int i = 0;
    while (w[i]) {
        for (int k = 0; k <= i; ++k) {
            printf("%c", w[k]);
        }
        printf("/n");
        ++i;
    }
}

