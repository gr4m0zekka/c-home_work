

#include <iostream>
#include <math.h>
const double eps = pow(10, -10);
int solve_quadratic(double a, double b, double c, double* px1, double* px2) {
    double d = pow(b, 2) - 4 * a * c;
    if (d + eps < 0) {
        return 0;
    }
    else if (d + eps > 0 && d - eps < 0) {
        double sol = -b / (2 * a);
        *px1 = sol;
        return 1;
    }
    else if (d - eps > 0) {
        *px1 = (-b - sqrt(d)) / (2 * a);
        *px2 = (-b + sqrt(d)) / (2 * a);
        return 2;
    }
}
using namespace std;
int main()
{
    double a, b, c, sl1, sl2;
    cin >> a >> b >> c;
    double* px1 = &sl1;
    double* px2 = &sl2;
    solve_quadratic(a, b, c, px1, px2);
    cout << sl1 << " " << sl2;
}

