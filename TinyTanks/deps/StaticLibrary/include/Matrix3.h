#ifndef _MATRIX3_H_
#define _MATRIX3_H_
#include "Vector3.h"
#include <math.h>

class Matrix3
{
public:
	Matrix3();
	Matrix3(float a_11, float a_12, float a_13, float a_21, float a_22, float a_23, float a_31, float a_32, float a_33);
	Matrix3(Vector3 x, Vector3 y, Vector3 z)
	{
		xAxis = x;
		yAxis = y;
		zAxis = z;
	};

	~Matrix3()
	{

	};

	void SetRow(const int& row, const Vector3& a_v1);
	void GetRow(const int row, Vector3& a_v1) const;

	void SetColumn(const int& col, const Vector3& a_v1);
	void GetColumn(const int col, Vector3& a_v1) const;
	//Function to Add two Matrices
	static Matrix3 Add(Matrix3& a_m1, Matrix3& a_m2);

	//Function to Subtract two Matrices
	static Matrix3 Subtract(Matrix3& a_m1, Matrix3& a_m2);

	//Function to Multiply two Matrices
	friend Matrix3 Multiply(const Matrix3& a_m1, const Matrix3& a_m2);

	//Operators
	operator float*();
	operator const float*() const;
	Matrix3 operator+(const Matrix3& a_m3) const;
	Matrix3 operator-(const Matrix3& a_m3) const;
	Matrix3 operator*(const Matrix3& a_m3) const;
	bool operator==(const Matrix3& a_m3) const;

	//Other functions
	float Determinant() const;
	bool Inverse();
	void Transpose();
	void Rotate(float fAngle);
	void Scale(float fXScalar, float fYScalar);
	void Scale(float fScalar);
	static const Matrix3 IDENTITY;
	static const Matrix3 ZERO;


private:
	union
	{
		struct
		{
			float m11, m12, m13,
				m21, m22, m23,
				m31, m32, m33;
		};
		struct
		{
			float i[9];
		};
		struct
		{
			Vector3 xAxis;
			Vector3 yAxis;
			union
			{
				Vector3 zAxis;
				Vector3 Translation;
			};

		};
		struct
		{
			float mat[3][3];
		};
	};

	float GetFloatPrecision(float value, int precision) const;
};

#endif
