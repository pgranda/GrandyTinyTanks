////////////////////////////////////////////////////////////////////////
//	File: Vector3.cpp
//
//	Author: Pawel Granda
//
//	Date: 09/02/2017
//
//	Brief: Maths Vector3 Library for Tiny Tanks Game
////////////////////////////////////////////////////////////////////////
#include "Vector3.h"
#include "Matrix3.h"
#include <math.h>

const Vector3 Vector3::ZERO = Vector3(0.f, 0.f, 0.f);
const Vector3 Vector3::AXIS_Y = Vector3(0.f, 1.0f, 0.f);

//Vector Getter
void Vector3::Get(float& a_x, float& a_y, float& a_z) const
{
	a_x = x;
	a_y = y;
	a_z = z;
}

//Vector Setter
void Vector3::Set(float a_x, float a_y, float a_z)
{
	x = a_x;
	y = a_y;
	z = a_z;
}

//Vector X Getter
float Vector3::GetX() const
{
	return x;
}

//Vector X Setter
void Vector3::SetX(float a_x)
{
	x = a_x;
}

//Vector Y Getter
float Vector3::GetY() const
{
	return y;
}

//Vector Y Setter
void Vector3::SetY(float a_y)
{
	y = a_y;
}

//Vector Y Getter
float Vector3::GetZ() const
{
	return z;
}

//Vector Y Setter
void Vector3::SetZ(float a_z)
{
	z = a_z;
}

//Calculate Vector Magnitude
float Vector3::Magnitude(float const a_x, float const a_y, float const a_z)
{
	return sqrtf(a_x*a_x + a_y*a_y + a_z*a_z);
}

//Calculate Squared Magnitude 
float Vector3::MagnitudeSquared(float& a_magnitude)
{
	return a_magnitude*a_magnitude;
}

//Calculate Distance Between Two Vectors
float Vector3::Distance(Vector3& a_v1, Vector3& a_v2)
{
	auto pX = a_v1.x - a_v2.x;
	auto pY = a_v1.y - a_v2.y;
	auto pZ = a_v1.z - a_v2.z;

	return sqrtf(pX*pX + pY*pY + pZ*pZ);
}

//Calculate Distance Squared
float Vector3::DistanceSquared(float& a_distance)
{
	return a_distance*a_distance;
}

//Calculate Dot Product
float Vector3::DotProduct(Vector3& a_v1, Vector3& a_v2)
{
	return a_v1.x * a_v2.x + a_v1.y * a_v2.y + a_v1.z * a_v2.z;
}

//Calculate Cross Product
Vector3 Vector3::CrossProduct(Vector3& a_v1, Vector3& a_v2)
{
	auto fXCross = a_v1.y * a_v2.z - a_v1.z * a_v2.y;
	auto fYCross = a_v1.z * a_v2.x - a_v1.x * a_v2.z;
	auto fZCross = a_v1.x * a_v2.y - a_v1.y * a_v2.x;

	return Vector3(fXCross, fYCross, fZCross);
}

//Normalize Vector
void Vector3::Normalize(Vector3& arg, float& a_magnitude)
{
	if (!a_magnitude == 0)
	{
		arg.x = arg.x / a_magnitude;
		arg.y = arg.y / a_magnitude;
		arg.z = arg.z / a_magnitude;
	}
}

//Normalized Vector
Vector3 Vector3::Normalized(Vector3& arg, float& a_magnitude)
{
	if (a_magnitude == 0)
	{
		return Vector3(arg.x, arg.y, arg.z);
	}

	auto fXNorm = arg.x / a_magnitude;
	auto fYNorm = arg.y / a_magnitude;
	auto fZNorm = arg.z / a_magnitude;

	return Vector3(fXNorm, fYNorm, fZNorm);

}

//Lerp
Vector3 Vector3::Lerp(Vector3& a_vec1, Vector3& a_vec2, float a_t)
{
	return a_t * a_vec2 + (1 - a_t) * a_vec1;
}

//Bezier Curve
Vector3 Vector3::QuadBezier(Vector3& a_vec1, Vector3& a_vec2, Vector3& a_vec3, float a_t)
{
	Vector3 mid1 = Lerp(a_vec1, a_vec2, a_t);
	Vector3 mid2 = Lerp(a_vec2, a_vec3, a_t);

	return Lerp(mid1, mid2, a_t);
}

//Hermite Spline
Vector3 Vector3::HermiteSpline(Vector3& a_point0, Vector3& a_point1, Vector3& a_tangent0, Vector3& a_tangent1, float a_t)
{
	float tSquared = a_t * a_t;
	float tCubic = tSquared * a_t;

	float h00 = 2 * tCubic - 3 * tSquared + 1;
	float h01 = -2 * tCubic + 3 * tSquared;
	float h10 = tCubic - 2 * tSquared + a_t;
	float h11 = tCubic - tSquared;

	Vector3 point = h00 * a_point0 + h10 * a_tangent0 + h01 * a_point1 + h11 * a_tangent1;

	return point;
}

//Cardinal Spline
Vector3 Vector3::CardinalSpline(Vector3& a_point0, Vector3& a_point1, Vector3& a_point2, float a_a, float a_t)
{
	Vector3 tangent0 = (a_point1 - a_point0) * a_a;
	Vector3 tangent1 = (a_point2 - a_point1) * a_a;

	float tSquared = a_t * a_t;
	float tCubic = tSquared * a_t;

	float h00 = 2 * tCubic - 3 * tSquared + 1;
	float h01 = -2 * tCubic + 3 * tSquared;
	float h10 = tCubic - 2 * tSquared + a_t;
	float h11 = tCubic - tSquared;

	Vector3 point = h00 * a_point0 + h10 * tangent0 + h01 * a_point1 + h11 * tangent1;

	return point;
}

//Operators
Vector3::operator float*()
{
	return static_cast<float*>(&x);
}

Vector3::operator const float*() const
{
	return static_cast<const float*>(&x);
}
//+
Vector3 Vector3::operator+(const Vector3& arg) const
{
	return Vector3(x + arg.x, y + arg.y, z + arg.z);
}

Vector3 Vector3::operator+(const float & scalar) const
{
	return Vector3(scalar + x, scalar + y, scalar + z);
}

Vector3 operator+(const float & scalar, const Vector3 & a_v1)
{
	return Vector3(a_v1.x + scalar, a_v1.y + scalar, a_v1.z + scalar);
}

//-
Vector3 Vector3::operator-(const Vector3& arg) const
{
	return Vector3(x - arg.x, y - arg.y, z - arg.z);
}

Vector3 Vector3::operator-(const float & scalar) const
{
	return Vector3(x - scalar, y - scalar, z - scalar);
}

Vector3 operator-(const float & scalar, const Vector3 & a_v1)
{
	return Vector3(a_v1.x - scalar, a_v1.y - scalar, a_v1.z - scalar);
}

//*
Vector3 Vector3::operator*(const float& scalar) const
{
	return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 Vector3::operator*(const Vector3& arg) const
{
	return Vector3(x * arg.x, y * arg.y, z * arg.z);
}

Vector3 operator*(const float& scalar, const Vector3& a_v1)
{
	return Vector3(a_v1.x * scalar, a_v1.y * scalar, a_v1.z * scalar);
}

Vector3 Vector3::operator*(const Matrix3& a_m1) const
{
	Vector3 row1;
	Vector3 row2;
	Vector3 row3;
	a_m1.GetColumn(0, row1);
	a_m1.GetColumn(1, row2);
	a_m1.GetColumn(2, row3);

	Vector3 newVector(
		(row1.GetX() * x) + (row1.GetY() * y) + (row1.GetZ() * z),
		(row2.GetX() * x) + (row2.GetY() * y) + (row2.GetZ() * z),
		(row3.GetX() * x) + (row3.GetY()* y) + (row3.GetZ()  *z));
	return newVector;

}

// /
Vector3 Vector3::operator/(const Vector3& arg) const
{
	return Vector3(x / arg.x, y / arg.y, z / arg.z);
}

Vector3 Vector3::operator/(const float & scalar) const
{
	return Vector3(x / scalar, y / scalar, z / scalar);
}

Vector3 operator/(const float & scalar, const Vector3 & a_v1)
{
	return Vector3(a_v1.x / scalar, a_v1.y / scalar, a_v1.z / scalar);
}

//Other
bool Vector3::operator!=(const Vector3& arg) const
{
	return ((x != arg.x) || (y != arg.y) || (z != arg.z));
}

bool Vector3::operator==(const Vector3& arg) const
{
	return ((x == arg.x) && (y == arg.y) && (z == arg.z));
}

//Constructors
Vector3::Vector3()
{
	x = 0.f;
	y = 0.f;
	z = 0.f;
}

Vector3::Vector3(float a_x, float a_y, float a_z)
{
	x = a_x;
	y = a_y;
	z = a_z;
}

Vector3::Vector3(Vector2 a_v1)
{
	x = a_v1.GetX();
	y = a_v1.GetY();
	z = 0.f; //TO DO I AM NOT SURE
}