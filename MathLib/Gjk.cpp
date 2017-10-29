////////////////////////////////////////////////////////////////////
// File: <Gjk.cpp>
// Author: <Alex Kitching>
// Date Created: <18/05/17>
// Brief: <Source file for the Gjk Class.>
////////////////////////////////////////////////////////////////////

#include "Gjk.h"

CollisionAlgorithms::Gjk::Gjk(const Vector3* a_v3Vertices1, size_t a_count1, const Vector3* a_v3Vertices2, size_t a_count2)
{
	// Assign Variables
	v3Vertices1 = a_v3Vertices1;
	iCount1 = a_count1;
	v3Vertices2 = a_v3Vertices2;
	iCount2 = a_count2;
}

bool CollisionAlgorithms::Gjk::IsColliding()
{
	Vector3 v3Dir = Vector3(1.f, -1.f, 0.f);
	
	size_t index = 0; // Index to Iterate Through

	// Setup First Point
	v3Simplex.push_back(Support(v3Dir));

	// Negate Direction for Next Point
	v3Dir = -v3Dir;

	// Start Looping
	while (true)
	{
		// Add new point to Simplex because no termination yet
		v3Simplex.push_back(Support(v3Dir));

		// Ensure Last Point passed origin
		if (v3Simplex.back().DotProduct(v3Dir) <= 0)
		{
			// If the point added last is not past origin
			// Then Minkowski Sum cannot contain origin
			return false;
		}
		else
		{
			if (ContainsOrigin(v3Dir))
			{
				// If it does, collision occurred
				return true;
			}
		}
		
	}
	return false;
}

Vector3 CollisionAlgorithms::Gjk::TripleProduct(Vector3 & a_vecA, Vector3 & a_vecB, Vector3 & a_vecC)
{
	Vector3 v3Result = Vector3::Zero;

	// Setup Dot Products
	float ac = a_vecA.DotProduct(a_vecC);
	float bc = a_vecB.DotProduct(a_vecC);

	// Perform b * ac - a * bc
	v3Result.SetX(a_vecB.GetX() * ac - a_vecA.GetX() * bc);
	v3Result.SetY(a_vecB.GetY() * ac - a_vecA.GetY() * bc);
	return v3Result;
}

Vector3 CollisionAlgorithms::Gjk::AveragePoint(const Vector3 * a_vertices, size_t a_count)
{
	Vector3 v3Average = Vector3::Zero;

	// Sum Vert X and Y Coordinates
	for (size_t i = 0; i < a_count; i++) // Iterating Through Each Point
	{
		// Get Average Components
		float fAverageX = v3Average.GetX();
		float fAverageY = v3Average.GetY();

		// Get Vert Components
		float fVertX = a_vertices[i].GetX();
		float fVertY = a_vertices[i].GetY();

		// Add to Sum
		fAverageX += fVertX;
		fAverageY += fVertY;

		// Set Average Components
		v3Average.SetX(fAverageX);
		v3Average.SetY(fAverageY);
	}

	// Get The Mean X and Y Coords (Center)
	v3Average /= a_count;

	return v3Average;
}

Vector3 CollisionAlgorithms::Gjk::FindFurthestPoint(const Vector3* a_vertices, size_t a_count, Vector3& a_dirVec)
{
	size_t index = 0;
	// Initialise Furthest Point to First Vert
	float fMaxDotProduct = a_vertices[index].DotProduct(a_dirVec);

	for (int i = 1; i < a_count; i++)
	{ // Loop Through each vert and compare Distances
		float fProduct = a_vertices[i].DotProduct(a_dirVec);

		if (fProduct > fMaxDotProduct)
		{ // New Product is Larger than Previous Largest Product
		  // Update Max Product
			fMaxDotProduct = fProduct;
			index = i;
		}
	}

	return a_vertices[index];
}

Vector3 CollisionAlgorithms::Gjk::Support(Vector3& a_dirVec)
{
	// Get Furthest point of first object along direction
	Vector3 v3FurthestPoint1 = FindFurthestPoint(v3Vertices1, iCount1, a_dirVec);
	// Get Furthest point of second object along opposite direction
	Vector3 v3FurthestPoint2 = FindFurthestPoint(v3Vertices2, iCount2, -a_dirVec);

	// Subtract two points to see if objects overlap (Minkowski Difference)
	return v3FurthestPoint1 - v3FurthestPoint2;
}

bool CollisionAlgorithms::Gjk::ContainsOrigin(Vector3& a_dirVec)
{
	// Get last point added to Simplex
	Vector3 v3A = v3Simplex.back();
	// Compute A to Origin (Same As -A)
	Vector3 v3AO = -v3A;

	// Triangle ABC
	if (v3Simplex.size() == 3)
	{
		// We Get ABC
		Vector3 v3B = v3Simplex[1];
		Vector3 v3C = v3Simplex[0];

		// Get A-B and A-C Vectors
		Vector3 v3AB = v3B - v3A;
		Vector3 v3AC = v3C - v3A;

		// Direction Perpendicular to AB
		a_dirVec = v3AB.Perpendicular();

		// Away from C
		if (a_dirVec.DotProduct(v3C) > 0) // If Same Direction invert direction
		{
			a_dirVec = -a_dirVec;
		}

		// If dirVec perpendicular on AB is same direction with origin
		// It means that C is furthest from origin so we need to remove and create a new simplex
		if (a_dirVec.DotProduct(v3AO) > 0) // Same Direction
		{
			v3Simplex.erase(v3Simplex.begin()); // Remove First Element (C)
			return false;
		}

		// Direction Perpendicular to AC
		a_dirVec = v3AC.Perpendicular();

		// Away from B
		if (a_dirVec.DotProduct(v3B) > 0) // If Same Direction invert direction
		{
			a_dirVec = -a_dirVec;
		}

		// If dirVec perpendicular on AC is same direction with origin
		// It means that B is furthest from origin and remove to create a new simplex
		if (a_dirVec.DotProduct(v3AO) > 0)
		{
			v3Simplex.erase(v3Simplex.begin() + 1); // Remove Second Element (C)
			return false;
		}

		// Origin must be inside triangle so this is the simplex
		return true;
	}
	else // Must be line
	{
		Vector3 v3B = v3Simplex[0];
		
		// We Get AB
		Vector3 v3AB = v3B - v3A;

		// Direction perpendicular to AB, to origin
		a_dirVec = v3AB.Perpendicular();
		if (a_dirVec.DotProduct(v3AO) < 0)
		{
			a_dirVec = -a_dirVec;
		}
	}
	return false;
}
