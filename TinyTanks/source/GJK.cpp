#include "GJK.h"

/**
Support function to calculate Minkowski Sum between two shapes in given direction vector "d".

@param shape1 Pointer to Shape class object.
@param shape2 Pointer to Shape class object.
@param d Direction vector.
@return p3 Vector2 point placed on the edge of Minkowski Sum area.
*/
Vector2 GJK::Support(Shape* shape1, Shape* shape2, Vector2 d)
{
	//First we get the farthest point in given direction for first shape e.g pTank1
	Vector2 p1 = shape1->GetFarthestPointInDirection(d);

	//Then we have to do the exact same but in the opposite direction for second shape e.g pTank2
	Vector2 negativeD = Vector2(-d.GetX(), -d.GetY());

	Vector2 p2 = shape2->GetFarthestPointInDirection(negativeD);

	//Now we subtract points coordinates we calculated above for two shapes - Minkowski Sum
	Vector2 p3 = p1 - p2;

	//Point p3 is placed on the edge of Minkowski Sum area
	return p3;
}

/**
Function which detects if there was a collision between two shapes.

@param A Pointer to Shape class object.
@param B Pointer to Shape class object.

@return true/false stating if there was or wasn't a collision.
*/
bool GJK::DetectCollision(Shape* A, Shape* B)
{
	//To begin with let us set the initial direction vector
	Vector2 d = Vector2(1, -1);

	//Calculation of first vertex of Simplex polygon in given direction "d"
	simplex.AddOutermostVertices(Support(A, B, d));

	//Now we have to again negate the direction vector
	d = Vector2(-d.GetX(), -d.GetY());

	while (true)
	{
		//We add a new point in the given direction
		simplex.AddOutermostVertices(Support(A, B, d));

		//We get the amount of vertices of our simplex
		int amountOfVertices = static_cast<int>(simplex.GetOutermostVertices().size());
		//Now we get the last added point to the simplex
		Vector2 lastPoint = simplex.GetOutermostVertices().at(amountOfVertices - 1);
		//Now we check if the last point we added passed the origin point
		if (Vector2::DotProduct(lastPoint, d) <= 0)
		{
			//If the last added point didn't pass the origin,
			//it means that our Minkowski Sum cannot possibly contain the origin
			//In a shortcut, we don't have the collision
			simplex.ClearOutermostVertices();
			return false;
		}
		else
		{
			//Minkowski Sum may possibly contain the origin
			//But we have to check if our simplex contains it as well
			if (ContainsOrigin(d))
			{
				//If our simplex contains the origin point then we have the collision
				simplex.ClearOutermostVertices();
				return true;
			}
		}
	}
}

/**
Function which checks if our simplex contains the origin.

@param d Address of direction vector.
@return true/false if the simplex contains the origin.
*/
bool GJK::ContainsOrigin(Vector2& d)
{
	//We get the amount of vertices of our simplex
	int amountOfVertices = static_cast<int>(simplex.GetOutermostVertices().size());
	//We get the last added point to the simplex
	Vector2 a = simplex.GetOutermostVertices().at(amountOfVertices - 1);
	//We negate the a vector
	Vector2 ao = Vector2(-a.GetX(), -a.GetY());

	if (amountOfVertices == 3)
	{
		//Obviously if amount of vertices of a shape is equal to 3 our shape is triangle
		//So we have to get the b and c vertices of our triangle
		Vector2 b = simplex.GetOutermostVertices().at(1);
		Vector2 c = simplex.GetOutermostVertices().at(0);

		//Now we calculate the edges of our triangle
		Vector2 ab = b - a;
		Vector2 ac = c - a;

		//Set direction vector to perpendicular to ab edge
		d = Vector2(-ab.GetY(), ab.GetX());

		//If the d direction is the same as c direction
		//then negate the d direction vector
		if (Vector2::DotProduct(d, c) > 0)
		{
			d = Vector2(-d.GetX(), -d.GetY());
		}

		//If the new d vector perpendicular to ab edge is in the same direction as the ao
		//C point has to be removed from the simplex because it is farthest from the origin point
		if (Vector2::DotProduct(d, ao) > 0)
		{
			simplex.RemoveOutermostVertices(c);
			return false;
		}

		//Now we set the direction to be perpendicular to ac edge
		d = Vector2(-ac.GetY(), ac.GetX());

		//If the d direction is the same as b direction
		//then negate the d direction vector
		if (Vector2::DotProduct(d, b) > 0)
		{
			d = Vector2(-d.GetX(), -d.GetY());
		}

		//If the new d vector perpendicular to ac edge is in the same direction as the ao
		//B point has to be removed from the simplex because it is farthest from the origin point

		if (Vector2::DotProduct(d, ao) > 0)
		{
			simplex.RemoveOutermostVertices(b);
			return false;
		}

		//Origin is within the simplex triangle
		return true;
	}
	else
	{
		//If we don't have 3 vertices yet,
		//Our situation is called line segment case

		//We get the first point added to simplex
		Vector2 b = simplex.GetOutermostVertices().at(0);
		
		//Now we calculate the edge between 2 points - creation of line
		Vector2 ab = b - a;

		//Set the d direction as perpendicular to ab
		d = Vector2(-ab.GetY(), ab.GetX());

		//Negation of the d direction vector
		if (Vector2::DotProduct(d, ao) < 0)
		{
			d = Vector2(-d.GetX(), -d.GetY());
		}
	}
	return false;
}

GJK::GJK()
{
}