////////////////////////////////////////////////////////////////////
// File: <Vector2.cpp>
// Author: <Alex Kitching>
// Date Created: <09/02/17>
// Brief: <Source file for the Vector2 Class.>
////////////////////////////////////////////////////////////////////

#include "Vector2.h"
#include "Vector3.h"
#include <math.h>
#include <stdlib.h>


const Vector2 Vector2::Up = {0.f, 1.f};
const Vector2 Vector2::Down = {0.f, -1.f};
const Vector2 Vector2::Right = {1.f, 0.f};
const Vector2 Vector2::Left = {-1.f, 0.f};
const Vector2 Vector2::Zero = { 0.f, 0.f };
const Vector2 Vector2::One = { 1.f, 1.f };

// Default Constructor
Vector2::Vector2() :
	fX(0.f),
	fY(0.f)
{
}

// Custom Constructor
Vector2::Vector2(const float a_fX, const float a_fY) :
	fX(a_fX),
	fY(a_fY)
{
}

Vector2::Vector2(const Vector3 a_v3Vec) :
	fX(a_v3Vec.GetX()),
	fY(a_v3Vec.GetY())
{
}

// Copy Constructor
Vector2::Vector2(const Vector2&  a_vec) :
	fX(a_vec.fX),
	fY(a_vec.fY)
{
}

// Destructor
Vector2::~Vector2()
{
}

// Magnitude
float const Vector2::Magnitude()
{
	return sqrtf(fX * fX + fY * fY);
}

// Magnitude Squared
float const Vector2::MagnitudeSquared()
{
	return fX * fX + fY * fY;
}

// Distance
float const Vector2::Distance(const Vector2& a_v2Vec)  const
{
	float fDistX = fX - a_v2Vec.fX;
	float fDistY = fY - a_v2Vec.fY;
	return sqrtf((fDistX * fDistX) + (fDistY * fDistY));
}

// Distance Squared
float const Vector2::DistanceSquared(const Vector2&  a_v2Vec)  const
{
	return sqrtf(Distance(a_v2Vec)) * sqrtf(Distance(a_v2Vec));
}
// Normalise the Vector
void const Vector2::Normalise()
{
	float fMag = Magnitude();
	if (fMag != 0.f)
	{
		fX = fX / fMag;
		fY = fY / fMag;
	}
}
// Normalised Value (Read Only)
Vector2 const Vector2::GetUnitVector()
{
	Vector2 v2Result = *this;
	v2Result.Normalise();
	return v2Result;
}

Vector2 Vector2::Perpendicular()
{
	return Vector2(fY, -fX); // Vector Perpendicular to original
}

float const Vector2::Angle(const Vector2 & a_v2Vec)  const
{
	float fDot = this->DotProduct(a_v2Vec);
	float fDet = fX * a_v2Vec.fY - fY * a_v2Vec.fX;
	float fAngle = atan2f(fDet, fDot);
	return fAngle;
}

// Dot Product
float const Vector2::DotProduct(const Vector2&  a_v2Vec) const
{
	return (fX*a_v2Vec.fX) + (fY*a_v2Vec.fY);
}

// Curve Functions
Vector2 Vector2::Lerp(Vector2 a_v2Vec0, Vector2 a_v2Vec1, float a_fTime)
{
	return a_v2Vec0 * a_v2Vec1 + (1 - a_fTime) * a_v2Vec0;
}

Vector2 Vector2::QuadBezier(Vector2 a_v2Vec0, Vector2 a_v2Vec1, Vector2 a_v2Vec2, float a_fTime)
{
	// Lerp from first point to second
	Vector2 v2MidVec1 = Lerp(a_v2Vec0, a_v2Vec1, a_fTime);
	// Lerp from the second point to the third
	Vector2 v2MidVec2 = Lerp(a_v2Vec1, a_v2Vec2, a_fTime);

	// Return the lerp from two intermediate points
	return Lerp(v2MidVec1, v2MidVec2, a_fTime);
}

Vector2 Vector2::HermiteSpline(Vector2 a_v2Point0, Vector2 a_v2Point1, Vector2 a_v2Tan0, Vector2 a_v2Tan1, float a_fTime)
{
	float fTimeSq = a_fTime * a_fTime;
	float fTimeCub = fTimeSq * a_fTime;

	float fH00 = 2.f * fTimeCub - 3.f * fTimeSq + 1.f;
	float fH01 = -2.f * fTimeCub + 3.f * fTimeSq;
	float fH10 = fTimeCub - 2.f * fTimeSq + a_fTime;
	float fH11 = fTimeCub - fTimeSq;

	Vector2 v2Point = fH00 * a_v2Point0 + fH10 * a_v2Tan0 + fH01 * a_v2Point1 + fH11 * a_v2Tan1;

	return v2Point;
}

Vector2 Vector2::CardinalSpline(Vector2 a_v2Point0, Vector2 a_v2Point1, Vector2 a_v2Point2, float a_fA, float a_fTime)
{
	Vector2 v2Tangent0 = (a_v2Point1 - a_v2Point0) * a_fA;
	Vector2 v2Tangent1 = (a_v2Point2 - a_v2Point1) * a_fA;

	float fTimeSq = a_fTime * a_fTime;
	float fTimeCub = fTimeSq * a_fTime;

	float fH00 = 2 * fTimeCub - 3 * fTimeSq + 1;
	float fH01 = -2 * fTimeCub + 3 * fTimeSq;
	float fH10 = fTimeCub - 2 * fTimeSq + a_fTime;
	float fH11 = fTimeCub - fTimeSq;

	Vector2 v2Point = fH00 * a_v2Point0 + fH10 * v2Tangent0 + fH01 * a_v2Point1 + fH11 * v2Tangent1;
	return v2Point;
}

// Set
void Vector2::Set(float  a_fX, float  a_fY)
{
	fX = a_fX;
	fY = a_fY;
}

void Vector2::SetX(float a_fX)
{
	fX = a_fX;
}

void Vector2::SetY(float a_fY)
{
	fY = a_fY;
}

// Get
Vector2 Vector2::Get() const
{
	return Vector2(fX,fY);
}

void Vector2::Get(float&  a_fX, float&  a_fY)const
{
	a_fX = fX;
	a_fY = fY;
}

float Vector2::GetX() const
{
	return fX;
}

void Vector2::GetX(float & a_fX)const
{
	a_fX = fX;
}

float Vector2::GetY() const
{
	return fY;
}

void Vector2::GetY(float & a_fY)const
{
	a_fY = fY;
}

// Set Random
void Vector2::SetRandom(float const a_fMin, float const a_fMax)
{
	fX = a_fMin + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (a_fMax - a_fMin)));
	fY = a_fMin + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (a_fMax - a_fMin)));
	int iPosNegX = rand() % 2;
	int iPosNegY = rand() % 2;
	if (iPosNegX == 0)
	{
		fX *= -1;
	}
	else if (iPosNegX == 1)
	{
	}
	if (iPosNegY == 0)
	{
		fY *= -1;
	}
	else if (iPosNegY == 1)
	{
	}
}

// Set Random X
void Vector2::SetRandomX(float a_fMin, float a_fMax)
{
	fX = a_fMin + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (a_fMax - a_fMin)));
	int iPosNegX = rand() % 2;
	if (iPosNegX == 0)
	{
		fX *= -1;
	}
	else if (iPosNegX == 1)
	{
	}
}

// Set Random Y
void Vector2::SetRandomY(float a_fMin, float a_fMax)
{
	fY = a_fMin + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (a_fMax - a_fMin)));
	int iPosNegY = rand() % 2;
	if (iPosNegY == 0)
	{
		fY *= -1;
	}
	else if (iPosNegY == 1)
	{
	}
}

// Operator Overloads
Vector2::operator float*()
{
	return static_cast<float*>(&fX);
}

Vector2::operator const float*() const
{
	return static_cast<const float*>(&fX);
}

bool Vector2::operator==(const Vector2&  a_v2Vec)
{
	return fX == a_v2Vec.fX && fY == a_v2Vec.fY;
}

bool Vector2::operator!=(const Vector2&  a_v2Vec)
{
	return fX != a_v2Vec.fX && fY != a_v2Vec.fY;
}

Vector2 Vector2::operator+(const Vector2&  a_v2Vec)
{
	return Vector2(fX + a_v2Vec.fX, fY + a_v2Vec.fY);
}

Vector2 Vector2::operator+(const float&  a_fValue)
{
	return Vector2(fX + a_fValue, fY + a_fValue);
}

Vector2 operator+(const float & a_fValue, const Vector2 & a_v2Vec)
{
	return Vector2(a_v2Vec.fX + a_fValue, a_v2Vec.fY + a_fValue);
}

Vector2 Vector2::operator+=(const Vector2&  a_v2Vec)
{
	fX += a_v2Vec.fX;
	fY += a_v2Vec.fY;
	return *this;
}

Vector2 Vector2::operator+=(const float&  a_fValue)
{
	fX += a_fValue;
	fY += a_fValue;
	return *this;
}

Vector2 Vector2::operator-() const
{
	return Vector2(-fX, -fY);
}

Vector2 Vector2::operator-(const Vector2&  a_v2Vec)
{
	return Vector2(fX - a_v2Vec.fX, fY - a_v2Vec.fY);
}

Vector2 Vector2::operator-(const float&  a_fValue)
{
	return Vector2(fX - a_fValue, fY - a_fValue);
}

Vector2 operator-(const float & a_fValue, const Vector2 & a_v2Vec)
{
	return Vector2(a_v2Vec.fX - a_fValue, a_v2Vec.fY - a_fValue);
}

Vector2 Vector2::operator-=(const Vector2&  a_v2Vec)
{
	fX -= a_v2Vec.fX;
	fY -= a_v2Vec.fY;
	return *this;
}

Vector2 Vector2::operator-=(const float&  a_fValue)
{
	fX -= a_fValue;
	fY -= a_fValue;
	return *this;
}

Vector2 Vector2::operator*(const Vector2&  a_v2Vec)
{
	return Vector2(fX * a_v2Vec.fX, fY * a_v2Vec.fY);
}

Vector2 Vector2::operator*(const float&  a_fValue)
{
	return Vector2(fX * a_fValue, fY * a_fValue);
}

Vector2 operator*(const float & a_fValue, const Vector2 & a_v2Vec)
{
	return Vector2(a_v2Vec.fX * a_fValue, a_v2Vec.fY * a_fValue);
}

Vector2 Vector2::operator*=(const Vector2&  a_v2Vec)
{
	fX *= a_v2Vec.fX;
	fY *= a_v2Vec.fY;
	return *this;
}

Vector2 Vector2::operator*=(const float&  a_fValue)
{
	fX *= a_fValue;
	fY *= a_fValue;
	return *this;
}

Vector2 Vector2::operator/(const Vector2 & a_v2Vec)
{
	return Vector2(fX / a_v2Vec.fX, fY / a_v2Vec.fY);
}

Vector2 Vector2::operator/(const float & a_fValue)
{
	return Vector2(fX / a_fValue, fY / a_fValue);
}

Vector2 operator/(const float & a_fValue, const Vector2 & a_v2Vec)
{
	return Vector2(a_v2Vec.fX / a_fValue, a_v2Vec.fY / a_fValue);
}

Vector2 Vector2::operator/=(const Vector2 & a_v2Vec)
{
	fX /= a_v2Vec.fX;
	fY /= a_v2Vec.fY;
	return *this;
}

Vector2 Vector2::operator/=(const float & a_fValue)
{
	fX /= a_fValue;
	fY /= a_fValue;
	return *this;
}
