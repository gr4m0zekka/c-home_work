

#include <iostream>
#include <math.h>
using namespace std;
double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double length(double x, double y) {
    return distance(x, y, 0, 0);
}
double scalar_product(double x1, double y1, double x2, double y2) {
    return x1 * x2 + y1 * y2;
}
const double pi = 3.14159265359;
double to_degrees(double rad) {
    return rad * 180 / pi;
}

int main()
{
    double  x, y;
    double  x1, y1;
    cin >> x >> y;
    cin >>  x1 >> y1;
    cout << to_degrees(acos(scalar_product(x, y, x1, y1) / (length(x,y)) * length(x1, y1)));
}

