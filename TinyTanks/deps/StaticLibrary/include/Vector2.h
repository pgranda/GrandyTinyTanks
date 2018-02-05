#ifndef _VECTOR2_H_
#define _VECTOR2_H_


class Vector2
{

public:
	//Vector2 Constructors
	Vector2();
	Vector2(float a_x, float a_y);

	//Vector2 Position X and Y Setter
	void Set(float a_x, float a_y);

	//Vector2 Position X and Y Getter
	void Get(float& a_x, float& a_y) const;

	//Vector2 Position X Setter
	void SetX(float a_x);

	//Vector2 Position X Getter
	float GetX() const;

	//Vector2 Position Y Setter
	void SetY(float a_y);

	//Vector2 Position Y Getter
	float GetY() const;

	//Calculate Magnitude
	static float Magnitude(float& a_x, float& a_y);

	//Calculate Squared Magnitude
	static float MagnitudeSquared(float& a_magnitude);

	//Calculate Distance Between Two Vectors
	static float Distance(Vector2& a_v1, Vector2& a_v2);

	//Calculate Squared Distance
	static float DistanceSquared(float& a_distance);

	//Calculate Dot Product
	static float DotProduct(Vector2& a_v1, Vector2& a_v2);

	//Normalize Vector
	static void Normalize(Vector2& arg, float& a_magnitude);

	//Normalized Vector
	static Vector2 Normalized(Vector2& arg, float& a_magnitude);

	//Zero Vector
	static const Vector2 ZERO;

	//Lerp
	static Vector2 Lerp(Vector2& a_vec1, Vector2& a_vec2, float a_t);

	//Bezier Curve
	static Vector2 QuadBezier(Vector2& a_vec1, Vector2& a_vec2, Vector2& a_vec3, float a_t);

	//Hermite Spline
	static Vector2 HermiteSpline(Vector2& a_point0, Vector2& a_point1, Vector2& a_tangent0, Vector2& a_tangent1, float t);

	//Cardinal Spline
	static Vector2 CardinalSpline(Vector2& a_point0, Vector2& a_point1, Vector2& a_point2, float a_a, float a_t);

	static Vector2 Rotate(Vector2& a_vec1, float sin, float cos);

	//Operators
	operator float*();
	operator const float*() const;
	//+
	Vector2 operator+(const Vector2& arg);
	Vector2 operator+(const float& scalar) const;
	friend Vector2 operator+(const float& scalar, const Vector2& a_v1);
	//-
	Vector2 operator-(const Vector2& arg);
	Vector2 operator-(const float& scalar) const;
	friend Vector2 operator-(const float& scalar, const Vector2& a_v1);
	//*
	Vector2 operator*(const Vector2& arg);
	Vector2 operator*(const float& scalar) const;
	friend Vector2 operator*(const float& scalar, const Vector2& a_v1);
	// /
	Vector2 operator/(const Vector2& arg);
	Vector2 operator/(const float& scalar) const;
	friend Vector2 operator/(const float& scalar, const Vector2& a_v1);
	//Other
	bool operator!=(const Vector2& arg) const;
	bool operator==(const Vector2& arg) const;

private:

	//Values X and Y for Positioning
	float x;
	float y;

};
#endif