////////////////////////////////////////////////////////////////////////
//	File: Vector4.cpp
//
//	Author: Pawel Granda
//
//	Date: 16/02/2017
//
//	Brief: Maths Vector4 Library for Tiny Tanks Game
////////////////////////////////////////////////////////////////////////
#include "Vector4.h"
#include <math.h>

const Vector4 Vector4::ZERO = Vector4(0.f, 0.f, 0.f, 0.f);

//Vector Getter
void Vector4::Get(float& a_x, float& a_y, float& a_z, float& a_w) const
{
	a_x = x;
	a_y = y;
	a_z = z;
	a_w = w;
}

//Vector Setter
void Vector4::Set(float a_x, float a_y, float a_z, float a_w)
{
	x = a_x;
	y = a_y;
	z = a_z;
	w = a_w;
}

//Calculate Vector Magnitude
float Vector4::Magnitude(float& a_x, float& a_y, float& a_z, float& a_w)
{
	return sqrtf(a_x*a_x + a_y*a_y + a_z*a_z + a_w*a_w);
}

//Calculate Squared Magnitude 
float Vector4::MagnitudeSquared(float& a_magnitude)
{
	return a_magnitude*a_magnitude;
}

//Calculate Distance Between Two Vectors
float Vector4::Distance(Vector4& a_v1, Vector4& a_v2)
{
	auto pX = a_v1.x - a_v2.x;
	auto pY = a_v1.y - a_v2.y;
	auto pZ = a_v1.z - a_v2.z;
	auto pW = a_v1.w - a_v2.w;

	return sqrtf(pX*pX + pY*pY + pZ*pZ + pW*pW);
}

//Calculate Distance Squared
float Vector4::DistanceSquared(float& a_distance)
{
	return a_distance*a_distance;
}

//Calculate Dot Product
float Vector4::DotProduct(Vector4& a_v1, Vector4& a_v2)
{
	return a_v1.x * a_v2.x + a_v1.y * a_v2.y + a_v1.z * a_v2.z + a_v1.w*a_v2.w;
}

//Normalize Vector
void Vector4::Normalize(Vector4& arg, float& a_magnitude)
{
	if (!a_magnitude == 0)
	{
		arg.x = arg.x / a_magnitude;
		arg.y = arg.y / a_magnitude;
		arg.z = arg.z / a_magnitude;
	}
}

//Normalized Vector
Vector4 Vector4::Normalized(Vector4& arg, float& a_magnitude)
{
	if (a_magnitude == 0)
	{
		return Vector4(arg.x, arg.y, arg.z, arg.w);
	}

	auto fXNorm = arg.x / a_magnitude;
	auto fYNorm = arg.y / a_magnitude;
	auto fZNorm = arg.z / a_magnitude;
	auto fWNorm = arg.w / a_magnitude;

	return Vector4(fXNorm, fYNorm, fZNorm, fWNorm);

}

//Lerp
Vector4 Vector4::Lerp(Vector4& a_vec1, Vector4& a_vec2, float a_t)
{
	return a_t * a_vec2 + (1 - a_t) * a_vec1;
}

//Bezier Curve
Vector4 Vector4::QuadBezier(Vector4& a_vec1, Vector4& a_vec2, Vector4& a_vec3, float a_t)
{
	Vector4 mid1 = Lerp(a_vec1, a_vec2, a_t);
	Vector4 mid2 = Lerp(a_vec2, a_vec3, a_t);

	return Lerp(mid1, mid2, a_t);
}

//Hermite Spline
Vector4 Vector4::HermiteSpline(Vector4& a_point0, Vector4& a_point1, Vector4& a_tangent0, Vector4& a_tangent1, float a_t)
{
	float tSquared = a_t * a_t;
	float tCubic = tSquared * a_t;

	float h00 = 2 * tCubic - 3 * tSquared + 1;
	float h01 = -2 * tCubic + 3 * tSquared;
	float h10 = tCubic - 2 * tSquared + a_t;
	float h11 = tCubic - tSquared;

	Vector4 point = h00 * a_point0 + h10 * a_tangent0 + h01 * a_point1 + h11 * a_tangent1;

	return point;
}

//Cardinal Spline
Vector4 Vector4::CardinalSpline(Vector4& a_point0, Vector4& a_point1, Vector4& a_point2, float a_a, float a_t)
{
	Vector4 tangent0 = (a_point1 - a_point0) * a_a;
	Vector4 tangent1 = (a_point2 - a_point1) * a_a;

	float tSquared = a_t * a_t;
	float tCubic = tSquared * a_t;

	float h00 = 2 * tCubic - 3 * tSquared + 1;
	float h01 = -2 * tCubic + 3 * tSquared;
	float h10 = tCubic - 2 * tSquared + a_t;
	float h11 = tCubic - tSquared;

	Vector4 point = h00 * a_point0 + h10 * tangent0 + h01 * a_point1 + h11 * tangent1;

	return point;
}

//Operators
Vector4::operator float*()
{
	return static_cast<float*>(&x);
}

Vector4::operator const float*() const
{
	return static_cast<const float*>(&x);
}
//+
Vector4 Vector4::operator+(const Vector4& arg) const
{
	return Vector4(x + arg.x, y + arg.y, z + arg.z, w + arg.w);
	//I don't know what to think about argument W, because when we add 1 and 1 its gonna be 2 which is not defined :/
	//Is it also possible to add 0 and 1? Point and Direction? 
	//Same goes with other operators
}
//-
Vector4 Vector4::operator-(const Vector4& arg) const
{
	return Vector4(x - arg.x, y - arg.y, z - arg.z, w - arg.w);
}
//*
Vector4 Vector4::operator*(const Vector4& arg) const
{
	return Vector4(x * arg.x, y * arg.y, z * arg.z, w * arg.w);
}

Vector4 Vector4::operator*(const float& scalar) const
{
	return Vector4(x * scalar, y * scalar, z * scalar, w * scalar);
}

Vector4 operator*(const float& scalar, const Vector4& a_v1)
{
	return Vector4(a_v1.x * scalar, a_v1.y * scalar, a_v1.z * scalar, a_v1.w * scalar);
}
// /
Vector4 Vector4::operator/(const Vector4& arg) const
{
	return Vector4(x / arg.x, y / arg.y, z / arg.z, w / arg.w);
}
//Other
bool Vector4::operator!=(const Vector4& arg) const
{
	return ((x != arg.x) || (y != arg.y) || (z != arg.z) || (w != arg.w));
}

bool Vector4::operator==(const Vector4& arg) const
{
	return ((x == arg.x) && (y == arg.y) && (z == arg.z) && (w == arg.w));
}

//Constructors
Vector4::Vector4()
{
	x = 0.f;
	y = 0.f;
	z = 0.f;
	w = 0.f;
}

Vector4::Vector4(float a_x, float a_y, float a_z, float a_w)
{
	x = a_x;
	y = a_y;
	z = a_z;
	w = a_w;
}