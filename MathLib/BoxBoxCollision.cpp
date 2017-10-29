#include "BoxBoxCollision.h"
#include <math.h>
#include <limits>

CollisionAlgorithms::BoxBoxCollision::BoxBoxCollision(const Vector3 a_v3Obj1Pos, const Vector2 a_v2Obj1Dimensions, const Vector3 a_v3Obj2Pos, const Vector2 a_v2Obj2Dimensions)
{
	// Setup Variables
	v3Obj1Pos = a_v3Obj1Pos;
	v2Obj1Dimensions = a_v2Obj1Dimensions;
	v3Obj2Pos = a_v3Obj2Pos;
	v2Obj2Dimensions = a_v2Obj2Dimensions;
}

bool CollisionAlgorithms::BoxBoxCollision::IsColliding()
{
	      // Object 1 Boundaries
	float fObj1MaxX = (v3Obj1Pos.GetX() + (0.5 * v2Obj1Dimensions.GetX())),
		  fObj1MinX = (v3Obj1Pos.GetX() - (0.5 * v2Obj1Dimensions.GetX())),
		  fObj1MaxY = (v3Obj1Pos.GetY() + (0.5 * v2Obj1Dimensions.GetY())),
		  fObj1MinY = (v3Obj1Pos.GetY() - (0.5 * v2Obj1Dimensions.GetY())),
		  // Object 2 Boundaries
		  fObj2MaxX = (v3Obj2Pos.GetX() + (0.5 * v2Obj2Dimensions.GetX())),
		  fObj2MinX = (v3Obj2Pos.GetX() - (0.5 * v2Obj2Dimensions.GetX())),
		  fObj2MaxY = (v3Obj2Pos.GetY() + (0.5 * v2Obj2Dimensions.GetY())),
		  fObj2MinY = (v3Obj2Pos.GetY() - (0.5 * v2Obj2Dimensions.GetY()));


	// Check Collision
	if (fObj1MinX < fObj2MaxX &&
		fObj1MaxX > fObj2MinX &&
		fObj1MinY < fObj2MaxY &&
		fObj1MaxY > fObj2MinY)
	{
		// Collision Occured
		return true;
	}
	else
	{
		// No Collision
		return false;
	}
}
