////////////////////////////////////////////////////////////////////////
//	File: Vector2.cpp
//
//	Author: Pawel Granda
//
//	Date: 09/02/2017
//
//	Brief: Maths Vector2 Library for Tiny Tanks Game
////////////////////////////////////////////////////////////////////////

#include "Vector2.h"
#include <math.h>

const Vector2 Vector2::ZERO = Vector2(0.f, 0.f);


//Vector Getter
void Vector2::Get(float& a_x, float& a_y) const
{
	a_x = x;
	a_y = y;
}

//Vector Setter
void Vector2::Set(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
}

//Vector X Getter
float Vector2::GetX() const
{
	return x;
}

//Vector X Setter
void Vector2::SetX(float a_x)
{
	x = a_x;
}
//Vector Y Getter
float Vector2::GetY() const
{
	return y;
}

//Vector Y Setter
void Vector2::SetY(float a_y)
{
	y = a_y;
}

//Calculate Vector Magnitude
float Vector2::Magnitude(float& a_x, float& a_y)
{
	return sqrtf(a_x*a_x + a_y*a_y);
}

//Calculate Squared Magnitude 
float Vector2::MagnitudeSquared(float& a_magnitude)
{
	return a_magnitude*a_magnitude;
}

//Calculate Distance Between Two Vectors
float Vector2::Distance(Vector2& a_v1, Vector2& a_v2)
{
	auto pX = a_v1.x - a_v2.x;
	auto pY = a_v1.y - a_v2.y;

	return sqrtf(pX*pX + pY*pY);
}

//Calculate Distance Squared
float Vector2::DistanceSquared(float& a_distance)
{
	return a_distance*a_distance;
}

//Calculate Dot Product
float Vector2::DotProduct(Vector2& a_v1, Vector2& a_v2)
{
	return a_v1.x * a_v2.x + a_v1.y * a_v2.y;
}

//Normalize Vector
void Vector2::Normalize(Vector2& arg, float& a_magnitude)
{
	if (!a_magnitude == 0)
	{
		arg.x = arg.x / a_magnitude;
		arg.y = arg.y / a_magnitude;
	}
}

//Normalized Vector
Vector2 Vector2::Normalized(Vector2& arg, float& a_magnitude)
{
	if (a_magnitude == 0)
	{
		return Vector2(arg.x, arg.y);
	}
	auto fXNorm = arg.x / a_magnitude;
	auto fYNorm = arg.y / a_magnitude;

	return Vector2(fXNorm, fYNorm);
}

//Lerp
Vector2 Vector2::Lerp(Vector2& a_vec1, Vector2& a_vec2, float a_t)
{
	return a_t * a_vec2 + (1 - a_t) * a_vec1;
}

//Bezier Curve
Vector2 Vector2::QuadBezier(Vector2& a_vec1, Vector2& a_vec2, Vector2& a_vec3, float a_t)
{
	Vector2 mid1 = Lerp(a_vec1, a_vec2, a_t);
	Vector2 mid2 = Lerp(a_vec2, a_vec3, a_t);

	return Lerp(mid1, mid2, a_t);
}

//Hermite Spline
Vector2 Vector2::HermiteSpline(Vector2& a_point0, Vector2& a_point1, Vector2& a_tangent0, Vector2& a_tangent1, float a_t)
{
	float tSquared = a_t * a_t;
	float tCubic = tSquared * a_t;

	float h00 = 2 * tCubic - 3 * tSquared + 1;
	float h01 = -2 * tCubic + 3 * tSquared;
	float h10 = tCubic - 2 * tSquared + a_t;
	float h11 = tCubic - tSquared;

	Vector2 point = h00 * a_point0 + h10 * a_tangent0 + h01 * a_point1 + h11 * a_tangent1;

	return point;
}

//Cardinal Spline
Vector2 Vector2::CardinalSpline(Vector2& a_point0, Vector2& a_point1, Vector2& a_point2, float a_a, float a_t)
{
	Vector2 tangent0 = (a_point1 - a_point0) * a_a;
	Vector2 tangent1 = (a_point2 - a_point1) * a_a;

	float tSquared = a_t * a_t;
	float tCubic = tSquared * a_t;

	float h00 = 2 * tCubic - 3 * tSquared + 1;
	float h01 = -2 * tCubic + 3 * tSquared;
	float h10 = tCubic - 2 * tSquared + a_t;
	float h11 = tCubic - tSquared;

	Vector2 point = h00 * a_point0 + h10 * tangent0 + h01 * a_point1 + h11 * tangent1;

	return point;
}

Vector2 Vector2::Rotate(Vector2& a_vec1, float sin, float cos)
{
	return Vector2(cos*a_vec1.x + sin*a_vec1.y, -sin*a_vec1.x + cos*a_vec1.y);
}

//Operators
Vector2::operator float*()
{
	return static_cast<float*>(&x);
}

Vector2::operator const float*() const
{
	return static_cast<const float*>(&x);
}

//+
Vector2 Vector2::operator+(const Vector2& arg)
{
	return Vector2(x + arg.x, y + arg.y);
}

Vector2 Vector2::operator+(const float & scalar) const
{
	return Vector2(scalar + x, scalar + y);
}

Vector2 operator+(const float & scalar, const Vector2 & a_v1)
{
	return Vector2(a_v1.x + scalar, a_v1.y + scalar);
}
//-
Vector2 Vector2::operator-(const Vector2& arg)
{
	return Vector2(x - arg.x, y - arg.y);
}

Vector2 Vector2::operator-(const float & scalar) const
{
	return Vector2(scalar - x, scalar - y);
}

Vector2 operator-(const float & scalar, const Vector2 & a_v1)
{
	return Vector2(a_v1.x - scalar, a_v1.y - scalar);
}

//*
Vector2 Vector2::operator*(const Vector2& arg)
{
	return Vector2(x * arg.x, y * arg.y);
}

Vector2 Vector2::operator*(const float & scalar) const
{
	return Vector2(scalar * x, scalar * y);
}

Vector2 operator*(const float & scalar, const Vector2 & a_v1)
{
	return Vector2(a_v1.x * scalar, a_v1.y * scalar);
}

// /
Vector2 Vector2::operator/(const Vector2& arg)
{
	return Vector2(x / arg.x, y / arg.y);
}

Vector2 Vector2::operator/(const float & scalar) const
{
	return Vector2(scalar / x, scalar / y);
}

Vector2 operator/(const float & scalar, const Vector2 & a_v1)
{
	return Vector2(a_v1.x / scalar, a_v1.y / scalar);
}

//Other
bool Vector2::operator!=(const Vector2& arg) const
{
	return ((x != arg.x) || (y != arg.y));
}

bool Vector2::operator==(const Vector2& arg) const
{
	return((x == arg.x) && (y == arg.y));
}

//Constructors
Vector2::Vector2()
{
	x = 0.f;
	y = 0.f;
}

Vector2::Vector2(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
}
