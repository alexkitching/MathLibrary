////////////////////////////////////////////////////////////////////
// File: <Vector2.h>
// Author: <Alex Kitching>
// Date Created: <09/02/17>
// Brief: <Header file for the Vector2 Class.>
////////////////////////////////////////////////////////////////////

#ifndef _VECTOR2_H_
#define _VECTOR2_H_

class Vector3;
class Vector2
{
public:
	// Default Constructor
	Vector2();
	// Custom Constructor
	Vector2(const float a_fX, const float a_fY);
	Vector2(const Vector3 a_v3Vec);
	// Copy Constructor
	Vector2(const Vector2& a_vec);
	// Destructor
	~Vector2();


	// Static Variables
	static const Vector2 Up;
	static const Vector2 Down;
	static const Vector2 Right;
	static const Vector2 Left;
	static const Vector2 Zero;
	static const Vector2 One;

	// Magnitude
	float const Magnitude();
	// Magnitude Squared
	float const MagnitudeSquared();

	// Distance
	float const Distance(const Vector2& a_vec) const;
	// Distance Squared
	float const DistanceSquared(const Vector2& a_vec) const;

	// Normalise
	void const Normalise();

	// Return Normalise (ReadOnly)
	Vector2 const GetUnitVector();

	// Return Perpendicular Vector
	Vector2 Perpendicular();

	// Find Angle Between Another Vector
	float const Angle(const Vector2& a_vec)  const;

	// Dot Product
	float const DotProduct(const Vector2& a_vec) const;

	// Curve Functions
	Vector2 Lerp(Vector2 a_vec0, Vector2 a_vec1, float a_tan);
	Vector2 QuadBezier(Vector2 a_vec0, Vector2 a_vec1, Vector2 a_vec2, float a_tan);
	Vector2 HermiteSpline(Vector2 a_point0, Vector2 a_point1, Vector2 a_tan0, Vector2 a_tan1, float a_fTime);
	Vector2 CardinalSpline(Vector2 a_point0, Vector2 a_point1, Vector2 a_point2, float a, float a_fTime);


	// Set Values
	void Set(float a_fX, float a_fY);
	void SetX(float a_fX);
	void SetY(float a_fY);
	// Get Values
	Vector2 Get()const;
	void Get(float& a_rfX, float& a_rfY)const;
	float GetX()const;
	void GetX(float& a_fX)const;
	float GetY()const;
	void GetY(float& a_fY)const;

	// Set Random
	void SetRandom(float a_fMin, float a_fMax);
	// Set RandomX
	void SetRandomX(float a_fMin, float a_fMax);
	// Set RandomY
	void SetRandomY(float a_fMin, float a_fMax);

	// Operator Overloads
	operator float* ();
	operator const float*() const;
	// Comparison
	bool Vector2::operator==(const Vector2& a_vec);
	bool Vector2::operator!=(const Vector2& a_vec);
	// Addition
	Vector2 Vector2::operator+(const Vector2& a_vec);
	Vector2 Vector2::operator+(const float& a_fValue);
	friend Vector2 operator+(const float& a_fValue, const Vector2& a_vec);
	Vector2 Vector2::operator+=(const Vector2& a_vec);
	Vector2 Vector2::operator+=(const float& a_fValue);
	// Subtraction
	Vector2 Vector2::operator-() const;
	Vector2 Vector2::operator-(const Vector2& a_vec);
	Vector2 Vector2::operator-(const float& a_fValue);
	friend Vector2 operator-(const float& a_fValue, const Vector2& a_vec);
	Vector2 Vector2::operator-=(const Vector2& a_vec);
	Vector2 Vector2::operator-=(const float& a_fValue);
	// Multiplication
	Vector2 Vector2::operator*(const Vector2& a_vec);
	Vector2 Vector2::operator*(const float& a_fValue);
	friend Vector2 operator*(const float& a_fValue, const Vector2& a_vec);
	Vector2 Vector2::operator*=(const Vector2& a_vec);
	Vector2 Vector2::operator*=(const float& a_fValue);
	// Division
	Vector2 Vector2::operator/(const Vector2& a_vec);
	Vector2 Vector2::operator/(const float& a_fValue);
	friend Vector2 operator/(const float& a_fValue, const Vector2& a_vec);
	Vector2 Vector2::operator/=(const Vector2& a_vec);
	Vector2 Vector2::operator/=(const float& a_fValue);


private:

	// Vector Components
	float fX;
	float fY;
};

#endif //!_VECTOR2_H_