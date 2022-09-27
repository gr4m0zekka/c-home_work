

#include <iostream>
float yearfrac(int year, int day) {
    float day_f = day;
    if (year % 4) {
        return day_f / 365;
    }
    else {
        return day_f / 366;
    }
}
int main()
{
    int year, day;
    scanf_s("%i %i", &year, &day);
    printf("%.5f", yearfrac(year, day));
}

