#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "Vector2.h"
#include <iostream>
#include <vector>
#include "Matrix3.h" 
#include <string>  

class Shape
{
public:
	Shape();
	Shape(float a_width, float a_height);

	std::vector<Vector2> GetOutermostVertices();
	void AddOutermostVertices(double a_x, double a_y);
	void RemoveOutermostVertices(Vector2 a_point);
	void ClearOutermostVertices();
	void Shape::AddOutermostVertices(Vector2 a_point);

	float GetWidth();
	void SetWidth(float a_width);

	float GetHeight();
	void SetHeight(float a_height);

	Vector2 GetFarthestPointInDirection(Vector2 d);
	virtual void UpdateOutermostVertices(Matrix3 m3PosRot);
	std::string Shape::ToString();

protected:
	std::vector<Vector2> outermostVertices;
	float height;
	float width;
};

#endif _SHAPE_H_
