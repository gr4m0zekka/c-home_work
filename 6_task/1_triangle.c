

#include <iostream>
#include <cmath>
struct point
{
    double x, y;
};
typedef struct point Point;
struct triangle
{
    Point a, b, c;
};
typedef struct triangle Triangle;
void print_point(Point a) {
    printf("(%.2lf, %.2lf)", a.x, a.y);
}
void print_triangle(Triangle XYZ) {
    printf("{");
    print_point(XYZ.a);
    print_point(XYZ.b);
    print_point(XYZ.c);
    printf("}");
}
double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double get_triangle_perimeter(const Triangle*  ABC) {
    return distance(ABC -> a, ABC -> b) + distance(ABC -> a, ABC -> c) + distance(ABC -> c, ABC -> b);
}
double get_triangle_area(const Triangle* ABC) {
    double p = get_triangle_perimeter(ABC) / 2;
    return sqrt(p * (p - distance(ABC -> a, ABC -> b)) * (p - distance(ABC -> a, ABC -> c)) * (p - distance(ABC -> c, ABC -> b)));
}
void move_triangle(Triangle* ABC, Point p) {
    (ABC -> a).x += p.x;
    (ABC->a).y += p.y;
    (ABC->b).x += p.x;
    (ABC->b).y += p.y;
    (ABC->c).x += p.x;
    (ABC->c).y += p.y;

}
Triangle moved_triangle(const Triangle* ABC, Point p) {
    Triangle XYZ = *ABC;
    (XYZ.a).x += p.x;
    (XYZ.a).y += p.y;
    (XYZ.b).x += p.x;
    (XYZ.b).y += p.y;
    (XYZ.c).x += p.x;
    (XYZ.c).y += p.y;
    return XYZ;
}
int main()
{
    Point a = { 0,3 };
    Triangle ABC = {0,0,0,4,3,0};
    Triangle* p = &ABC;
    moved_triangle(p, a);
    print_triangle(moved_triangle(p, a));
}

