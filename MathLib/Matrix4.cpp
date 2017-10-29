////////////////////////////////////////////////////////////////////
// File: <Matrix4.cpp>
// Author: <Alex Kitching>
// Date Created: <24/02/17>
// Brief: <Source file for the Matrix 4x4 Class.>
////////////////////////////////////////////////////////////////////

#include "Matrix4.h"

#include <math.h>

const Matrix4 Matrix4::Identity{ Vector4{1.f,0.f,0.f,0.f}, Vector4{0.f,1.f,0.f,0.f}, Vector4{0.f,0.f,1.f,0.f}, Vector4{0.f,0.f,0.f,1.f} };

Matrix4::Matrix4()
{

}

Matrix4::Matrix4(const float a_fM11, const float a_fM12, const float a_m13, const float a_m14, const float a_m21, const float a_m22, const float a_m23, const float a_m24, const float a_m31, const float a_m32, const float a_m33, const float a_m34, const float a_m41, const float a_m42, const float a_m43, const float a_m44)
{
	m11 = a_fM11, m12 = a_fM12, m13 = a_m13, m14 = a_m14;
	m21 = a_m21, m22 = a_m22, m23 = a_m23, m24 = a_m24;
	m31 = a_m31, m32 = a_m32, m33 = a_m33, m34 = a_m34;
	m41 = a_m41, m42 = a_m42, m43 = a_m43, m44 = a_m44;
}

Matrix4::Matrix4(const Vector4 x, const Vector4 y, const Vector4 z, const Vector4 w)
{
	xAxis = x;
	yAxis = y;
	zAxis = z;
	Translation = w;
}

Matrix4::Matrix4(const Matrix4 & a_mat)
{
	m11 = a_mat.m11;
	m12 = a_mat.m12;
	m13 = a_mat.m13;
	m14 = a_mat.m14;
	m21 = a_mat.m21;
	m22 = a_mat.m22;
	m23 = a_mat.m23;
	m24 = a_mat.m24;
	m31 = a_mat.m31;
	m32 = a_mat.m32;
	m33 = a_mat.m33;
	m34 = a_mat.m34;
	m41 = a_mat.m41;
	m42 = a_mat.m42;
	m43 = a_mat.m43;
	m44 = a_mat.m44;
}

Matrix4::~Matrix4()
{
}

float Matrix4::GetValue(const unsigned int row, const unsigned int col) const
{
	return m[row][col];
}

Vector4 Matrix4::GetRow(const unsigned int row) const
{
	return Vector4(m[row][0], m[row][1], m[row][2] , m[row][3]);
}

void Matrix4::GetRow(const unsigned int row, Vector4 a_vector) const
{
	a_vector = Vector4(m[row][0], m[row][1], m[row][2], m[row][3]);
}

Vector4 Matrix4::GetCol(const unsigned int col) const
{
	return Vector4(m[0][col], m[1][col], m[2][col], m[3][col]);
}

void Matrix4::GetCol(const unsigned int col, Vector4 a_vector) const
{
	a_vector = Vector4(m[0][col], m[1][col], m[2][col], m[3][col]);
}

void Matrix4::SetValue(const unsigned int row, const unsigned int col, const float a_value)
{
	m[row][col] = a_value;
}

void Matrix4::SetRow(const unsigned int row, const float a_value)
{
	m[row][0] = a_value, m[row][1] = a_value, m[row][2] = a_value, m[row][3] = a_value;
}

void Matrix4::SetRow(const unsigned int row, const Vector4 a_vector)
{
	float x = 0.f, y = 0.f, z = 0.f, w = 0.f;
	a_vector.GetX(x);
	a_vector.GetY(y);
	a_vector.GetZ(z);
	a_vector.GetW(w);
	m[row][0] = x, m[row][1] = y, m[row][2] = z, m[row][3] = w;
}

void Matrix4::SetCol(const unsigned int col, const float a_value)
{
	m[0][col] = a_value, m[1][col] = a_value, m[2][col] = a_value, m[3][col] = a_value;
}

void Matrix4::SetCol(const unsigned int col, const Vector4 a_vector)
{
	float x = 0.f, y = 0.f, z = 0.f, w = 0.f;
	a_vector.GetX(x);
	a_vector.GetY(y);
	a_vector.GetZ(z);
	a_vector.GetW(w);
	m[0][col] = x, m[1][col] = y, m[2][col] = z, m[3][col] = w;
}

Matrix4::operator float*()
{
	return i;
}

Matrix4::operator const float*() const
{
	return i;
}

float Matrix4::operator[](const unsigned int index) const
{
	return i[index];
}

bool Matrix4::operator==(const Matrix4 & a_mat) const
{
	m11 == a_mat.m11;
	m12 == a_mat.m12;
	m13 == a_mat.m13;
	m14 == a_mat.m14;
	m21 == a_mat.m21;
	m22 == a_mat.m22;
	m23 == a_mat.m23;
	m24 == a_mat.m24;
	m31 == a_mat.m31;
	m32 == a_mat.m32;
	m33 == a_mat.m33;
	m34 == a_mat.m34;
	m41 == a_mat.m41;
	m42 == a_mat.m42;
	m43 == a_mat.m43;
	m44 == a_mat.m44;

	return this;
}

bool Matrix4::operator!=(const Matrix4 & a_mat) const
{
	m11 != a_mat.m11;
	m12 != a_mat.m12;
	m13 != a_mat.m13;
	m14 != a_mat.m14;
	m21 != a_mat.m21;
	m22 != a_mat.m22;
	m23 != a_mat.m23;
	m24 != a_mat.m24;
	m31 != a_mat.m31;
	m32 != a_mat.m32;
	m33 != a_mat.m33;
	m34 != a_mat.m34;
	m41 != a_mat.m41;
	m42 != a_mat.m42;
	m43 != a_mat.m43;
	m44 != a_mat.m44;

	return this;
}

Matrix4 Matrix4::operator+(const Matrix4 & a_mat)  const
{
	return Matrix4(m11 + a_mat.m11, m12 + a_mat.m12, m13 + a_mat.m13, m14 + a_mat.m14,
		           m21 + a_mat.m21, m22 + a_mat.m22, m23 + a_mat.m23, m24 + a_mat.m24,
		           m31 + a_mat.m31, m32 + a_mat.m32, m33 + a_mat.m33, m34 + a_mat.m34,
		           m41 + a_mat.m41, m42 + a_mat.m42, m43 + a_mat.m43, m44 + a_mat.m44);
}

Matrix4 Matrix4::operator+(const float & a_fValue)  const
{
	return Matrix4(m11 + a_fValue, m12 + a_fValue, m13 + a_fValue, m14 + a_fValue,
		           m21 + a_fValue, m22 + a_fValue, m23 + a_fValue, m24 + a_fValue,
		           m31 + a_fValue, m32 + a_fValue, m33 + a_fValue, m34 + a_fValue,
		           m41 + a_fValue, m42 + a_fValue, m43 + a_fValue, m44 + a_fValue);
}

Matrix4 Matrix4::operator-(const Matrix4 & a_mat) const
{
	return Matrix4(m11 - a_mat.m11, m12 - a_mat.m12, m13 - a_mat.m13, m14 - a_mat.m14,
		           m21 - a_mat.m21, m22 - a_mat.m22, m23 - a_mat.m23, m24 - a_mat.m24,
		           m31 - a_mat.m31, m32 - a_mat.m32, m33 - a_mat.m33, m34 - a_mat.m34,
		           m41 - a_mat.m41, m42 - a_mat.m42, m43 - a_mat.m43, m44 - a_mat.m44);
}

Matrix4 Matrix4::operator-(const float & a_fValue) const
{
	return Matrix4(m11 - a_fValue, m12 - a_fValue, m13 - a_fValue, m14 - a_fValue,
		           m21 - a_fValue, m22 - a_fValue, m23 - a_fValue, m24 - a_fValue,
		           m31 - a_fValue, m32 - a_fValue, m33 - a_fValue, m34 - a_fValue,
		           m41 - a_fValue, m42 - a_fValue, m43 - a_fValue, m44 - a_fValue);
}

Matrix4 Matrix4::operator*(const Matrix4 & a_mat) const
{
	Matrix4 mResult;
	mResult.m11 = (m11 * a_mat.m11) + (m12 * a_mat.m21) + (m13 * a_mat.m31);
	mResult.m12 = (m11 * a_mat.m12) + (m12 * a_mat.m22) + (m13 * a_mat.m32);
	mResult.m13 = (m11 * a_mat.m13) + (m12 * a_mat.m23) + (m13 * a_mat.m33);
	mResult.m14 = (m11 * a_mat.m14) + (m12 * a_mat.m24) + (m13 * a_mat.m34);

	mResult.m21 = (m21 * a_mat.m11) + (m22 * a_mat.m21) + (m23 * a_mat.m31);
	mResult.m22 = (m21 * a_mat.m12) + (m22 * a_mat.m22) + (m23 * a_mat.m32);
	mResult.m23 = (m21 * a_mat.m13) + (m22 * a_mat.m23) + (m23 * a_mat.m33);
	mResult.m24 = (m21 * a_mat.m14) + (m22 * a_mat.m24) + (m23 * a_mat.m34);

	mResult.m31 = (m31 * a_mat.m11) + (m32 * a_mat.m21) + (m33 * a_mat.m31);
	mResult.m32 = (m31 * a_mat.m12) + (m32 * a_mat.m22) + (m33 * a_mat.m32);
	mResult.m33 = (m31 * a_mat.m13) + (m32 * a_mat.m23) + (m33 * a_mat.m33);
	mResult.m34 = (m31 * a_mat.m14) + (m32 * a_mat.m24) + (m33 * a_mat.m34);

	mResult.m41 = (m41 * a_mat.m11) + (m42 * a_mat.m21) + (m43 * a_mat.m31);
	mResult.m42 = (m41 * a_mat.m12) + (m42 * a_mat.m22) + (m43 * a_mat.m32);
	mResult.m43 = (m41 * a_mat.m13) + (m42 * a_mat.m23) + (m43 * a_mat.m33);
	mResult.m44 = (m41 * a_mat.m14) + (m42 * a_mat.m24) + (m43 * a_mat.m34);
	return mResult;
}

Matrix4 Matrix4::operator*(const float & a_fValue) const
{
	Matrix4 mResult;
	mResult.m11 = (m11 * a_fValue) + (m12 * a_fValue) + (m13 * a_fValue);
	mResult.m12 = (m11 * a_fValue) + (m12 * a_fValue) + (m13 * a_fValue);
	mResult.m13 = (m11 * a_fValue) + (m12 * a_fValue) + (m13 * a_fValue);
	mResult.m14 = (m11 * a_fValue) + (m12 * a_fValue) + (m13 * a_fValue);

	mResult.m21 = (m21 * a_fValue) + (m22 * a_fValue) + (m23 * a_fValue);
	mResult.m22 = (m21 * a_fValue) + (m22 * a_fValue) + (m23 * a_fValue);
	mResult.m23 = (m21 * a_fValue) + (m22 * a_fValue) + (m23 * a_fValue);
	mResult.m24 = (m21 * a_fValue) + (m22 * a_fValue) + (m23 * a_fValue);

	mResult.m31 = (m31 * a_fValue) + (m32 * a_fValue) + (m33 * a_fValue);
	mResult.m32 = (m31 * a_fValue) + (m32 * a_fValue) + (m33 * a_fValue);
	mResult.m33 = (m31 * a_fValue) + (m32 * a_fValue) + (m33 * a_fValue);
	mResult.m34 = (m31 * a_fValue) + (m32 * a_fValue) + (m33 * a_fValue);

	mResult.m41 = (m41 * a_fValue) + (m42 * a_fValue) + (m43 * a_fValue);
	mResult.m42 = (m41 * a_fValue) + (m42 * a_fValue) + (m43 * a_fValue);
	mResult.m43 = (m41 * a_fValue) + (m42 * a_fValue) + (m43 * a_fValue);
	mResult.m44 = (m41 * a_fValue) + (m42 * a_fValue) + (m43 * a_fValue);
	return mResult;
}

Vector4 Matrix4::operator*(const Vector4 & a_vec)  const
{
	float fX = (m11 * a_vec.GetX()) + (m12 * a_vec.GetY()) + (m13 * a_vec.GetZ()) + (m14 * a_vec.GetW());
	float fY = (m21 * a_vec.GetX()) + (m22 * a_vec.GetY()) + (m23 * a_vec.GetZ()) + (m24 * a_vec.GetW());
	float fZ = (m31 * a_vec.GetX()) + (m32 * a_vec.GetY()) + (m33 * a_vec.GetZ()) + (m34 * a_vec.GetW());
	float fW = (m41 * a_vec.GetX()) + (m42 * a_vec.GetY()) + (m43 * a_vec.GetZ()) + (m44 * a_vec.GetW());
	return Vector4(fX, fY, fZ, fW);
}

void Matrix4::Transpose()
{
	Matrix4 mat = *this;
	m11 = mat.m11; m12 = mat.m21; m13 = mat.m31, m14 = mat.m41;
	m21 = mat.m12; m22 = mat.m22; m23 = mat.m32, m24 = mat.m42;
	m31 = mat.m13; m32 = mat.m23; m33 = mat.m33, m34 = mat.m43;
	m41 = mat.m14, m42 = mat.m24, m43 = mat.m34, m44 = mat.m44;
}

float Matrix4::Determinant3() const
{
	return (m11 * ((m22 * m33) - (m23 * m32))  //1st Col
		  - m12 * ((m21 * m33) - (m23 * m31))  //2nd Col
	      + m13 * ((m21 * m32) - (m22 * m31)));//3rd Col
}

bool Matrix4::Inverse()
{
	const float fDeter = Determinant3();
	if (fDeter != 0.0f)
	{
		const float fInvDeter = 1 / fDeter;

		Matrix4 mat = *this;
		m11 = ((mat.m22 * mat.m33) - (mat.m23 * mat.m32)) * fInvDeter;
		m12 = ((mat.m13 * mat.m32) - (mat.m12 * mat.m33)) * fInvDeter;
		m13 = ((mat.m12 * mat.m23) - (mat.m13 * mat.m22)) * fInvDeter;
		m14 = 0.0f;

		m21 = ((mat.m23 * mat.m31) - (mat.m21 * mat.m33)) * fInvDeter;
		m22 = ((mat.m11 * mat.m33) - (mat.m13 * mat.m31)) * fInvDeter;
		m23 = ((mat.m13 * mat.m21) - (mat.m11 * mat.m23)) * fInvDeter;
		m24 = 0.0f;

		m31 = ((mat.m21 * mat.m32) - (mat.m22 * mat.m31)) * fInvDeter;
		m32 = ((mat.m12 * mat.m31) - (mat.m11 * mat.m32)) * fInvDeter;
		m33 = ((mat.m11 * mat.m22) - (mat.m12 * mat.m21)) * fInvDeter;
		m34 = 0.0f;

		m41 = (mat.m21 * ((mat.m33 * mat.m42) - (mat.m32 * mat.m43)) +
			   mat.m22 * ((mat.m31 * mat.m43) - (mat.m33 * mat.m41)) +
			   mat.m23 * ((mat.m32 * mat.m41) - (mat.m31 * mat.m42))) * fInvDeter;
		m42 = (mat.m11 * ((mat.m32 * mat.m43) - (mat.m33 * mat.m42)) +
			   mat.m12 * ((mat.m33 * mat.m41) - (mat.m31 * mat.m43)) +
			   mat.m13 * ((mat.m31 * mat.m42) - (mat.m32 * mat.m41))) * fInvDeter;
		m43 = (mat.m11 * ((mat.m23 * mat.m42) - (mat.m22 * mat.m43)) +
			   mat.m12 * ((mat.m21 * mat.m43) - (mat.m23 * mat.m41)) +
			   mat.m13 * ((mat.m22 * mat.m41) - (mat.m21 * mat.m42))) * fInvDeter;
		m44 = 1.0f;

		return true;
	}
	else
	{
		return false;
	}
}

void Matrix4::RotateX(const float fAngle)
{
	const float co = cosf(fAngle);
	const float si = sinf(fAngle);
	m11 = 1.0f; m12 = 0.0f; m13 = 0.0f; m14 = 0.0f;
	m21 = 0.0f; m22 = co;   m23 = si;   m24 = 0.0f;
	m31 = 0.0f; m32 = -si;  m33 = co;   m34 = 0.0f;
	m41 = 0.0f; m42 = 0.0f; m43 = 0.0f; m44 = 1.0f;
}

void Matrix4::RotateY(const float fAngle)
{
	const float co = cosf(fAngle);
	const float si = sinf(fAngle);
	m11 = co;   m12 = 0.0f; m13 = -si;  m14 = 0.0f;
	m21 = 0.0f; m22 = 1.0f; m23 = 0.0f; m24 = 0.0f;
	m31 = si;   m32 = 0.0f; m33 = co;   m34 = 0.0f;
	m41 = 0.0f; m42 = 0.0f; m43 = 0.0f; m44 = 1.0f;
}

void Matrix4::RotateZ(const float fAngle)
{
	const float co = cosf(fAngle);
	const float si = sinf(fAngle);
	m11 = co;   m12 = si;   m13 = 0.0f; m14 = 0.0f;
	m21 = -si;  m22 = co;   m23 = 0.0f; m24 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = 1.0f; m34 = 0.0f;
	m41 = 0.0f; m42 = 0.0f; m43 = 0.0f; m44 = 1.0f;
}

void Matrix4::Scale(const float fXScalar, const float fYScalar, const float fZScalar)
{
	m11 = m11 * fXScalar; m12 = 0.0f;           m13 = 0.0f;           m14 = 0.0f;
	m21 = 0.0f;           m22 = m22 * fYScalar; m23 = 0.0f;           m24 = 0.0f;
	m31 = 0.0f;           m32 = 0.0f;           m33 = m33 * fZScalar; m34 = 0.0f;
	m41 = 0.0f;           m42 = 0.0f;           m43 = 0.0f;           m44 = 0.0f;
}


