

#include <iostream>
#include <math.h>
using namespace std;

double f(double x) {
    return pow(x, 5) + 2 * pow(x, 4) + 5 * pow(x, 2) + 4 * x - 500;
}
const double eps = pow(10, -10);

int main()
{
    double l, h;
    cin >> l >> h;
    while (h - l > eps) {
         double m = (l + h) / 2;
         if (f(m) < 0) {
             l = m;
         }
         else if (f(m) > 0) {
             h = m;
         }
    }
    cout << h;
}

