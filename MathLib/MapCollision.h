/////////////////////////////////////////////////////////////////////////////////////
// File: <MapCollision.h>
// Author: <Alex Kitching>
// Date Created: <22/05/17>
// Brief: <Header file for the MapCollision class, functions and variables.>
/////////////////////////////////////////////////////////////////////////////////////

#ifndef _MapCollision_H_
#define _MapCollision_H_

#include "Vector2.h"
#include "Vector3.h"

namespace CollisionAlgorithms
{
	class MapCollision
	{
	public:
		MapCollision(const Vector2 a_v2MapDimensions, const Vector2 a_v2ObjDimensions, const Vector3 a_v3ObjPos);
		~MapCollision() {};
		
		// Functions
		bool IsColliding();
	private:

		// Variables
		// Map
		Vector2 v2MapDimensions;
		float fMapBorderWidth;
		// Object
		Vector2 v2ObjDimensions;
		Vector3 v3ObjPos;
	};
}

#endif // !_MapCollision_H_
