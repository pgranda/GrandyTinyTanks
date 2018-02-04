#include "Pencil.h"

/**
Function to update outermost vertices of an object.

@param m3PosRot 3x3 Matrix containing position and rotation of an object.
*/
void Pencil::UpdateOutermostVertices()
{
	//Clear vertices from last iteration
	outermostVertices.clear();

	Vector3 yAxis;
	Vector3 zAxis;

	m3PosRot.GetRow(1, yAxis);
	m3PosRot.GetRow(2, zAxis);

	float tipLength = 155.f / 1379.f * width;

	//First we create outermost vertices of our object as it would be placed perpendicular to the Cartesian system
	Vector2 vector1;
	Vector2 vector2;

	if (tips == 1)
	{
		vector1 = Vector2(-width / 2.f, -height / 2.f);
		vector2 = Vector2(-width / 2.f, height / 2.f);
	}
	else if (tips == 2)
	{
		vector1 = Vector2(-width / 2.f + tipLength, -height / 2.f);
		vector2 = Vector2(-width / 2.f + tipLength, height / 2.f);

		Vector2 vector6 = Vector2(-width / 2.f, 0);
		Vector2 rotatedVector6 = Vector2::Rotate(vector6, yAxis.GetX(), yAxis.GetY());
		Vector2 point6 = Vector2(zAxis.GetX() + rotatedVector6.GetX(), zAxis.GetY() + rotatedVector6.GetY());
		outermostVertices.push_back(point6);
	}

	Vector2 vector3 = Vector2(width / 2.f - tipLength, -height / 2.f);
	Vector2 vector4 = Vector2(width / 2.f - tipLength, height / 2.f);
	Vector2 vector5 = Vector2(width / 2.f, 0);

	//If the object was a tank we have to rotate the outermost vertices of our shape along with our tank
	Vector2 rotatedVector1 = Vector2::Rotate(vector1, yAxis.GetX(), yAxis.GetY());
	Vector2 rotatedVector2 = Vector2::Rotate(vector2, yAxis.GetX(), yAxis.GetY());
	Vector2 rotatedVector3 = Vector2::Rotate(vector3, yAxis.GetX(), yAxis.GetY());
	Vector2 rotatedVector4 = Vector2::Rotate(vector4, yAxis.GetX(), yAxis.GetY());
	Vector2 rotatedVector5 = Vector2::Rotate(vector5, yAxis.GetX(), yAxis.GetY());

	//From above calculations and actual position of our tank we have to create points which will help us determine collision
	Vector2 point1 = Vector2(zAxis.GetX() + rotatedVector1.GetX(), zAxis.GetY() + rotatedVector1.GetY());
	Vector2 point2 = Vector2(zAxis.GetX() + rotatedVector2.GetX(), zAxis.GetY() + rotatedVector2.GetY());
	Vector2 point3 = Vector2(zAxis.GetX() + rotatedVector3.GetX(), zAxis.GetY() + rotatedVector3.GetY());
	Vector2 point4 = Vector2(zAxis.GetX() + rotatedVector4.GetX(), zAxis.GetY() + rotatedVector4.GetY());
	Vector2 point5 = Vector2(zAxis.GetX() + rotatedVector5.GetX(), zAxis.GetY() + rotatedVector5.GetY());

	//Add newly calculated vertices
	outermostVertices.push_back(point1);
	outermostVertices.push_back(point2);
	outermostVertices.push_back(point3);
	outermostVertices.push_back(point4);
	outermostVertices.push_back(point5);
}

Pencil::Pencil(const char* a_fileName, int a_width, int a_height, Vector2 a_position, float a_angle, int a_tips)
	:Obstacle(a_fileName, a_width, a_height, a_position, a_angle)
{
	tips = a_tips;
	outermostVertices.clear();
	UpdateOutermostVertices();
}

