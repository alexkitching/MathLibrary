////////////////////////////////////////////////////////////////////
// File: <Vector4.h>
// Author: <Alex Kitching>
// Date Created: <23/02/17>
// Brief: <Header file for the Vector4 Class.>
////////////////////////////////////////////////////////////////////

#ifndef _VECTOR4_H_
#define _VECTOR4_H_

class Vector3;
class Vector4
{
public:
	//Default Constructor
	Vector4();
	//Custom Constructor
	Vector4(float a_fX, float a_fY, float a_fZ, float a_fW);
	Vector4(Vector3 a_vec, float a_fW);
	Vector4(Vector3 a_vec);
	//Copy Constructor
	Vector4(const Vector4& a_vec);
	//Destructor
	~Vector4();

	//Static Variables
	static const Vector4 Zero;
	static const Vector4 One;

	//Magnitude
	float const Magnitude();
	//Magnitude Squared
	float const MagnitudeSquared();

	//Distance
	float const Distance(Vector4& a_vec);
	//Distance Squared
	float const DistanceSquared(Vector4& a_vec);

	//Normalise
	void const Normalise();
	// Return Normalise (ReadOnly)
	Vector4 const GetUnitVector();

	//Dot Product
	float const DotProduct(const Vector4& a_vec) const;
	//Cross Product
	Vector4 const CrossProduct(const Vector4 & a_vec) const;

	//Set Values
	void Set(float a_fX, float a_fY, float  a_fZ, float a_fW);
	void SetX(float a_fX);
	void SetY(float a_fY);
	void SetZ(float a_fZ);
	void SetW(float a_fW);

	//Get Values
	Vector4 Get()const;
	void Get(float& a_fX, float& a_fY, float&  a_fZ, float& a_fW)const;
	float GetX()const;
	void GetX(float& a_fX)const;
	float GetY()const;
	void GetY(float& a_fY)const;
	float GetZ()const;
	void GetZ(float& a_fZ)const;
	float GetW()const;
	void GetW(float& a_fW)const;

	//Set Random
	void SetRandom(float a_fMin, float a_fMax);
	//Set RandomX
	void SetRandomX(float a_fMin, float a_fMax);
	//Set RandomY
	void SetRandomY(float a_fMin, float a_fMax);
	//Set RandomZ
	void SetRandomZ(float a_fMin, float a_fMax);

	

	//Operator Overloads
	operator float* ();
	operator const float*() const;
	//Comparison
	bool Vector4::operator==(const Vector4& a_vec);
	bool Vector4::operator!=(const Vector4& a_vec);
	//Addition
	Vector4 Vector4::operator+(const Vector4& a_vec);
	Vector4 Vector4::operator+(const float& a_fValue);
	friend Vector4 operator+(const float& a_fValue, const Vector4& a_vec);
	Vector4 Vector4::operator+=(const Vector4& a_vec);
	Vector4 Vector4::operator+=(const float& a_fValue);
	//Subtraction
	Vector4 Vector4::operator-() const;
	Vector4 Vector4::operator-(const Vector4& a_vec);
	Vector4 Vector4::operator-(const float& a_fValue);
	friend Vector4 operator-(const float& a_fValue, const Vector4& a_vec);
	Vector4 Vector4::operator-=(const Vector4& a_vec);
	Vector4 Vector4::operator-=(const float& a_fValue);
	//Multiplication
	Vector4 Vector4::operator*(const Vector4& a_vec);
	Vector4 Vector4::operator*(const float& a_fValue);
	friend Vector4 operator*(const float& a_fValue, const Vector4& a_vec);
	Vector4 Vector4::operator*=(const Vector4& a_vec);
	Vector4 Vector4::operator*=(const float& a_fValue);
	//Division
	Vector4 Vector4::operator/(const Vector4& a_vec);
	Vector4 Vector4::operator/(const float& a_fValue);
	friend Vector4 operator/(const float& a_fValue, const Vector4& a_vec);
	Vector4 Vector4::operator/=(const Vector4& a_vec);
	Vector4 Vector4::operator/=(const float& a_fValue);

private:
	//Vector Components
	float fX;
	float fY;
	float fZ;
	float fW;
};

#endif //!_VECTOR4_H_