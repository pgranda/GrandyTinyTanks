#include "Shape.h"
#define _USE_MATH_DEFINES
#include<math.h>

std::vector<Vector2> Shape::GetOutermostVertices()
{
	return outermostVertices;
}

void Shape::AddOutermostVertices(double a_x, double a_y)
{
	outermostVertices.push_back(Vector2((float)(a_x), (float)(a_y)));
}

void Shape::AddOutermostVertices(Vector2 a_point)
{
	outermostVertices.push_back(a_point);
}

void Shape::RemoveOutermostVertices(Vector2 a_point)
{
	auto toRemove = std::find(outermostVertices.begin(), outermostVertices.end(), a_point);
	if (toRemove != outermostVertices.end())
	{
		outermostVertices.erase(toRemove);
	}
}

float Shape::GetWidth()
{
	return width;
}

void Shape::SetWidth(float a_width)
{
	width = a_width;
}

float Shape::GetHeight()
{
	return height;
}

void Shape::SetHeight(float a_height)
{
	height = a_height;
}

//Function which returns farthest point in given vector direction "d"
Vector2 Shape::GetFarthestPointInDirection(Vector2 d)
{
	int index = 0;
	float maxDot = -INFINITY; //We set maxDot to -INFINITY to assure that first loop iteration will always find greater dot

	for (int i = 0; i < outermostVertices.size(); i++)
	{
		Vector2 vertex = outermostVertices.at(i);
		float dot = Vector2::DotProduct(vertex, d);

		if (dot > maxDot)
		{
			maxDot = dot;
			index = i;
		}
	}

	return outermostVertices.at(index);
}

//Function to update every outermost vertex of our object that takes part in collision detection
void Shape::UpdateOutermostVertices(Matrix3 m3PosRot)
{
	Vector3 yAxis;
	Vector3 zAxis;

	m3PosRot.GetRow(1, yAxis);
	m3PosRot.GetRow(2, zAxis);

	Vector2 vector1 = Vector2(-width / 2.f, -height / 2.f);
	Vector2 vector2 = Vector2(-width / 2.f, height / 2.f);
	Vector2 vector3 = Vector2(width / 2.f, -height / 2.f);
	Vector2 vector4 = Vector2(width / 2.f, height / 2.f);

	//If the object was a tank we have to rotate the outermost vertices of our shape along with our tank
	Vector2 rotatedVector1 = Vector2::Rotate(vector1, yAxis.GetX(), yAxis.GetY());
	Vector2 rotatedVector2 = Vector2::Rotate(vector2, yAxis.GetX(), yAxis.GetY());
	Vector2 rotatedVector3 = Vector2::Rotate(vector3, yAxis.GetX(), yAxis.GetY());
	Vector2 rotatedVector4 = Vector2::Rotate(vector4, yAxis.GetX(), yAxis.GetY());

	//From above calculations and actual position of our tank we have to create points which will help us determine collision
	Vector2 point1 = Vector2(zAxis.GetX() + rotatedVector1.GetX(), zAxis.GetY() + rotatedVector1.GetY());
	Vector2 point2 = Vector2(zAxis.GetX() + rotatedVector2.GetX(), zAxis.GetY() + rotatedVector2.GetY());
	Vector2 point3 = Vector2(zAxis.GetX() + rotatedVector3.GetX(), zAxis.GetY() + rotatedVector3.GetY());
	Vector2 point4 = Vector2(zAxis.GetX() + rotatedVector4.GetX(), zAxis.GetY() + rotatedVector4.GetY());

	//Clear vertices from last iteration
	outermostVertices.clear();

	//Add newly calculated vertices
	outermostVertices.push_back(point1);
	outermostVertices.push_back(point2);
	outermostVertices.push_back(point3);
	outermostVertices.push_back(point4);
}

std::string Shape::ToString()
{
	std::string text = "";
	for (int i = 0; i < outermostVertices.size(); i++)
	{
		text = text + std::to_string(outermostVertices.at(i).GetX()) + "," + std::to_string(outermostVertices.at(i).GetY()) + "\n";
	}
	return text;
}

void Shape::ClearOutermostVertices()
{
	outermostVertices.clear();
}

Shape::Shape()
{
	width = 0;
	height = 0;
}

Shape::Shape(float a_width, float a_height)
{
	//Framework is actually drawing sprite smaller than we pass it to the sprite constructor, 
	//so our collision is more accurate when we decrease it by 2 pixels

	width = a_width - 2;
	height = a_height - 2;
}
