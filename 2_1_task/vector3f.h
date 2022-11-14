#pragma once
#include <cmath>
#include <iostream>

struct vector3f
{
    float x;
    float y;
    float z;
};

vector3f operator+ (const vector3f & a, const vector3f & b) /*сложение векторов*/
{
    vector3f result = { a.x + b.x, a.y + b.y, a.z + b.z };
    return result;
}

vector3f operator-(const vector3f& a, const vector3f& b) /*вычитание векторов*/
{
    vector3f result = { a.x - b.x, a.y - b.y, a.z - b.z };
    return result;
}

vector3f operator*(const vector3f& a, const float& b) /*умножение вектора на число*/
{
    vector3f result = { a.x * b, a.y * b, a.z * b };
    return result;
}

vector3f operator*(const float& b, const vector3f& a) /*умножение числа на вектор*/
{
    vector3f result = { a.x * b, a.y * b, a.z * b };
    return result;
}

float operator*(const vector3f& a, const vector3f& b) /*умножение векторов*/
{
    float result =  a.x * b.x + a.y * b.y + a.z * b.z ;
    return result;
}

vector3f operator/(const vector3f& a, const float& b) /*деление вектора на число*/
{
    vector3f result = { a.x / b, a.y / b, a.z / b };
    return result;
}

bool operator==(const vector3f& a, const vector3f b) { /*проверка на равенство */
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

bool operator!=(const vector3f& a, const vector3f& b) { /*проверка на нерваенство*/
    return a.x != b.x || a.y != b.y || a.z != b.z;
}
vector3f operator+=(vector3f a, const vector3f b) { /*увеличиваем вектор на вектор*/
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
 }

vector3f operator-=(vector3f a, const vector3f b) { /*уменьшаем вектор на вектор*/
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

vector3f& operator*=(vector3f a, const float b) { /*умеожаем вектор на число*/
    a.x *= b;
    a.y *= b;
    a.z *= b;
    return a;
}

vector3f& operator/=(vector3f a, const float b) { /*деление вектора на число*/
    a.x /= b;
    a.y /= b;
    a.z /= b;
    return a;
}

vector3f operator-(const vector3f& a) /*унарный минус*/
{
    vector3f result;
    result.x = -a.x;
    result.y = -a.y;
    result.z = -a.z;
    return result;
}


vector3f operator+(const vector3f& a) /*унарный плюс*/
{
    return a;
}

std::ostream& operator<<(std::ostream& out, const vector3f& a) { /*вывод вектора*/
    out << '(' << a.x << "," << a.y << "," << a.z << ')';
    return out;
}

std::istream& operator>>(std::istream& in, vector3f& c) { /*ввод вектора*/
    in >> c.x >> c.y >> c.z;
    return in;
}

float squaredNorm(const vector3f& a) { /*возвращает квадрат нормы*/
    return a.x * a.x + a.y * a.y + a.z * a.z;
}

float norm(const vector3f& a) { /*возвращает норму */
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

void normalize(vector3f& a) { /*нормализуем вектор а*/
    a.x = a.x / norm(a);
    a.y = a.y / norm(a);
    a.z = a.z / norm(a);
}










