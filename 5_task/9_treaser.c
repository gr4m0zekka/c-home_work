
#include <iostream>

#include <stdio.h>

int main()
{
    int n;
    char direct1[10] = "North";
    char direct2[10] = "South";
    char direct3[10] = "West";
    char direct4[10] = "East";
    int X = 0, Y = 0;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i) {
        char  cor[30];
        scanf("%s", cor);
        int step;
        scanf("%i", &step);
        if (strcmp(cor, direct1) != 0) {
            Y += step;
        }
        else if (strcmp(cor, direct2) != 0) {
            Y -= step;
        }
        else if (strcmp(cor, direct3) != 0) {
            X -= step;
        }
        else if (strcmp(cor, direct4) != 0) {
            X += step;
        }
    }
    printf("%i %i", X, Y);
}
