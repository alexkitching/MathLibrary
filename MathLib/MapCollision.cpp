#include "MapCollision.h"

CollisionAlgorithms::MapCollision::MapCollision(const Vector2 a_v2MapDimensions, const Vector2 a_v2ObjDimensions, const Vector3 a_v3ObjPos) :
	fMapBorderWidth(26)
{
	v2MapDimensions = a_v2MapDimensions;
	v2ObjDimensions = a_v2ObjDimensions;
	v3ObjPos = a_v3ObjPos;
}

bool CollisionAlgorithms::MapCollision::IsColliding()
{
	Vector2 v2TopLeftCorner = Vector2(0.f, v2MapDimensions.GetY());
	Vector2 v2TopRightCorner = Vector2(v2MapDimensions.GetX(), v2MapDimensions.GetY());
	Vector2 v2BottomRightCorner = Vector2(v2MapDimensions.GetX(), 0.f);
	Vector2 v2BottomLeftCorner = Vector2::Zero;

	if (v3ObjPos.GetX() >= (v2MapDimensions.GetX() - fMapBorderWidth) - 0.5 * v2ObjDimensions.GetX())
	{ // If at right Map Boundary
		return true;
	}
	else if (v3ObjPos.GetX() <= fMapBorderWidth + 0.5 * v2ObjDimensions.GetX())
	{ // If at left map boundary
		return true;
	}

	if (v3ObjPos.GetY() >= (v2MapDimensions.GetY() -fMapBorderWidth)- 0.5 * v2ObjDimensions.GetY())
	{ // If at top map boundary
		return true;
	}
	else if (v3ObjPos.GetY() <= fMapBorderWidth + 0.5 * v2ObjDimensions.GetY())
	{ // If at bottom map boundary
		return true;
	}
	// If no hit
	return false;
}
