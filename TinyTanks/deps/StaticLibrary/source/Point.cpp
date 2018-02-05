#include "Point.h"

void Point::Get(float& a_x, float& a_y)
{
	a_x = x;
	a_y = y;
}

void Point::Set(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
}

Point::Point()
{
	x = 0.f;
	y = 0.f;
}

Point::Point(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
}

void Point::SetX(float a_x)
{
	x = a_x;
}

float Point::GetX()
{
	return x;
}

void Point::SetY(float a_y)
{
	y = a_y;
}

float Point::GetY()
{
	return y;
}

//Operators
Point::operator float*()
{
	return static_cast<float*>(&x);
}

Point::operator const float*() const
{
	return static_cast<const float*>(&x);
}

//+
Point Point::operator+(const Point& arg)
{
	return Point(x + arg.x, y + arg.y);
}

Point Point::operator+(const float & scalar) const
{
	return Point(scalar + x, scalar + y);
}

Point operator+(const float & scalar, const Point & a_v1)
{
	return Point(a_v1.x + scalar, a_v1.y + scalar);
}
//-
Point Point::operator-(const Point& arg)
{
	return Point(x - arg.x, y - arg.y);
}

Point Point::operator-(const float & scalar) const
{
	return Point(scalar - x, scalar - y);
}

Point operator-(const float & scalar, const Point & a_v1)
{
	return Point(a_v1.x - scalar, a_v1.y - scalar);
}

//*
Point Point::operator*(const Point& arg)
{
	return Point(x * arg.x, y * arg.y);
}

Point Point::operator*(const float & scalar) const
{
	return Point(scalar * x, scalar * y);
}

Point operator*(const float & scalar, const Point & a_v1)
{
	return Point(a_v1.x * scalar, a_v1.y * scalar);
}

// /
Point Point::operator/(const Point& arg)
{
	return Point(x / arg.x, y / arg.y);
}

Point Point::operator/(const float & scalar) const
{
	return Point(scalar / x, scalar / y);
}

Point operator/(const float & scalar, const Point & a_v1)
{
	return Point(a_v1.x / scalar, a_v1.y / scalar);
}

//Other
bool Point::operator!=(const Point& arg) const
{
	return ((x != arg.x) || (y != arg.y));
}

bool Point::operator==(const Point& arg) const
{
	return((x == arg.x) && (y == arg.y));
}