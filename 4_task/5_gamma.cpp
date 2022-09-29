
#include <iostream>
#include <math.h>
using namespace std;
double gamma(double x) {
    double integr = 0;
    const double dt = 0.01;
    const double eps = pow(10, -10);
    double t = 0;
    double sq = (pow(t, x - 1)) * exp(- t) + pow(t + dt, x - 1) * exp(- t - dt) / 2 * dt;
    while (sq >= eps) {
        integr += sq;
        t += dt;
        sq = (pow(t, x - 1) * exp(-t) + pow(t + dt, x - 1) * exp(-t - dt)) / 2 * dt;
    }
    return integr;
}
int main()
{
    double x;
    cin >> x;
    cout << gamma(x);
}
