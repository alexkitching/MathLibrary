////////////////////////////////////////////////////////////////////
// File: <Vector3.cpp>
// Author: <Alex Kitching>
// Date Created: <09/02/17>
// Brief: <Source file for the Vector3 Class.>
////////////////////////////////////////////////////////////////////

#include "Vector3.h"
#include "Vector2.h"
#include "Vector4.h"
#include "Matrix3.h"
#include <math.h>
#include <stdlib.h>

// Static Variable Definition
const Vector3 Vector3::Up = { 0.f, 1.f, 0.f};
const Vector3 Vector3::Down = { 0.f, -1.f, 0.f};
const Vector3 Vector3::Right = { 1.f, 0.f, 0.f};
const Vector3 Vector3::Left = { -1.f, 0.f, 0.f};
const Vector3 Vector3::Forward = { 0.f, 0.f, 1.f };
const Vector3 Vector3::Back = { 0.f, 0.f, -1.f };
const Vector3 Vector3::Zero = { 0.f, 0.f, 0.f};
const Vector3 Vector3::One = { 1.f, 1.f , 1.f};

// Default Constructor
Vector3::Vector3() :
	fX(0.f),
	fY(0.f),
	fZ(0.f)
{
}

// Custom Constructor
Vector3::Vector3(float a_fX, float a_fY, float a_fZ) :
	fX(a_fX),
	fY(a_fY),
	fZ(a_fZ)
{
}

Vector3::Vector3(Vector4 a_v4Vec) :
	fX(a_v4Vec.GetX()),
	fY(a_v4Vec.GetY()),
	fZ(a_v4Vec.GetZ())
{
}

Vector3::Vector3(Vector2 a_v2Vec, float a_fZ) :
	fX(a_v2Vec.GetX()),
	fY(a_v2Vec.GetY()),
	fZ(a_fZ)
{
}

Vector3::Vector3(Vector2 a_v2Vec) :
	fX(a_v2Vec.GetX()),
	fY(a_v2Vec.GetY()),
	fZ(0.f)
{
}

// Copy Constructor
Vector3::Vector3(const Vector3 & a_v3Vec) :
	fX(a_v3Vec.fX),
	fY(a_v3Vec.fY),
	fZ(a_v3Vec.fZ)
{
}

// Magnitude
float const Vector3::Magnitude()
{
	return sqrtf(fX * fX + fY * fY + fZ * fZ);
}

// Magnitude Squared
float const Vector3::MagnitudeSquared()
{
	return fX * fX + fY * fY + fZ * fZ;
}

// Distance
float const Vector3::Distance(Vector3& a_v3Vec)
{
	float fDistX = fX - a_v3Vec.fX;
	float fDistY = fX - a_v3Vec.fY;
	float fDistZ = fZ - a_v3Vec.fZ;
	return sqrtf((fDistX * fDistX) + (fDistY * fDistY) + (fDistZ * fDistZ));
}

// Distance Squared
float const Vector3::DistanceSquared(Vector3& a_v3Vec)
{
	return sqrtf(Distance(a_v3Vec)) * sqrtf(Distance(a_v3Vec));
}

// Normalise the Vector
void const Vector3::Normalise()
{
	float fMag = Magnitude();
	if (fMag != 0.f)
	{
		fX = fX / fMag;
		fY = fY / fMag;
		fZ = fZ / fMag;
	}
}
// Normalised Value (Read Only)
Vector3 const Vector3::GetUnitVector()
{
	Vector3 v3Result = *this;
	v3Result.Normalise();
	return v3Result;
}

// Return Perpendicular Vector
Vector3 Vector3::Perpendicular()
{
	return Vector3(fY, -fX, fZ); // Vector Perpendicular to original
}

Vector3 Vector3::Reflect(Vector3 a_v3Velocity, Vector3 a_v3Normal)
{
	return 2 * a_v3Velocity.DotProduct(a_v3Normal) * a_v3Normal - a_v3Velocity;
}

// Find Angle Between Another Vector
float const Vector3::Angle2D(Vector3 & a_v3Vec)
{
	float fDot = this->DotProduct(a_v3Vec);
	float fDet = fX * a_v3Vec.fY - fY * a_v3Vec.fX;
	float fAngle = atan2f(fDet, fDot);
	return fAngle;
}

// Dot Product
float const Vector3::DotProduct(const Vector3& a_v3Vec) const
{
	return (fX*a_v3Vec.fX) + (fY*a_v3Vec.fY);
}

Vector3 const Vector3::CrossProduct(Vector3 & a_v3Vec) const
{
	float fCrossX = (fY * a_v3Vec.fZ) - (fZ * a_v3Vec.fY);
	float fCrossY = (fZ * a_v3Vec.fX) - (fX * a_v3Vec.fZ);
	float fCrossZ = (fX * a_v3Vec.fY) - (fY * a_v3Vec.fX);
	return Vector3(fCrossX, fCrossY, fCrossZ);
}

// Curve Functions
Vector3 Vector3::Lerp(Vector3 a_v3Vec0, Vector3 a_v3Vec1, float a_fTime)
{
	return a_v3Vec0 + a_fTime*(a_v3Vec1 - a_v3Vec0);
}

Vector3 Vector3::QuadBezier(Vector3 a_v3Vec0, Vector3 a_v3Vec1, Vector3 a_v3Vec2, float a_fTime)
{
	// Lerp from first point to second
	Vector3 v3MidVec1 = Lerp(a_v3Vec0, a_v3Vec1, a_fTime);
	// Lerp from the second point to the third
	Vector3 v3MidVec2 = Lerp(a_v3Vec1, a_v3Vec2, a_fTime);

	// Return the lerp from two intermediate points
	return Lerp(v3MidVec1, v3MidVec2, a_fTime);
}

Vector3 Vector3::HermiteSpline(Vector3 a_v3Point0, Vector3 a_v3Point1, Vector3 a_v3Tan0, Vector3 a_v3Tan1, float a_fTime)
{
	float fTimeSq = a_fTime * a_fTime;
	float fTimeCub = fTimeSq * a_fTime;

	float fH00 = 2 * fTimeCub - 3 * fTimeSq + 1;
	float fH01 = -2 * fTimeCub + 3 * fTimeSq;
	float fH10 = fTimeCub - 2 * fTimeSq + a_fTime;
	float fH11 = fTimeCub - fTimeSq;

	Vector3 v3Point = fH00 * a_v3Point0 + fH10 * a_v3Tan0 + fH01 * a_v3Point1 + fH11 * a_v3Tan1;

	return v3Point;
}

Vector3 Vector3::CardinalSpline(Vector3 a_v3Point0, Vector3 a_v3Point1, Vector3 a_v3Point2, float a_fA, float a_fTime)
{
	Vector3 v3Tangent0 = (a_v3Point1 - a_v3Point0) * a_fA;
	Vector3 v3Tangent1 = (a_v3Point2 - a_v3Point1) * a_fA;

	float fTimeSq = a_fTime * a_fTime;
	float fTimeCub = fTimeSq * a_fTime;

	float fH00 = 2.f * fTimeCub - 3.f * fTimeSq + 1.f;
	float fH01 = -2.f * fTimeCub + 3.f * fTimeSq;
	float fH10 = fTimeCub - 2.f * fTimeSq + a_fTime;
	float fH11 = fTimeCub - fTimeSq;

	Vector3 v3Point = fH00 *a_v3Point0 + fH10 * v3Tangent0 + fH01 * a_v3Point1 + fH11 * v3Tangent1;
	return v3Point;
}

// Set
void Vector3::Set(float a_fX, float a_fY, float a_fZ)
{
	fX = a_fX;
	fY = a_fY;
	fZ = a_fZ;
}

void Vector3::SetX(float a_fX)
{
	fX = a_fX;
}

void Vector3::SetY(float a_fY)
{
	fY = a_fY;
}

void Vector3::SetZ(float a_fZ)
{
	fZ = a_fZ;
}

// Get
Vector3 Vector3::Get() const
{
	return Vector3(fX,fY,fZ);
}

void Vector3::Get(float& a_fX, float& a_fY, float& a_fZ)const
{
	a_fX = fX;
	a_fY = fY;
	a_fZ = fZ;
}

float Vector3::GetX() const
{
	return fX;
}

void Vector3::GetX(float & a_fX)const
{
	a_fX = fX;
}

float Vector3::GetY() const
{
	return fY;
}

void Vector3::GetY(float & a_fY)const
{
	a_fY = fY;
}

float Vector3::GetZ() const
{
	return fZ;
}

void Vector3::GetZ(float & a_fZ)const
{
	a_fZ = fZ;
}

// Set Random
void Vector3::SetRandom(float const a_fMin, float const a_fMax)
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
}

// Set Random X
void Vector3::SetRandomX(float a_fMin, float a_fMax)
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

// Set Random Y
void Vector3::SetRandomY(float a_fMin, float a_fMax)
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

// Set Random Z
void Vector3::SetRandomZ(float a_fMin, float a_fMax)
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

Vector3::operator float*()
{
	return static_cast<float*>(&fX);
}

Vector3::operator const float*() const
{
	return static_cast<const float*>(&fX);
}

// Destructor
Vector3::~Vector3()
{
}

// Operator Overloads
bool Vector3::operator==(const Vector3& a_v3Vec)
{
	return 	fX == a_v3Vec.fX && fY == a_v3Vec.fY;
}

bool Vector3::operator!=(const Vector3& a_v3Vec)
{
	return fX != a_v3Vec.fX && fY != a_v3Vec.fY;
}

Vector3 Vector3::operator+(const Vector3& a_v3Vec)
{
	return Vector3(fX + a_v3Vec.fX, fY + a_v3Vec.fY, fZ);
}

Vector3 Vector3::operator+(const float& a_fValue)
{
	return Vector3(fX + a_fValue, fY + a_fValue, fZ);
}

Vector3 operator+(const float & a_fValue, const Vector3 & a_v3Vec)
{
	return Vector3(a_v3Vec.fX + a_fValue, a_v3Vec.fY + a_fValue, a_v3Vec.fZ);
}

Vector3 Vector3::operator+=(const Vector3& a_v3Vec)
{
	fX += a_v3Vec.fX;
	fY += a_v3Vec.fY;
	return *this;
}

Vector3 Vector3::operator+=(const float& a_fValue)
{
	fX += a_fValue;
	fY += a_fValue;
	return *this;
}

Vector3 Vector3::operator-() const
{
	return Vector3(-fX, -fY, -fZ);
}

Vector3 Vector3::operator-(const Vector3& a_v3Vec)
{
	return Vector3(fX - a_v3Vec.fX, fY - a_v3Vec.fY, fZ);
}

Vector3 Vector3::operator-(const float& a_fValue)
{
	return Vector3(fX - a_fValue, fY - a_fValue, fZ);
}

Vector3 operator-(const float & a_fValue, const Vector3 & a_v3Vec)
{
	return Vector3(a_v3Vec.fX - a_fValue, a_v3Vec.fY - a_fValue, a_v3Vec.fZ);
}

Vector3 Vector3::operator-=(const Vector3& a_v3Vec)
{
	fX -= a_v3Vec.fX;
	fY -= a_v3Vec.fY;
	return *this;
}

Vector3 Vector3::operator-=(const float& a_fValue)
{
	fX -= a_fValue;
	fY -= a_fValue;
	return *this;
}

Vector3 Vector3::operator*(const Vector3& a_v3Vec)
{
	return Vector3(fX * a_v3Vec.fX, fY * a_v3Vec.fY, fZ);
}

Vector3 Vector3::operator*(const float& a_fValue)
{
	return Vector3(fX * a_fValue, fY * a_fValue, fZ);
}

Vector3 operator*(const float & a_fValue, const Vector3 & a_v3Vec)
{
	return Vector3(a_v3Vec.fX * a_fValue, a_v3Vec.fY * a_fValue, a_v3Vec.fZ);
}

Vector3 Vector3::operator*(const Matrix3 & a_m3Mat)
{
	Vector3 v3ColX, v3RowY, v3RowZ;
	v3ColX = a_m3Mat.GetCol(0);
	v3RowY = a_m3Mat.GetCol(1);
	v3RowZ = a_m3Mat.GetCol(2);

	Vector3 v3NewVec((v3ColX.GetX() * fX) + (v3ColX.GetY() * fY) + (v3ColX.GetZ() * fZ),
					 (v3RowY.GetX() * fX) + (v3RowY.GetY() * fY) + (v3RowZ.GetZ() * fZ),
					 (v3RowZ.GetX() * fX) + (v3RowZ.GetY() * fY) + (v3RowZ.GetZ() * fZ));
	return v3NewVec;
}

Vector3 Vector3::operator*=(const Vector3& a_v3Vec)
{
	fX *= a_v3Vec.fX;
	fY *= a_v3Vec.fY;
	return *this;
}

Vector3 Vector3::operator*=(const float& a_fValue)
{
	fX *= a_fValue;
	fY *= a_fValue;
	return *this;
}

Vector3 Vector3::operator*=(const Matrix3 & a_m3Mat)
{
	Vector3 v3ColX, v3RowY, v3RowZ;
	v3ColX = a_m3Mat.GetCol(0);
	v3RowY = a_m3Mat.GetCol(1);
	v3RowZ = a_m3Mat.GetCol(2);

	fX = (v3ColX.GetX() * fX) + (v3ColX.GetY() * fY) + (v3ColX.GetZ() * fZ),
	fY = (v3RowY.GetX() * fX) + (v3RowY.GetY() * fY) + (v3RowZ.GetZ() * fZ),
	fZ = (v3RowZ.GetX() * fX) + (v3RowZ.GetY() * fY) + (v3RowZ.GetZ() * fZ);
	return *this;

}

Vector3 Vector3::operator/(const Vector3 & a_v3Vec)
{
	return Vector3(fX / a_v3Vec.fX, fY / a_v3Vec.fY, fZ);
}

Vector3 Vector3::operator/(const float & a_fValue)
{
	return Vector3(fX / a_fValue, fY / a_fValue, fZ);
}

Vector3 operator/(const float & a_fValue, const Vector3 & a_v3Vec)
{
	return Vector3(a_v3Vec.fX / a_fValue, a_v3Vec.fY / a_fValue, a_v3Vec.fZ);
}

Vector3 Vector3::operator/=(const Vector3 & a_v3Vec)
{
	fX /= a_v3Vec.fX;
	fY /= a_v3Vec.fY;
	return *this;
}

Vector3 Vector3::operator/=(const float & a_fValue)
{
	fX /= a_fValue;
	fY /= a_fValue;
	return *this;
}
