#ifndef _VECTOR4_H_
#define _VECTOR4_H_


class Vector4
{

public:
	//Vector4 Constructors
	Vector4();
	Vector4(float a_x, float a_y, float a_z, float a_w);

	//Vector4 Position X and Y Setter
	void Set(float a_x, float a_y, float a_z, float a_w);

	//Vector4 Position X and Y Getter
	void Get(float& a_x, float& a_y, float& a_z, float& a_w) const;

	//Calculate Magnitude
	static float Magnitude(float& a_x, float& a_y, float& a_z, float& a_w);

	//Calculate Squared Magnitude
	static float MagnitudeSquared(float& a_magnitude);

	//Calculate Distance Between Two Vectors
	static float Distance(Vector4& a_v1, Vector4& a_v2);

	//Calculate Squared Distance
	static float DistanceSquared(float& a_distance);

	//Calculate Dot Product
	static float DotProduct(Vector4& a_v1, Vector4& a_v2);

	//Calculate Cross Product
	static Vector4 CrossProduct(Vector4& a_v1, Vector4& a_v2);

	//Normalize Vector
	static void Normalize(Vector4& arg, float& a_magnitude);

	//Normalized Vector
	static Vector4 Normalized(Vector4& arg, float& a_magnitude);

	//Zero Vector
	static const Vector4 ZERO;

	//Lerp
	static Vector4 Lerp(Vector4& a_vec1, Vector4& a_vec2, float a_t);

	//Bezier Curve
	static Vector4 QuadBezier(Vector4& a_vec1, Vector4& a_vec2, Vector4& a_vec3, float a_t);

	//Hermite Spline
	static Vector4 HermiteSpline(Vector4& a_point0, Vector4& a_point1, Vector4& a_tangent0, Vector4& a_tangent1, float t);

	//Cardinal Spline
	static Vector4 CardinalSpline(Vector4& a_point0, Vector4& a_point1, Vector4& a_point2, float a_a, float a_t);

	//Operators
	operator float*();
	operator const float*() const;
	Vector4 operator+(const Vector4& arg) const;
	Vector4 operator-(const Vector4& arg) const;
	Vector4 operator*(const Vector4& arg) const;
	Vector4 operator*(const float& scalar) const;
	friend Vector4 operator*(const float& scalar, const Vector4& a_v1);
	Vector4 operator/(const Vector4& arg) const;
	bool operator!=(const Vector4& arg) const;
	bool operator==(const Vector4& arg) const;

private:

	//Values X, Y, Z and W for positioning
	float x;
	float y;
	float z;
	float w;

};
#endif