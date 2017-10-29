////////////////////////////////////////////////////////////////////
// File: <Vector3.h>
// Author: <Alex Kitching>
// Date Created: <09/02/17>
// Brief: <Header file for the Vector3 Class.>
////////////////////////////////////////////////////////////////////

#ifndef _VECTOR3_H_
#define _VECTOR3_H_

class Matrix3;
class Vector2;
class Vector4;
class Vector3
{
public:
	// Default Constructor
	Vector3();
	// Custom Constructors
	Vector3(float a_fX, float a_fY, float a_fZ);
	Vector3(Vector4 a_v4Vec);
	Vector3(Vector2 a_v3Vec, float a_fZ);
	Vector3(Vector2 a_v2Vec);

	// Copy Constructor
	Vector3(const Vector3& a_v3Vec);
	// Destructor
	~Vector3();

	// Static Variables
	static const Vector3 Up;
	static const Vector3 Down;
	static const Vector3 Right;
	static const Vector3 Left;
	static const Vector3 Forward;
	static const Vector3 Back;
	static const Vector3 Zero;
	static const Vector3 One;

	// Magnitude
	float const Magnitude();
	// Magnitude Squared
	float const MagnitudeSquared();

	// Distance
	float const Distance(Vector3& a_v3Vec);
	// Distance Squared
	float const DistanceSquared(Vector3& a_v3Vec);

	// Normalise
	void const Normalise();

	// Return Normalise (ReadOnly)
	Vector3 const GetUnitVector();

	// Return Perpendicular Vector
	Vector3 Perpendicular();

	Vector3 Reflect(Vector3 a_v3Velocity, Vector3 a_v3Normal);

	// Find Angle Between Another Vector
	float const Angle2D(Vector3& a_v3Vec);

	// Dot Product
	float const DotProduct(const Vector3& a_v3Vec) const;
	// Cross Product
	Vector3 const CrossProduct(Vector3& a_v3Vec) const;

	// Curve Functions
	Vector3 Lerp(Vector3 a_v3Vec0, Vector3 a_v3Vec1, float a_fTime);
	Vector3 QuadBezier(Vector3 a_v3Vec0, Vector3 a_v3Vec1, Vector3 a_v3Vec2, float a_fTime);
	Vector3 HermiteSpline(Vector3 a_v3Point0, Vector3 a_v3Point1, Vector3 a_v3Tan0, Vector3 a_v3Tan1, float a_fTime);
	Vector3 CardinalSpline(Vector3 a_v3Point0, Vector3 a_v3Point1, Vector3 a_v3Point2, float a_fA, float a_fTime);

	// Set Values
	void Set(float a_fX, float a_fY, float  a_fZ);
	void SetX(float a_fX);
	void SetY(float a_fY);
	void SetZ(float a_fZ);

	// Get Values
	Vector3 Get()const;
	void Get(float& a_fX, float& a_fY, float&  a_fZ)const;
	float GetX()const;
	void GetX(float& a_fX)const;
	float GetY()const;
	void GetY(float& a_fY)const;
	float GetZ()const;
	void GetZ(float& a_fZ)const;

	// Set Random
	void SetRandom(float a_fMin, float a_fMax);
	// Set RandomX
	void SetRandomX(float a_fMin, float a_fMax);
	// Set RandomY
	void SetRandomY(float a_fMin, float a_fMax);
	// Set RandomZ
	void SetRandomZ(float a_fMin, float a_fMax);

	// Operator Overloads
	operator float* ();
	operator const float*() const;
	// Comparison
	bool Vector3::operator==(const Vector3& a_v3Vec);
	bool Vector3::operator!=(const Vector3& a_v3Vec);

	// Addition
	Vector3 Vector3::operator+(const Vector3& a_v3Vec);
	Vector3 Vector3::operator+(const float& a_fValue);
	friend Vector3 operator+(const float& a_fValue, const Vector3& a_v3Vec);
	Vector3 Vector3::operator+=(const Vector3& a_v3Vec);
	Vector3 Vector3::operator+=(const float& a_fValue);

	// Subtraction
	Vector3 Vector3::operator-() const;
	Vector3 Vector3::operator-(const Vector3& a_v3Vec);
	Vector3 Vector3::operator-(const float& a_fValue);
	friend Vector3 operator-(const float& a_fValue, const Vector3& a_v3Vec);
	Vector3 Vector3::operator-=(const Vector3& a_v3Vec);
	Vector3 Vector3::operator-=(const float& a_fValue);

	// Multiplication
	Vector3 Vector3::operator*(const Vector3& a_v3Vec);
	Vector3 Vector3::operator*(const float& a_fValue);
	friend Vector3 operator*(const float& a_fValue, const Vector3& a_v3Vec);
	Vector3 Vector3::operator*(const Matrix3& a_m3Mat);
	Vector3 Vector3::operator*=(const Vector3& a_v3Vec);
	Vector3 Vector3::operator*=(const float& a_fValue);
	Vector3 Vector3::operator*=(const Matrix3& a_m3Mat);

	// Division
	Vector3 Vector3::operator/(const Vector3& a_v3Vec);
	Vector3 Vector3::operator/(const float& a_fValue);
	friend Vector3 operator/(const float& a_fValue, const Vector3& a_v3Vec);
	Vector3 Vector3::operator/=(const Vector3& a_v3Vec);
	Vector3 Vector3::operator/=(const float& a_fValue);

private:

	// Vector Components
	float fX;
	float fY;
	// Translation Component (2D Only, 0 - Position 1 - Direction)
	float fZ;
};

#endif //!_VECTOR3_H_