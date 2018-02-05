#include "Matrix4.h"

const Matrix4 Matrix4::IDENTITY = Matrix4(1.0f, 0.f, 0.f, 0.f, 0.f, 1.0f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f);
const Matrix4 Matrix4::ZERO = Matrix4(0.0f, 0.f, 0.f, 0.f, 0.f, 0.0f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f);


Matrix4::Matrix4()
{

}

Matrix4::Matrix4(float a_11, float a_12, float a_13, float a_14, float a_21, float a_22, float a_23, float a_24, float a_31, float a_32, float a_33, float a_34, float a_41, float a_42, float a_43, float a_44) :
	m11(a_11), m12(a_12), m13(a_13), m14(a_14),
	m21(a_21), m22(a_22), m23(a_23), m24(a_24),
	m31(a_31), m32(a_32), m33(a_33), m34(a_34),
	m41(a_41), m42(a_42), m43(a_43), m44(a_44)
{
}

//Function to Add two Matrices
Matrix4 Matrix4::Add(Matrix4& a_m1, Matrix4& a_m2)
{
	Matrix4 result;
	result = a_m1 + a_m2;
	return result;
}

//Function to Subtract two Matrices
Matrix4 Matrix4::Subtract(Matrix4& a_m1, Matrix4& a_m2)
{
	Matrix4 result;
	result = a_m1 - a_m2;
	return result;
}

//Function to Multiply two Matrices
Matrix4 Multiply(const Matrix4& a_m1, const Matrix4& a_m2)
{
	Matrix4 result;
	result = a_m1 * a_m2;
	return result;
}

//Operators
Matrix4::operator float*()
{
	return static_cast<float*>(&m11);
}

Matrix4::operator const float*() const
{
	return static_cast<const float*>(&m11);
}
Matrix4 Matrix4::operator+(const Matrix4& a_m4) const
{
	Matrix4 result;
	result.m11 = m11 + a_m4.m11;
	result.m12 = m12 + a_m4.m12;
	result.m13 = m13 + a_m4.m13;
	result.m14 = m14 + a_m4.m14;
	result.m21 = m21 + a_m4.m21;
	result.m22 = m22 + a_m4.m22;
	result.m23 = m23 + a_m4.m23;
	result.m14 = m14 + a_m4.m14;
	result.m31 = m31 + a_m4.m31;
	result.m32 = m32 + a_m4.m32;
	result.m33 = m33 + a_m4.m33;
	result.m34 = m34 + a_m4.m34;
	result.m41 = m41 + a_m4.m41;
	result.m42 = m42 + a_m4.m42;
	result.m43 = m43 + a_m4.m43;
	result.m44 = m44 + a_m4.m44;

	//result.xAxis = xAxis + a_m4.xAxis;
	//result.yAxis = yAxis + a_m4.yAxis;
	//result.zAxis = zAxis + a_m4.zAxis;
	//result.wComp = wComp + a_m4.wComp;

	return result;
}

Matrix4 Matrix4::operator-(const Matrix4& a_m4) const
{
	Matrix4 result;
	result.m11 = m11 - a_m4.m11;
	result.m12 = m12 - a_m4.m12;
	result.m13 = m13 - a_m4.m13;
	result.m14 = m14 - a_m4.m14;
	result.m21 = m21 - a_m4.m21;
	result.m22 = m22 - a_m4.m22;
	result.m23 = m23 - a_m4.m23;
	result.m14 = m14 - a_m4.m14;
	result.m31 = m31 - a_m4.m31;
	result.m32 = m32 - a_m4.m32;
	result.m33 = m33 - a_m4.m33;
	result.m34 = m34 - a_m4.m34;
	result.m41 = m41 - a_m4.m41;
	result.m42 = m42 - a_m4.m42;
	result.m43 = m43 - a_m4.m43;
	result.m44 = m44 - a_m4.m44;

	//result.xAxis = xAxis - a_m4.xAxis;
	//result.yAxis = yAxis - a_m4.yAxis;
	//result.zAxis = zAxis - a_m4.zAxis;
	//result.zAxis = wComp - a_m4.wComp;

	return result;
}

Matrix4 Matrix4::operator*(const Matrix4& a_m4) const
{
	Matrix4 result;
	result.m11 = m11 * a_m4.m11 + m12 * a_m4.m21 + m13 * a_m4.m31 + m14 * a_m4.m41;
	result.m12 = m11 * a_m4.m21 + m12 * a_m4.m22 + m13 * a_m4.m32 + m14 * a_m4.m42;
	result.m13 = m11 * a_m4.m31 + m12 * a_m4.m23 + m13 * a_m4.m33 + m14 * a_m4.m43;
	result.m14 = m11 * a_m4.m41 + m12 * a_m4.m24 + m13 * a_m4.m34 + m14 * a_m4.m44;

	result.m21 = m21 * a_m4.m11 + m22 * a_m4.m21 + m23 * a_m4.m31 + m24 * a_m4.m41;
	result.m22 = m21 * a_m4.m21 + m22 * a_m4.m22 + m23 * a_m4.m32 + m24 * a_m4.m42;
	result.m23 = m21 * a_m4.m31 + m22 * a_m4.m23 + m23 * a_m4.m33 + m24 * a_m4.m43;
	result.m24 = m21 * a_m4.m41 + m22 * a_m4.m24 + m23 * a_m4.m34 + m24 * a_m4.m44;

	result.m31 = m31 * a_m4.m11 + m32 * a_m4.m21 + m33 * a_m4.m31 + m34 * a_m4.m41;
	result.m32 = m31 * a_m4.m21 + m32 * a_m4.m22 + m33 * a_m4.m32 + m34 * a_m4.m42;
	result.m33 = m31 * a_m4.m31 + m32 * a_m4.m23 + m33 * a_m4.m33 + m34 * a_m4.m43;
	result.m34 = m31 * a_m4.m41 + m32 * a_m4.m24 + m33 * a_m4.m34 + m34 * a_m4.m44;

	result.m41 = m41 * a_m4.m11 + m42 * a_m4.m21 + m43 * a_m4.m31 + m44 * a_m4.m41;
	result.m42 = m41 * a_m4.m21 + m42 * a_m4.m22 + m43 * a_m4.m32 + m44 * a_m4.m42;
	result.m43 = m41 * a_m4.m31 + m42 * a_m4.m23 + m43 * a_m4.m33 + m44 * a_m4.m43;
	result.m44 = m41 * a_m4.m41 + m42 * a_m4.m24 + m43 * a_m4.m34 + m44 * a_m4.m44;


	return result;
}

//Matrix4 Determinant
float Matrix4::Determinant3() const
{
	return (m11 * (m22 * m33 - m23 * m32) +
		m12 * (m23 * m31 - m21 * m33) +
		m13 * (m21 * m32 - m22 * m31));
}

//Function to Inverse Matrix
bool Matrix4::Inverse()
{
	float fDeterminant = Determinant3();
	if (fDeterminant != 0.0f)
	{
		const float fInvDet = 1 / fDeterminant;

		Matrix4 mat = *this;
		m11 = (mat.m22 * mat.m33 - mat.m23 * mat.m32) * fInvDet;
		m12 = (mat.m13 * mat.m32 - mat.m12 * mat.m33) * fInvDet;
		m13 = (mat.m12 * mat.m23 - mat.m13 * mat.m22) * fInvDet;
		m14 = 0.0f;

		m21 = (mat.m23 * mat.m31 - mat.m21 * mat.m33) * fInvDet;
		m22 = (mat.m11 * mat.m33 - mat.m13 * mat.m31) * fInvDet;
		m23 = (mat.m13 * mat.m21 - mat.m11 * mat.m23) * fInvDet;
		m24 = 0.0f;

		m31 = (mat.m21 * mat.m32 - mat.m22 * mat.m31) * fInvDet;
		m32 = (mat.m12 * mat.m31 - mat.m11 * mat.m32) * fInvDet;
		m33 = (mat.m11 * mat.m22 - mat.m12 * mat.m21) * fInvDet;
		m34 = 0.0f;

		m41 = (mat.m21 * (mat.m33 * mat.m42 - mat.m32 * mat.m43) +
			mat.m22 * (mat.m31 * mat.m43 - mat.m33 * mat.m41) +
			mat.m23 * (mat.m32 * mat.m41 - mat.m31 * mat.m42)) * fInvDet;
		m42 = (mat.m11 * (mat.m32 * mat.m43 - mat.m33 * mat.m42) +
			mat.m12 * (mat.m33 * mat.m41 - mat.m31 * mat.m43) +
			mat.m13 * (mat.m31 * mat.m42 - mat.m32 * mat.m41)) * fInvDet;
		m43 = (mat.m11 * (mat.m23 * mat.m42 - mat.m22 * mat.m43) +
			mat.m12 * (mat.m21 * mat.m43 - mat.m23 * mat.m41) +
			mat.m13 * (mat.m22 * mat.m41 - mat.m21 * mat.m42)) * fInvDet;
		m44 = 1.0f;

		return true;
	}
	return false;
}

//Function to Transpose
void Matrix4::Transpose()
{
	Matrix4 result;
	result.m11 = m11;
	result.m12 = m21;
	result.m13 = m31;
	result.m14 = m41;
	result.m21 = m12;
	result.m22 = m22;
	result.m23 = m32;
	result.m24 = m42;
	result.m31 = m13;
	result.m32 = m23;
	result.m33 = m33;
	result.m34 = m43;
	result.m41 = m14;
	result.m42 = m24;
	result.m43 = m34;
	result.m44 = m44;
}

//Matrix Rotation Functions
void Matrix4::RotateX(float fAngle)
{
	const float co = cosf(fAngle);
	const float si = sinf(fAngle);
	m11 = 1.0f; m12 = 0.0f; m13 = 0.0f; m14 = 0.0f;
	m21 = 0.0f; m22 = co;   m23 = si;   m24 = 0.0f;
	m31 = 0.0f; m32 = -si;  m33 = co;   m34 = 0.0f;
	m41 = 0.0f;	m42 = 0.0f;	m43 = 0.0f; m44 = 1.0f;
}

void Matrix4::RotateY(float fAngle)
{
	const float co = cosf(fAngle);
	const float si = sinf(fAngle);
	m11 = co;   m12 = 0.0f; m13 = -si;  m14 = 0.0f;
	m21 = 0.0f; m22 = 1.0f; m23 = 0.0f; m24 = 0.0f;
	m31 = si;   m32 = 0.0f; m33 = co;   m34 = 0.0f;
	m41 = 0.0f;	m42 = 0.0f;	m43 = 0.0f; m44 = 1.0f;
}

void Matrix4::RotateZ(float fAngle)
{
	const float co = cosf(fAngle);
	const float si = sinf(fAngle);
	m11 = co;   m12 = si;   m13 = 0.0f; m14 = 0.0f;
	m21 = -si;  m22 = co;   m23 = 0.0f; m24 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = 1.0f; m34 = 0.0f;
	m41 = 0.0f;	m42 = 0.0f;	m43 = 0.0f; m44 = 1.0f;
}

//Matrix Scale
void Matrix4::Scale(float fXScalar, float fYScalar, float fZScalar)
{
	m11 = m11 * fXScalar; m12 = 0.0f;           m13 = 0.0f;           m14 = 0.0f;
	m21 = 0.0f;           m22 = m22 * fYScalar; m23 = 0.0f;           m24 = 0.0f;
	m31 = 0.0f;           m32 = 0.0f;           m33 = m33 * fZScalar; m34 = 0.0f;
	m41 = 0.0f;			  m42 = 0.0f;           m43 = 0.0f;           m44 = 1.0f;
}