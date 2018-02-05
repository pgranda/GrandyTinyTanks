#ifndef _MATRIX4_H_
#define _MATRIX4_H_
#include "Vector4.h"
#include <math.h>

class Matrix4
{
public:
	Matrix4();
	Matrix4(float a_11, float a_12, float a_13, float a_14, float a_21, float a_22, float a_23, float a_24, float a_31, float a_32, float a_33, float a_34, float a_41, float a_42, float a_43, float a_44);
	Matrix4(Vector4 x, Vector4 y, Vector4 z, Vector4 w)
	{
		xAxis = x;
		yAxis = y;
		zAxis = z;
		wComp = w;
	};

	~Matrix4()
	{

	};

	//Function to Add two Matrices
	static Matrix4 Add(Matrix4& a_m1, Matrix4& a_m2);

	//Function to Subtract two Matrices
	static Matrix4 Subtract(Matrix4& a_m1, Matrix4& a_m2);

	//Function to Multiply two Matrices
	friend Matrix4 Multiply(const Matrix4& a_m1, const Matrix4& a_m2);

	//Operators
	operator float*();
	operator const float*() const;
	Matrix4 operator+(const Matrix4& a_m4) const;
	Matrix4 operator-(const Matrix4& a_m4) const;
	Matrix4 operator*(const Matrix4& a_m4) const;

	//Other functions
	float Determinant3() const;
	bool Inverse();
	void Transpose();
	void RotateX(float fAngle);
	void RotateY(float fAngle);
	void RotateZ(float fAngle);
	void Scale(float fXScalar, float fYScalar, float fZScalar);
	static const Matrix4 IDENTITY;
	static const Matrix4 ZERO;

private:
	union
	{
		struct
		{
			float m11, m12, m13, m14,
				m21, m22, m23, m24,
				m31, m32, m33, m34,
				m41, m42, m43, m44;
		};
		struct
		{
			float i[16];
		};
		struct
		{
			Vector4 xAxis;
			Vector4 yAxis;
			Vector4 zAxis;
			Vector4 wComp;
		};
		struct
		{
			float mat[4][4];
		};
	};
};


#endif