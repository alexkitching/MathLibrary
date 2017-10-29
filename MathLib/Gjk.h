/////////////////////////////////////////////////////////////////////////////////////
// File: <Gjk.h>
// Author: <Alex Kitching>
// Date Created: <18/05/17>
// Brief: <Header file for the Gjk class, functions and variables.>
/////////////////////////////////////////////////////////////////////////////////////

#ifndef _Gjk_H_
#define __Gjk_H__H_

#include "Vector3.h"
#include <vector>



namespace CollisionAlgorithms
{
	class Gjk
	{
	
	public:
		// Constructors
		Gjk(const Vector3* a_v3Vertices1, size_t a_count1, const Vector3* a_v3Vertices2, size_t a_count2);
		~Gjk() {};

		// Functions
		bool IsColliding();

	private:
		// Functions
		// Triple Product (Used to Calculate Perpendicular Normal Vectors)
		Vector3 TripleProduct(Vector3& a_vecA, Vector3& a_vecB, Vector3& a_vecC);

		// Return Center Point
		Vector3 AveragePoint(const Vector3* a_vertices, size_t a_count);

		// Get Furthest Vert along Direction
		Vector3 FindFurthestPoint(const Vector3* a_vertices, size_t a_count, Vector3& a_dirVec);

		// GJK Support Function
		Vector3 Support(Vector3& a_dirVec);

		// Check for Containing Origin
		bool ContainsOrigin(Vector3& a_dirVec);

		// Variables
		// Object 1 Parameters
	    const Vector3 *v3Vertices1;
		size_t iCount1;	
		// Object 2 Parameters
		const Vector3 *v3Vertices2;
		size_t iCount2;

		std::vector<Vector3> v3Simplex;
	};
}

#endif