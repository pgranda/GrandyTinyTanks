#ifndef _VECTOR3_H_
#define _VECTOR3_H_
#include "Vector2.h"

class Matrix3;
class Vector3
{

public:
	//Vector3 Constructors
	Vector3();
	Vector3(float a_x, float a_y, float a_z);
	Vector3(Vector2 a_v1);

	//Vector3 Position X and Y Setter
	void Set(float a_x, float a_y, float a_z);

	//Vector3 Position X and Y Getter
	void Get(float& a_x, float& a_y, float& a_z) const;

	//Vector3 Position X Setter
	void SetX(float a_x);

	//Vector3 Position X Getter
	float GetX() const;

	//Vector3 Position Y Setter
	void SetY(float a_y);

	//Vector3 Position Y Getter
	float GetY() const;

	//Vector3 Position Z Setter
	void SetZ(float a_z);

	//Vector3 Position Z Getter
	float GetZ() const;

	//Calculate Magnitude
	static float Magnitude(float const a_x, float const a_y, float const a_z);

	//Calculate Squared Magnitude
	static float MagnitudeSquared(float& a_magnitude);

	//Calculate Distance Between Two Vectors
	static float Distance(Vector3& a_v1, Vector3& a_v2);

	//Calculate Squared Distance
	static float DistanceSquared(float& a_distance);

	//Calculate Dot Product
	static float DotProduct(Vector3& a_v1, Vector3& a_v2);

	//Calculate Cross Product
	static Vector3 CrossProduct(Vector3& a_v1, Vector3& a_v2);

	//Normalize Vector
	static void Normalize(Vector3& arg, float& a_magnitude);

	//Normalized Vector
	static Vector3 Normalized(Vector3& arg, float& a_magnitude);

	//Zero Vector
	static const Vector3 ZERO;
	static const Vector3 AXIS_Y;

	//Lerp
	static Vector3 Lerp(Vector3& a_vec1, Vector3& a_vec2, float a_t);

	//Bezier Curve
	static Vector3 QuadBezier(Vector3& a_vec1, Vector3& a_vec2, Vector3& a_vec3, float a_t);

	//Hermite Spline
	static Vector3 HermiteSpline(Vector3& a_point0, Vector3& a_point1, Vector3& a_tangent0, Vector3& a_tangent1, float t);

	//Cardinal Spline
	static Vector3 CardinalSpline(Vector3& a_point0, Vector3& a_point1, Vector3& a_point2, float a_a, float a_t);

	//Operators
	operator float*();
	operator const float*() const;
	Vector3 operator+(const Vector3& arg) const;
	Vector3 operator+(const float& scalar) const;
	friend Vector3 operator+(const float& scalar, const Vector3& a_v1);

	Vector3 operator-(const Vector3& arg) const;
	Vector3 operator-(const float& scalar) const;
	friend Vector3 operator-(const float& scalar, const Vector3& a_v1);

	Vector3 operator*(const Vector3& arg) const;
	Vector3 operator*(const float& scalar) const;
	Vector3 operator*(const Matrix3& a_m1) const;
	friend Vector3 operator*(const float& scalar, const Vector3& a_v1);

	Vector3 operator/(const Vector3& arg) const;
	Vector3 operator/(const float& scalar) const;
	friend Vector3 operator/(const float& scalar, const Vector3& a_v1);

	bool operator!=(const Vector3& arg) const;
	bool operator==(const Vector3& arg) const;

private:

	//Values X, Y and Z for positioning
	float x;
	float y;
	float z;

};
#endif