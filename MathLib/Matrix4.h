////////////////////////////////////////////////////////////////////
// File: <Matrix4.h>
// Author: <Alex Kitching>
// Date Created: <24/02/17>
// Brief: <Header file for the Matrix 4x4 Class.>
////////////////////////////////////////////////////////////////////

#ifndef _MATRIX4_H_
#define _MATRIX4_H_
#include "Vector4.h"

class Matrix4
{
public:
	//Default Constructor
	Matrix4();
	//Custom Constructors
	Matrix4(const float a_fM11, const float a_fM12, const float a_m13, const float a_m14, const float a_m21, const float a_m22, const float a_m23, const float a_m24, const float a_m31, const float a_m32,
		const float a_m33, const float a_m34, const float a_m41, const float a_m42, const float a_m43, const float a_m44);
	Matrix4(const Vector4 x, const Vector4 y, const Vector4 z, const Vector4 w);
	//Copy Constructor 
	Matrix4(const Matrix4& a_mat);
	//Destructor
	~Matrix4();

	//Identity Matrix
	static const Matrix4 Identity;

	//Get Value
	float GetValue(const unsigned int row, const unsigned int col) const;
	//Get Row Vector
	Vector4 GetRow(const unsigned int row) const;
	void GetRow(const unsigned int row, Vector4 a_vector)const;
	//Get Column Vector
	Vector4 GetCol(const unsigned int col) const;
	void GetCol(const unsigned int col, Vector4 a_vector)const;

	//Set Value
	void SetValue(const unsigned int row, const unsigned int col, const float a_value);
	//Set Row Vector
	void SetRow(const unsigned int row, const float a_value);
	void SetRow(const unsigned int row, const Vector4 a_vector);
	//Set Column Vector
	void SetCol(const unsigned int col, const float a_value);
	void SetCol(const unsigned int col, const Vector4 a_vector);

	//Operator Overloads
	//Access
	operator float*();
	operator const float*() const;
	float operator[](const unsigned int index) const;
	//Comparison
	bool Matrix4::operator==(const Matrix4& a_mat) const;
	bool Matrix4::operator!=(const Matrix4& a_mat) const;
	//Addition
	Matrix4 Matrix4::operator+(const Matrix4& a_mat)  const;
	Matrix4 Matrix4::operator+(const float& a_fValue)  const;
	//Subtraction
	Matrix4 Matrix4::operator-(const Matrix4& a_mat)  const;
	Matrix4 Matrix4::operator-(const float& a_fValue)  const;
	//Multiplication
	Matrix4 Matrix4::operator*(const Matrix4& a_mat)  const;
	Matrix4 Matrix4::operator*(const float& a_fValue)  const;
	Vector4 Matrix4::operator*(const Vector4& a_vec)  const;

	//Transpose
	void Transpose();
	//Determinant
	float Determinant3() const;
	//Inverse
	bool Inverse();
	//Rotate
	void RotateX(const float fAngle);
	void RotateY(const float fAngle);
	void RotateZ(const float fAngle);
	//Scale
	void Scale(const float fXScalar, const float fYScalar, const float fZScalar);

private:
	union
	{
		float m[4][4];
		struct
		{
			float m11, m12, m13, m14;
			float m21, m22, m23, m24;
			float m31, m32, m33, m34;
			float m41, m42, m43, m44;
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
			Vector4 Translation;
		};
	};
};

#endif //!_MATRIX4_H_