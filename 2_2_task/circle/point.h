#pragma once

/*
    Поля x и y сделаны приватными
    Конкретно для этого класса их можно было сделать публичными
    Так как пользователь всё-равно будет иметь доступ без ограничений к этим полям через геттеры и сеттеры
    Но они сделаны приватными для образовательных целей
*/

class Point
{
private:
    float mx, my;

public:

    Point(float x, float y);
    Point();

    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);

    void normalize();
    float distance(const Point& p) const;
    float norm() const;
    Point operator+(const Point& right) const;
    Point operator*(float a) const;



    friend Point operator*(float a, const Point& p);
    friend std::ostream& operator<<(std::ostream& left, const Point& right);
};

class Circle {
private:
    Point center;
    float radius;
public:
    Circle(const Point& acenter, float aradius);
    Circle();
    Circle(const Circle& circle);

    Point getCent() const;
    float getRad() const;
    void setCent(const Point& acenter);
    void setRad(float radius);

    float getArea() const;
    float getDistance(const Point& p) const;
    bool isColliding(const Circle& c);
    void move(const Point& p);
};
