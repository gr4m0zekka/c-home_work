

#include <stdio.h>
struct game
{
    char name[30];
    double mark;

};
typedef struct game Game;

int main()
{
    int n;
    scanf("%i", &n);
    Game list[10];
    for (int i = 0; i < n; ++i) {
        scanf("%[^:]", list[i].name);
        int k;
        double sum = 0;
        scanf(":%i", &k);
        for (int j = 0; j < k; ++j) {
            int now;
            scanf("%i", &now);
            sum += now;
        }
        list[i].mark = sum / k;
    }
    for (int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < n - 1; ++j) {
            if (list[j].mark > list[j + 1].mark) {
                Game step;
                step = list[j];
                list[j] = list[j + 1];
                list[j + 1] = step;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%s: %lf", list[i].name, list[i].mark);
    }
}
