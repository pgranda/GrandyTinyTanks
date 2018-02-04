#ifndef _GJK_H_
#define _GJK_H_

#include <iostream>
#include "Shape.h"
#include "Vector2.h"

class GJK
{
public:
	GJK();

	/**
	Support function to calculate Minkowski Sum between two shapes in given direction vector "d".

	@param shape1 Pointer to Shape class object.
	@param shape2 Pointer to Shape class object.
	@param d Direction vector.
	@return p3 Vector2 point placed on the edge of Minkowski Sum area.
	*/
	Vector2 Support(Shape* shape1, Shape* shape2, Vector2 d);

	/**
	Function which detects if there was a collision between two shapes.

	@param A Pointer to Shape class object.
	@param B Pointer to Shape class object.

	@return true/false stating if there was or wasn't a collision.
	*/
	bool DetectCollision(Shape* A, Shape* B);

	/**
	Function which checks if our simplex contains the origin.

	@param d Address of direction vector.
	@return true/false if the simplex contains the origin.
	*/
	bool ContainsOrigin(Vector2& d);

private:
	//Simplex is a polygon that arrises from Minkowski Sum points
	Shape simplex;
};

#endif _GJK_H_s