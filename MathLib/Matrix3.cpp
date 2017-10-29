////////////////////////////////////////////////////////////////////
// File: <Matrix3.cpp>
// Author: <Alex Kitching>
// Date Created: <16/02/17>
// Brief: <Source file for the Matrix 3x3 Class.>
////////////////////////////////////////////////////////////////////

#include "Matrix3.h"

#include "Vector2.h"
#include <math.h>

const Matrix3 Matrix3::Identity = { Vector3::Right , Vector3::Up, Vector3::Forward };

Matrix3::Matrix3()
{
}

Matrix3::Matrix3(const float a_m11, const float a_m12, const float a_m13, const float a_m21, const float a_m22, const float a_m23, const float a_m31, const float a_m32, const float a_m33)
{
	m11 = a_m11, m12 = a_m12, m13 = a_m13;
	m21 = a_m21, m22 = a_m22, m23 = a_m23;
	m31 = a_m31, m32 = a_m32, m33 = a_m33;
}

Matrix3::Matrix3(const Vector3 x, const Vector3 y, const Vector3 z)
{
	xAxis = x;
	yAxis = y;
	zAxis = z;
}

Matrix3::Matrix3(const Matrix3 & a_mat)
{
	m11 = a_mat.m11;
	m12 = a_mat.m12;
	m13 = a_mat.m13;
	m21 = a_mat.m21;
	m22 = a_mat.m22;
	m23 = a_mat.m23;
	m31 = a_mat.m31;
	m32 = a_mat.m32;
	m33 = a_mat.m33;
}

Matrix3::~Matrix3()
{
}

float Matrix3::GetValue(const unsigned int row, const unsigned int col) const
{
	return m[row][col];
}

Vector3 Matrix3::GetRow(const unsigned int row) const
{
	return Vector3(m[row][0], m[row][1], m[row][2]);
}

void Matrix3::GetRow(const unsigned int row, Vector3 a_vector) const
{
	a_vector = Vector3(m[row][0], m[row][1], m[row][2]);
}

Vector3 Matrix3::GetCol(const unsigned int col) const
{
	return Vector3(m[0][col], m[1][col], m[2][col]);
}

void Matrix3::GetCol(const unsigned int col, Vector3 a_vector) const
{
	a_vector = Vector3(m[0][col], m[1][col], m[2][col]);
}

void Matrix3::SetValue(const unsigned int row, const unsigned int col, const float a_value)
{
	m[row][col] = a_value;
}

void Matrix3::SetRow(const unsigned int row, const float a_value)
{
	m[row][0] = a_value, m[row][1] = a_value, m[row][2] = a_value;
}

void Matrix3::SetRow(const unsigned int row, const Vector3 a_vector)
{
	float x = 0.f, y = 0.f, z = 0.f;
	a_vector.GetX(x);
	a_vector.GetY(y);
	a_vector.GetZ(z);
	m[row][0] = x, m[row][1] = y, m[row][2] = z;
}

void Matrix3::SetCol(const unsigned int col, const float value)
{
	m[0][col] = value, m[1][col] = value, m[2][col] = value;
}

void Matrix3::SetCol(const unsigned int col, const Vector3 a_vector)
{
	float x = 0.f, y = 0.f, z = 0.f;
	a_vector.GetX(x);
	a_vector.GetY(y);
	a_vector.GetZ(z);
	m[0][col] = x, m[1][col] = y, m[2][col] = z;
}

Matrix3::operator float*()
{
	return i;
}

Matrix3::operator const float*() const
{
	return i;
}

float Matrix3::operator[](const unsigned int index) const
{
	return i[index];
}

bool Matrix3::operator==(const Matrix3 & a_mat) const
{
	m11 == a_mat.m11;
	m12 == a_mat.m12;
	m13 == a_mat.m13;
	m21 == a_mat.m21;
	m22 == a_mat.m22;
	m23 == a_mat.m23;
	m31 == a_mat.m31;
	m32 == a_mat.m32;
	m33 == a_mat.m33;
	return this;
}

bool Matrix3::operator!=(const Matrix3 & a_mat) const
{
	m11 != a_mat.m11;
	m12 != a_mat.m12;
	m13 != a_mat.m13;
	m21 != a_mat.m21;
	m22 != a_mat.m22;
	m23 != a_mat.m23;
	m31 != a_mat.m31;
	m32 != a_mat.m32;
	m33 != a_mat.m33;
	return this;
}

Matrix3 Matrix3::operator+(const Matrix3 & a_mat)
{
	return Matrix3(m11 + a_mat.m11, m12 + a_mat.m12, m13 + a_mat.m13,
		           m21 + a_mat.m21, m22 + a_mat.m22, m23 + a_mat.m23,
		           m31 + a_mat.m31, m32 + a_mat.m32, m33 + a_mat.m33);
}

Matrix3 Matrix3::operator+(const float & a_value)
{
	return Matrix3(m11 + a_value, m12 + a_value, m13 + a_value,
				   m21 + a_value, m22 + a_value, m23 + a_value,
				   m31 + a_value, m32 + a_value, m33 + a_value);
}

Matrix3 Matrix3::operator-(const Matrix3 & a_mat)
{
	return Matrix3(m11 - a_mat.m11, m12 - a_mat.m12, m13 - a_mat.m13,
				   m21 - a_mat.m21, m22 - a_mat.m22, m23 - a_mat.m23,
				   m31 - a_mat.m31, m32 - a_mat.m32, m33 - a_mat.m33);
}

Matrix3 Matrix3::operator-(const float & a_value)
{
	return Matrix3(m11 - a_value, m12 - a_value, m13 - a_value,
				   m21 - a_value, m22 - a_value, m23 - a_value,
				   m31 - a_value, m32 - a_value, m33 - a_value);
}

Matrix3 Matrix3::operator*(const Matrix3 & a_mat)
{
	Matrix3 mResult;
	mResult.m11 = (m11 * a_mat.m11) + (m12 * a_mat.m21) + (m13 * a_mat.m31);
	mResult.m12 = (m11 * a_mat.m12) + (m12 * a_mat.m22) + (m13 * a_mat.m32);
	mResult.m13 = (m11 * a_mat.m13) + (m12 * a_mat.m23) + (m13 * a_mat.m33);

	mResult.m21 = (m21 * a_mat.m11) + (m22 * a_mat.m21) + (m23 * a_mat.m31);
	mResult.m22 = (m21 * a_mat.m12) + (m22 * a_mat.m22) + (m23 * a_mat.m32);
	mResult.m23 = (m21 * a_mat.m13) + (m22 * a_mat.m23) + (m23 * a_mat.m33);

	mResult.m31 = (m31 * a_mat.m11) + (m32 * a_mat.m21) + (m33 * a_mat.m31);
	mResult.m32 = (m31 * a_mat.m12) + (m32 * a_mat.m22) + (m33 * a_mat.m32);
	mResult.m33 = (m31 * a_mat.m13) + (m32 * a_mat.m23) + (m33 * a_mat.m33);
	return mResult;
}

Matrix3 Matrix3::operator*(const float & a_value)
{

	Matrix3 mResult;
	mResult.m11 = (m11 * a_value) + (m12 * a_value) + (m13 * a_value);
	mResult.m12 = (m11 * a_value) + (m12 * a_value) + (m13 * a_value);
	mResult.m13 = (m11 * a_value) + (m12 * a_value) + (m13 * a_value);
										  					
	mResult.m21 = (m21 * a_value) + (m22 * a_value) + (m23 * a_value);
	mResult.m22 = (m21 * a_value) + (m22 * a_value) + (m23 * a_value);
	mResult.m23 = (m21 * a_value) + (m22 * a_value) + (m23 * a_value);
					
	mResult.m31 = (m31 * a_value) + (m32 * a_value) + (m33 * a_value);
	mResult.m32 = (m31 * a_value) + (m32 * a_value) + (m33 * a_value);
	mResult.m33 = (m31 * a_value) + (m32 * a_value) + (m33 * a_value);
	return mResult;
}

Vector3 Matrix3::operator*(const Vector3 & a_vec)
{
	float fX = ( m11 * a_vec.GetX() ) + ( m12 * a_vec.GetY() ) + ( m13 * a_vec.GetZ() );
	float fY = ( m21 * a_vec.GetX() ) + ( m22 * a_vec.GetY() ) + ( m23 * a_vec.GetZ() );
	float fZ = ( m31 * a_vec.GetX() ) + ( m32 * a_vec.GetY() ) + ( m33 * a_vec.GetZ() );
	
	return Vector3(fX, fY, fZ);
}

Vector3 Matrix3::operator*(const Vector3* a_vec)
{
	float fX = (m11 * a_vec->GetX()) + (m12 * a_vec->GetY()) + (m13 * a_vec->GetZ());
	float fY = (m21 * a_vec->GetX()) + (m22 * a_vec->GetY()) + (m23 * a_vec->GetZ());
	float fZ = (m31 * a_vec->GetX()) + (m32 * a_vec->GetY()) + (m33 * a_vec->GetZ());

	return Vector3(fX, fY, fZ);
}

void Matrix3::Transpose()
{
	Matrix3 mat = *this;
	m11 = mat.m11; m12 = mat.m21; m13 = mat.m31;
	m21 = mat.m12; m22 = mat.m22; m23 = mat.m32;
	m31 = mat.m13; m32 = mat.m23; m33 = mat.m33;
}

float Matrix3::Determinant() const
{
	return (m11 * ((m22 * m33) - (m23 * m32)) //1st Col
	   	   - m12 * ((m21 * m33) - (m23 * m31)) //2nd Col
	   	   + m13 * ((m21 * m32) - (m22 * m31)));//3rd Col
}

bool Matrix3::Inverse()
{
	float fDeter = Determinant();
	if (fDeter != 0.0f)
	{
		const float fInvDeter = 1 / fDeter;
		Matrix3 mat = *this;
		m11 = ((mat.m22 * mat.m33) - (mat.m32 * mat.m23)) * fInvDeter;
		m12 = ((mat.m13 * mat.m32) - (mat.m12 * mat.m33)) * fInvDeter;
		m13 = ((mat.m12 * mat.m23) - (mat.m13 * mat.m22)) * fInvDeter;

		m21 = ((mat.m23 * mat.m31) - (mat.m21 * mat.m33)) * fInvDeter;
		m22 = ((mat.m22 * mat.m33) - (mat.m13 * mat.m31)) * fInvDeter;
		m23 = ((mat.m21 * mat.m13) - (mat.m11 * mat.m23)) * fInvDeter;

		m31 = ((mat.m21 * mat.m32) - (mat.m31 * mat.m22)) * fInvDeter;
		m32 = ((mat.m31 * mat.m12) - (mat.m11 * mat.m32)) * fInvDeter;
		m33 = ((mat.m11 * mat.m22) - (mat.m21 * mat.m12)) * fInvDeter;
		return true;
	}
	else
	{
		return false;
	}
}

void Matrix3::Rotate(const float fAngle)
{
	const float co = cosf(fAngle);
	const float si = sinf(fAngle);
	m11 = co;   m12 = si;  m13 = 0.0f;
	m21 = -si;   m22 = co;   m23 = 0.0f;
	m31 = 0.0f; m32 = 0.0f; m33 = 1.0f;
}

void Matrix3::Scale(const float fXScalar, const float fYScalar)
{
	m11 = m11 * fXScalar; m12 = 0.0f;           m13 = 0.0f;
	m21 = 0.0f;           m22 = m22 * fYScalar; m23 = 0.0f;
	m31 = 0.0f;           m32 = 0.0f;           m33 = 1.0f;
}
