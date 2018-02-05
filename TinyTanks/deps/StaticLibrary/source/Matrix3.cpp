#include "Matrix3.h"

const Matrix3 Matrix3::IDENTITY = Matrix3(1.0f, 0.f, 0.f, 0.f, 1.0f, 0.f, 0.f, 0.f, 1.f);
const Matrix3 Matrix3::ZERO = Matrix3(0.0f, 0.f, 0.f, 0.f, 0.0f, 0.f, 0.f, 0.f, 0.f);


Matrix3::Matrix3()
{

}

Matrix3::Matrix3(float a_11, float a_12, float a_13, float a_21, float a_22, float a_23, float a_31, float a_32, float a_33) :
	m11(a_11), m12(a_12), m13(a_13),
	m21(a_21), m22(a_22), m23(a_23),
	m31(a_31), m32(a_32), m33(a_33)
{

}

void Matrix3::SetRow(const int& row, const Vector3& a_v1)
{
	if (row >= 0 && row < 3)
	{
		mat[row][0] = a_v1.GetX();
		mat[row][1] = a_v1.GetY();
		mat[row][2] = a_v1.GetZ();
	}
}

void Matrix3::GetRow(const int row, Vector3& a_v1) const
{
	if (row >= 0 && row < 3)
	{
		a_v1.SetX(mat[row][0]);
		a_v1.SetY(mat[row][1]);
		a_v1.SetZ(mat[row][2]);
	}
}


void Matrix3::SetColumn(const int& col, const Vector3& a_v1)
{
	if (col >= 0 && col < 3)
	{
		mat[0][col] = a_v1.GetX();
		mat[1][col] = a_v1.GetY();
		mat[2][col] = a_v1.GetZ();
	}
}
void Matrix3::GetColumn(const int col, Vector3& a_v1) const
{
	if (col >= 0 && col < 3)
	{
		a_v1.SetX(mat[0][col]);
		a_v1.SetY(mat[1][col]);
		a_v1.SetZ(mat[2][col]);
	}
}

//Function to Add two Matrices
Matrix3 Matrix3::Add(Matrix3& a_m1, Matrix3& a_m2)
{
	Matrix3 result;
	result = a_m1 + a_m2;
	return result;
}

//Function to Subtract two Matrices
Matrix3 Matrix3::Subtract(Matrix3& a_m1, Matrix3& a_m2)
{
	Matrix3 result;
	result = a_m1 - a_m2;
	return result;
}

//Function to Multiply two Matrices
Matrix3 Multiply(const Matrix3& a_m1, const Matrix3& a_m2)
{
	Matrix3 result;
	result = a_m1 * a_m2;
	return result;
}

//Operators
Matrix3::operator float*()
{
	return static_cast<float*>(&m11);
}

Matrix3::operator const float*() const
{
	return static_cast<const float*>(&m11);
}

Matrix3 Matrix3::operator+(const Matrix3& a_m3) const
{
	Matrix3 result;
	result.m11 = m11 + a_m3.m11;
	result.m12 = m12 + a_m3.m12;
	result.m13 = m13 + a_m3.m13;
	result.m21 = m21 + a_m3.m21;
	result.m22 = m22 + a_m3.m22;
	result.m23 = m23 + a_m3.m23;
	result.m31 = m31 + a_m3.m31;
	result.m32 = m32 + a_m3.m32;
	result.m33 = m33 + a_m3.m33;

	//result.xAxis = xAxis + a_m3.xAxis;
	//result.yAxis = yAxis + a_m3.yAxis;
	//result.zAxis = zAxis + a_m3.zAxis;

	return result;
}

Matrix3 Matrix3::operator-(const Matrix3& a_m3) const
{
	Matrix3 result;
	result.m11 = m11 - a_m3.m11;
	result.m12 = m12 - a_m3.m12;
	result.m13 = m13 - a_m3.m13;
	result.m21 = m21 - a_m3.m21;
	result.m22 = m22 - a_m3.m22;
	result.m23 = m23 - a_m3.m23;
	result.m31 = m31 - a_m3.m31;
	result.m32 = m32 - a_m3.m32;
	result.m33 = m33 - a_m3.m33;

	//result.xAxis = xAxis - a_m3.xAxis;
	//result.yAxis = yAxis - a_m3.yAxis;
	//result.zAxis = zAxis - a_m3.zAxis;

	return result;
}

Matrix3 Matrix3::operator*(const Matrix3& a_m3) const
{
	Matrix3 result;
	result.m11 = m11 * a_m3.m11 + m12 * a_m3.m21 + m13 * a_m3.m31;
	result.m12 = m11 * a_m3.m12 + m12 * a_m3.m22 + m13 * a_m3.m32;
	result.m13 = m11 * a_m3.m13 + m12 * a_m3.m23 + m13 * a_m3.m33;

	result.m21 = m21 * a_m3.m11 + m22 * a_m3.m21 + m23 * a_m3.m31;
	result.m22 = m21 * a_m3.m12 + m22 * a_m3.m22 + m23 * a_m3.m32;
	result.m23 = m21 * a_m3.m13 + m22 * a_m3.m23 + m23 * a_m3.m33;

	result.m31 = m31 * a_m3.m11 + m32 * a_m3.m21 + m33 * a_m3.m31;
	result.m32 = m31 * a_m3.m12 + m32 * a_m3.m22 + m33 * a_m3.m32;
	result.m33 = m31 * a_m3.m13 + m32 * a_m3.m23 + m33 * a_m3.m33;

	return result;
}

bool Matrix3::operator==(const Matrix3& a_m3) const
{
	bool equals = true;
	equals &= GetFloatPrecision(m11, 1) == GetFloatPrecision(a_m3.m11, 1);
	equals &= GetFloatPrecision(m12, 1) == GetFloatPrecision(a_m3.m12, 1);
	equals &= GetFloatPrecision(m13, 1) == GetFloatPrecision(a_m3.m13, 1);
	equals &= GetFloatPrecision(m21, 1) == GetFloatPrecision(a_m3.m21, 1);
	equals &= GetFloatPrecision(m22, 1) == GetFloatPrecision(a_m3.m22, 1);
	equals &= GetFloatPrecision(m23, 1) == GetFloatPrecision(a_m3.m23, 1);
	equals &= GetFloatPrecision(m31, 1) == GetFloatPrecision(a_m3.m31, 1);
	equals &= GetFloatPrecision(m32, 1) == GetFloatPrecision(a_m3.m32, 1);
	equals &= GetFloatPrecision(m33, 1) == GetFloatPrecision(a_m3.m33, 1);

	return equals;
}

//Function Matrix3 Determinant
float Matrix3::Determinant() const
{
	return (m11 * (m22 * m33 - m23 * m32) +
		m12 * (m23 * m31 - m21 * m33) +
		m13 * (m21 * m32 - m22 * m31));
}

//Function Matrix3 Inverse
bool Matrix3::Inverse()
{
	float fDeterminant = Determinant();
	if (fDeterminant != 0.0f)
	{
		const float fInvDet = 1 / fDeterminant;

		Matrix3 mat = *this;
		m11 = (mat.m22 * mat.m33 - mat.m23 * mat.m32) * fInvDet;
		m12 = (mat.m13 * mat.m32 - mat.m12 * mat.m33) * fInvDet;
		m13 = (mat.m12 * mat.m23 - mat.m13 * mat.m22) * fInvDet;

		m21 = (mat.m23 * mat.m31 - mat.m21 * mat.m33) * fInvDet;
		m22 = (mat.m11 * mat.m33 - mat.m13 * mat.m31) * fInvDet;
		m23 = (mat.m13 * mat.m21 - mat.m11 * mat.m23) * fInvDet;

		m31 = (mat.m21 * mat.m32 - mat.m22 * mat.m31) * fInvDet;
		m32 = (mat.m12 * mat.m31 - mat.m11 * mat.m32) * fInvDet;
		m33 = (mat.m11 * mat.m22 - mat.m12 * mat.m21) * fInvDet;

		return true;
	}
	return false;
}

//Function to Transpose Matrix3
void Matrix3::Transpose()
{
	float temp;
	m11, m22, m33;
	temp = m12; m12 = m21; m21 = temp;
	temp = m13; m13 = m31; m31 = temp;
	temp = m23; m23 = m32; m32 = temp;
}

//Matrix Rotation Functions
void Matrix3::Rotate(float fAngle)
{
	const float co = cosf(fAngle);
	const float si = sinf(fAngle);
	m11 = co;   m12 = si;    m13 = 0.0f;
	m21 = -si;  m22 = co;    m23 = 0.0f;
	m31 = 0.0f; m32 = 0.0f;  m33 = 1.0f;
}

//Matrix Scale 2 Arguments
void Matrix3::Scale(float fXScalar, float fYScalar)
{
	m11 = m11 * fXScalar; m12 = 0.0f;           m13 = 0.0f;
	m21 = 0.0f;           m22 = m22 * fYScalar; m23 = 0.0f;
	m31 = 0.0f;           m32 = 0.0f;           m33 = 1.0f;
}

//Matrix Scale 1 Argument
void Matrix3::Scale(float fScalar)
{
	m11 = m11 * fScalar;  m12 = 0.0f;           m13 = 0.0f;
	m21 = 0.0f;           m22 = m22 * fScalar;  m23 = 0.0f;
	m31 = 0.0f;           m32 = 0.0f;           m33 = 1.0f;
}

float Matrix3::GetFloatPrecision(float value, int precision) const
{
	return ((int)(value * (int)pow(10, precision) + .5) / (float)pow(10, precision));
}