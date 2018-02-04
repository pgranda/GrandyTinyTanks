#ifndef _PENCIL_H_
#define _PENCIL_H_

#define _USE_MATH_DEFINES

#include <math.h>

#include "Obstacle.h"

class Pencil : public Obstacle
{
public:
	Pencil(const char* a_fileName, int a_width, int a_height, Vector2 a_position, float a_angle, int a_tips);

	/**
	Function to update outermost vertices of an object.

	@param m3PosRot 3x3 Matrix containing position and rotation of an object.
	*/
	void UpdateOutermostVertices();

private:
	int tips;
};

#endif