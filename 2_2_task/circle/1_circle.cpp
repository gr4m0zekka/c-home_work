#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "point.h"


Point::Point(float x, float y)
{
	mx = x;
	my = y;
}

Point::Point()
{
	mx = 0;
	my = 0;
}


float Point::getX() const
{
	return mx;
}

float Point::getY() const
{
	return my;
}

void Point::setX(float x)
{
	mx = x;
}

void Point::setY(float y)
{
	my = y;
}

float Point::norm() const
{
	return std::sqrt(mx * mx + my * my);
}

void Point::normalize()
{
	float pnorm = norm();
	mx /= pnorm;
	my /= pnorm;
}

float Point::distance(const Point& p) const
{
	return std::sqrt((p.mx - mx) * (p.mx - mx) + (p.my - my) * (p.my - my));
}

Point Point::operator+(const Point& right) const
{
	Point result = { mx + right.mx, my + right.my };
	return result;
}

Point Point::operator*(float a) const
{
	Point result = { a * mx, a * my };
	return result;
}




Point operator*(float a, const Point& p)
{
	Point result = { a * p.mx, a * p.my };
	return result;
}

std::ostream& operator<<(std::ostream& left, const Point& right)
{
	left << "(" << right.mx << ", " << right.my << ")";
	return left;
}

Circle::Circle(const Point& acenter, float aradius) {
	center = acenter;
	radius = aradius;
}

Circle::Circle() {
	center = Point::Point();
	radius = 1;
}

Circle::Circle(const Circle& circle) {
	center = circle.center;
	radius = circle.radius;
}

Point Circle::getCent() const {
	return center;
}

float Circle::getRad() const {
	return radius;
}

void Circle::setCent(const Point& acenter) {
	center = acenter;
}

void Circle::setRad(float aradius) {
	if (aradius < 0) {
		radius = 0;
	}
	else {
		radius = aradius;
	}
}

float Circle::getArea() const {
	return 3.14 * radius * radius;
}

float Circle::getDistance(const Point& p) const {
	return center.distance(p) - radius;
}

bool Circle::isColliding(const Circle& c) {
	return center.distance(c.center) < radius + c.radius && center.distance(c.center) > radius - c.radius;
}

void Circle::move(const Point& p) {
	center.operator+(p);
}
int main()
{
    std::cout << "Hello World!\n";
}

