

#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;


int main()
{
    int n;
    scanf_s("%i", &n);
    for (int i = 1; i <= n; i++) {
        printf("%i ", i);
        printf("->");
        printf("%3i ", i * i);
        printf("-> ");
        printf("%3i\n", i * i * i);

    }
}

