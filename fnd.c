

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
    if (n % 2 == 0 && ((n >= 0) && (n <= 20) || (n > 100) && (n < 200))) {
        printf("Yes");
    }
    else {
        printf("No");
    }
}

