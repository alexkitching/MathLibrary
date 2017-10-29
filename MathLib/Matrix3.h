////////////////////////////////////////////////////////////////////
// File: <Matrix3.h>
// Author: <Alex Kitching>
// Date Created: <16/02/17>
// Brief: <Header file for the Matrix 3x3 Class.>
////////////////////////////////////////////////////////////////////

#ifndef _MATRIX3_H_
#define _MATRIX3_H_

#include "Vector3.h"

class Vector2;
class Matrix3
{
public:
	//Default Constructor
	Matrix3();
	//Custom Constructors
	Matrix3(const float a_m11, const float a_m12, const float a_m13, const float a_m21, const float a_m22, const float a_m23, const float a_m31, const float a_m32, const float a_m33);
	Matrix3(const Vector3 x, const Vector3 y, const Vector3 z);
	//Copy Constructor 
	Matrix3(const Matrix3& a_mat);
	//Destructor
	~Matrix3();

	//Identity Matrix
	static const Matrix3 Identity;

	//Get Value
	float GetValue(const unsigned int row, const unsigned int col) const;
	//Get Row Vector
	Vector3 GetRow(const unsigned int row) const;
	void GetRow(const unsigned int row, Vector3 a_vector) const;
	//Get Column Vector
	Vector3 GetCol(const unsigned int col) const;
	void GetCol(const unsigned int col, Vector3 a_vector)const;

	//Set Value
	void SetValue(const unsigned int row, const unsigned int col, const float a_value);
	//Set Row Vector
	void SetRow(const unsigned int row, const float a_value);
	void SetRow(const unsigned int row, const Vector3 a_vector);
	//Set Column Vector
	void SetCol(const unsigned int col, const float a_value);
	void SetCol(const unsigned int col, const Vector3 a_vector);

	//Operator Overloads
	//Access
	operator float*();
	operator const float*() const;
	float operator[](const unsigned int index) const;
	//Comparison
	bool Matrix3::operator==(const Matrix3& a_mat) const;
	bool Matrix3::operator!=(const Matrix3& a_mat) const;
	//Addition
	Matrix3 Matrix3::operator+(const Matrix3& a_mat);
	Matrix3 Matrix3::operator+(const float& a_value);
	//Subtraction
	Matrix3 Matrix3::operator-(const Matrix3& a_mat);
	Matrix3 Matrix3::operator-(const float& a_value);
	//Multiplication
	Matrix3 Matrix3::operator*(const Matrix3& a_mat);
	Matrix3 Matrix3::operator*(const float& a_value);
	Vector3 Matrix3::operator*(const Vector3& a_vec);
	Vector3 Matrix3::operator*(const Vector3* a_vec);

	//Transpose
	void Transpose();
	//Determinant
	float Determinant() const;
	//Inverse
	bool Inverse();
	//Rotate
	void Rotate(const float fAngle);
	//Scale
	void Scale(const float fXScalar, const float fYScalar);


private:
	union 
	{
		float m[3][3];
		struct
		{
			float m11, m12, m13;
			float m21, m22, m23;
			float m31, m32, m33;
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
	};
};

#endif //!_MATRIX3_H_