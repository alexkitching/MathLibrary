////////////////////////////////////////////////////////////////////
// File: <Vector4.cpp>
// Author: <Alex Kitching>
// Date Created: <23/02/17>
// Brief: <Source file for the Vector4 Class.>
////////////////////////////////////////////////////////////////////

#include "Vector4.h"
#include "Vector3.h"
#include <math.h>
#include <stdlib.h>

//Static Variable Definition
const Vector4 Vector4::Zero = { 0.f, 0.f, 0.f, 0.f };
const Vector4 Vector4::One = { 1.f, 1.f , 1.f, 1.f };

//Default Constructor
Vector4::Vector4()
{
	fX = 0.f;
	fY = 0.f;
	fZ = 0.f;
	fW = 0.f;
}

//Custom Constructor
Vector4::Vector4(float a_fX, float a_fY, float a_fZ, float a_fW) : fX(a_fX), fY(a_fY), fZ(a_fZ), fW(a_fW)
{
}

Vector4::Vector4(Vector3 a_vec, float a_fW)
{
	float x = 0.f, y = 0.f, z = 0.f;
	a_vec.GetX(x);
	a_vec.GetY(y);
	a_vec.GetZ(z);
	fX = x;
	fY = y;
	fZ = z;
	fW = a_fW;
}

Vector4::Vector4(Vector3 a_vec)
{
	float x = 0.f, y = 0.f, z = 0.f;
	a_vec.GetX(x);
	a_vec.GetY(y);
	a_vec.GetZ(z);
	fX = x;
	fY = y;
	fZ = z;
	fW = 0.f;
}

//Copy Constructor
Vector4::Vector4(const Vector4 & a_vec) : fX(a_vec.fX), fY(a_vec.fY), fZ(a_vec.fZ), fW(a_vec.fW)
{
}

//Destructor
Vector4::~Vector4()
{
}

//Magnitude
float const Vector4::Magnitude()
{
	return sqrtf(fX * fX + fY * fY + fZ * fZ);
}

//Magnitude Squared
float const Vector4::MagnitudeSquared()
{
	return fX * fX + fY * fY + fZ * fZ;
}

//Distance
float const Vector4::Distance(Vector4& a_vec)
{
	float DistX = fX - a_vec.fX;
	float DistY = fX - a_vec.fY;
	float DistZ = fZ - a_vec.fZ;
	return sqrtf((DistX * DistX) + (DistY * DistY) + (DistZ * DistZ));
}

//Distance Squared
float const Vector4::DistanceSquared(Vector4& a_vec)
{
	return sqrtf(Distance(a_vec)) * sqrtf(Distance(a_vec));
}

//Normalise the Vector
void const Vector4::Normalise()
{
	float fMag = Magnitude();
	if (fMag != 0.f)
	{
		fX = fX / fMag;
		fY = fY / fMag;
		fZ = fZ / fMag;
	}
}
//Normalised Value (Read Only)
Vector4 const Vector4::GetUnitVector()
{
	Vector4 v4Result = *this;
	v4Result.Normalise();
	return v4Result;
}

//Dot Product
float const Vector4::DotProduct(const Vector4& a_vec) const
{
	return (fX*a_vec.fX) + (fY*a_vec.fY) + (fZ*a_vec.fZ);
}

//Cross Product
Vector4 const Vector4::CrossProduct(const Vector4 & a_vec) const
{
	float fCrossX = (fY * a_vec.fZ) - (fZ * a_vec.fY);
	float fCrossY = (fZ * a_vec.fX) - (fX * a_vec.fZ);
	float fCrossZ = (fX * a_vec.fY) - (fY * a_vec.fX);
	return Vector4(fCrossX, fCrossY, fCrossZ, fW);
}

//Set
void Vector4::Set(float a_fX, float a_fY, float a_fZ, float a_fW)
{
	fX = a_fX;
	fY = a_fY;
	fZ = a_fZ;
	fW = a_fW;
}

void Vector4::SetX(float a_fX)
{
	fX = a_fX;
}

void Vector4::SetY(float a_fY)
{
	fY = a_fY;
}

void Vector4::SetZ(float a_fZ)
{
	fZ = a_fZ;
}

void Vector4::SetW(float a_fW)
{
	fW = a_fW;
}

//Get
Vector4 Vector4::Get() const
{
	return Vector4(fX, fY, fZ, fW);
}

void Vector4::Get(float& a_fX, float& a_fY, float& a_fZ, float& a_fW)const
{
	a_fX = fX;
	a_fY = fY;
	a_fZ = fZ;
	a_fW = fW;
}

float Vector4::GetX() const
{
	return fX;
}

void Vector4::GetX(float & a_fX)const
{
	a_fX = fX;
}

float Vector4::GetY() const
{
	return fY;
}

void Vector4::GetY(float & a_fY)const
{
	a_fY = fY;
}

float Vector4::GetZ() const
{
	return fZ;
}

void Vector4::GetZ(float & a_fZ)const
{
	a_fZ = fZ;
}

float Vector4::GetW() const
{
	return fW;
}

void Vector4::GetW(float & a_fW)const
{
	a_fW = fW;
}

//Set Random
void Vector4::SetRandom(float const a_fMin, float const a_fMax)
{
	fX = a_fMin + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (a_fMax - a_fMin)));
	fY = a_fMin + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (a_fMax - a_fMin)));
	fZ = a_fMin + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (a_fMax - a_fMin)));
	int iPosNegX = rand() % 2;
	int iPosNegY = rand() % 2;
	int iPosNegZ = rand() % 2;
	if (iPosNegX == 0)
	{
		fX *= -1;
	}
	else if (iPosNegX == 1)
	{
		return;
	}
	if (iPosNegY == 0)
	{
		fY *= -1;
	}
	else if (iPosNegY == 1)
	{
		return;
	}
	if (iPosNegZ == 0)
	{
		fZ *= -1;
	}
	else if (iPosNegZ == 1)
	{
		return;
	}
}

//Set Random X
void Vector4::SetRandomX(float a_fMin, float a_fMax)
{
	fX = a_fMin + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (a_fMax - a_fMin)));
	int iPosNegX = rand() % 2;
	if (iPosNegX == 0)
	{
		fX *= -1;
	}
	else if (iPosNegX == 1)
	{
		return;
	}
}

//Set Random Y
void Vector4::SetRandomY(float a_fMin, float a_fMax)
{
	fY = a_fMin + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (a_fMax - a_fMin)));
	int iPosNegY = rand() % 2;
	if (iPosNegY == 0)
	{
		fY *= -1;
	}
	else if (iPosNegY == 1)
	{
		return;
	}
}

//Set Random Z
void Vector4::SetRandomZ(float a_fMin, float a_fMax)
{
	fZ = a_fMin + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (a_fMax - a_fMin)));
	int iPosNegZ = rand() % 2;
	if (iPosNegZ == 0)
	{
		fZ *= -1;
	}
	else if (iPosNegZ == 1)
	{
		return;
	}
}

Vector4::operator float*()
{
	return static_cast<float*>(&fX);
}

Vector4::operator const float*() const
{
	return static_cast<const float*>(&fX);
}

//Operator Overloads
bool Vector4::operator==(const Vector4& a_vec)
{
	return fX == a_vec.fX && fY == a_vec.fY && fZ == a_vec.fZ;
}

bool Vector4::operator!=(const Vector4& a_vec)
{
	return fX != a_vec.fX && fY != a_vec.fY && fZ != a_vec.fZ;
}

Vector4 Vector4::operator+(const Vector4& a_vec)
{
	return Vector4(fX + a_vec.fX, fY + a_vec.fY, fZ + a_vec.fZ, fW);
}

Vector4 Vector4::operator+(const float& a_fValue)
{
	return Vector4(fX + a_fValue, fY + a_fValue, fZ + a_fValue, fW);
}

Vector4 operator+(const float & a_fValue, const Vector4 & a_vec)
{
	return Vector4(a_vec.fX + a_fValue, a_vec.fY + a_fValue, a_vec.fZ + a_fValue, a_vec.fW);
}

Vector4 Vector4::operator+=(const Vector4& a_vec)
{
	fX += a_vec.fX;
	fY += a_vec.fY;
	fZ += a_vec.fZ;
	return *this;
}

Vector4 Vector4::operator+=(const float& a_fValue)
{
	fX += a_fValue;
	fY += a_fValue;
	fZ += a_fValue;
	return *this;
}

Vector4 Vector4::operator-() const
{
	Vector4 newVec;
	newVec.fX = -fX;
	newVec.fY = -fY;
	newVec.fZ = -fZ;
	newVec.fW = -fW;
	return newVec;
}

Vector4 Vector4::operator-(const Vector4& a_vec)
{
	return Vector4(fX - a_vec.fX, fY - a_vec.fY, fZ - a_vec.fZ, fW);
}

Vector4 Vector4::operator-(const float& a_fValue)
{
	return Vector4(fX - a_fValue, fY - a_fValue, fZ - a_fValue, fW);
}

Vector4 operator-(const float & a_fValue, const Vector4 & a_vec)
{
	return Vector4(a_vec.fX - a_fValue, a_vec.fY - a_fValue, a_vec.fZ - a_fValue, a_vec.fW);
}

Vector4 Vector4::operator-=(const Vector4& a_vec)
{
	fX -= a_vec.fX;
	fY -= a_vec.fY;
	fZ -= a_vec.fZ;
	return *this;
}

Vector4 Vector4::operator-=(const float& a_fValue)
{
	fX -= a_fValue;
	fY -= a_fValue;
	fZ -= a_fValue;
	return *this;
}

Vector4 Vector4::operator*(const Vector4& a_vec)
{
	return Vector4(fX * a_vec.fX, fY * a_vec.fY, fZ * a_vec.fZ, fW);
}

Vector4 Vector4::operator*(const float& a_fValue)
{
	return Vector4(fX * a_fValue, fY * a_fValue, fZ * a_fValue, fW);
}

Vector4 operator*(const float & a_fValue, const Vector4 & a_vec)
{
	return Vector4(a_vec.fX * a_fValue, a_vec.fY * a_fValue, a_vec.fZ * a_fValue, a_vec.fW);
}

Vector4 Vector4::operator*=(const Vector4& a_vec)
{
	fX *= a_vec.fX;
	fY *= a_vec.fY;
	fZ *= a_vec.fZ;
	return *this;
}

Vector4 Vector4::operator*=(const float& a_fValue)
{
	fX *= a_fValue;
	fY *= a_fValue;
	fZ *= a_fValue;
	return *this;
}

Vector4 Vector4::operator/(const Vector4 & a_vec)
{
	return Vector4(fX / a_vec.fX, fY / a_vec.fY, fZ / a_vec.fZ, fW);
}

Vector4 Vector4::operator/(const float & a_fValue)
{
	return Vector4(fX / a_fValue, fY / a_fValue, fZ / a_fValue, fW);
}

Vector4 operator/(const float & a_fValue, const Vector4 & a_vec)
{
	return Vector4(a_vec.fX / a_fValue, a_vec.fY / a_fValue, a_vec.fZ / a_fValue, a_vec.fW);
}

Vector4 Vector4::operator/=(const Vector4 & a_vec)
{
	fX /= a_vec.fX;
	fY /= a_vec.fY;
	fZ /= a_vec.fZ;
	return *this;
}

Vector4 Vector4::operator/=(const float & a_fValue)
{
	fX /= a_fValue;
	fY /= a_fValue;
	fZ /= a_fValue;
	return *this;
}
