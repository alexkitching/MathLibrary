/////////////////////////////////////////////////////////////////////////////////////
// File: <BoxBoxCollision.h>
// Author: <Alex Kitching>
// Date Created: <18/05/17>
// Brief: <Header file for the BoxBoxCollision class, functions and variables.>
/////////////////////////////////////////////////////////////////////////////////////

#ifndef _BoxBoxCollision_H_
#define _BoxBoxCollision_H_

#include "Vector2.h"
#include "Vector3.h"

namespace CollisionAlgorithms
{
	class BoxBoxCollision
	{
	public:
		// Constructors 
		BoxBoxCollision(const Vector3 a_v3Obj1Pos, const Vector2 a_v2Obj1Dimensions, const Vector3 a_v3Obj2Pos, const Vector2 a_v2Obj2Dimensions);
		~BoxBoxCollision() {};

		// Functions
		bool IsColliding();

	private:

		// Variables
		// Object 1 Parameters
		Vector3 v3Obj1Pos;
		Vector2 v2Obj1Dimensions;
		// Object 2 Parameters
		Vector3 v3Obj2Pos;
		Vector2 v2Obj2Dimensions;
	};
}

#endif