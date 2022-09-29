

#include <iostream>
#include <math.h>

double distance(double x, double y, double x1, double y1) {
    return sqrt(pow(x - x1, 2) + pow(y - y1, 2));
}
const double eps = pow(10, -5);
using namespace std;
int main()
{
    double x, y, r1;
    cin >> x >> y >> r1;
    double x1, y1, r2;
    cin >> x1 >> y1 >> r2;
    if (distance(x, y, x1, y1) + min(r1, r2) < max(r1, r2) or distance(x, y, x1, y1) > r1 + r2) {
        cout << "Do not intersect";
    }
    else if (distance(x, y, x1, y1) + min(r1, r2) - max(r1, r2) < eps and distance(x, y, x1, y1) + min(r1, r2) - max(r1, r2) > -eps or distance(x, y, x1, y1) - r1 - r2 < eps and distance(x, y, x1, y1) - r1 - r2 > -eps) {
        cout << "Touch";
    }
    else if (distance(x, y, x1, y1) + min(r1, r2) > max(r1, r2) or distance(x, y, x1, y1) < r1 + r2) {
        cout << "Intersect";
    }

}

