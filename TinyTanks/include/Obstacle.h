#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#define _USE_MATH_DEFINES

#include <math.h>

#include "Tank.h"

class Obstacle : public Sprite, public Shape
{
public:
	Obstacle(const char* a_fileName, int a_width, int a_height, Vector2 a_position, float a_angle);

private:

};

#endif