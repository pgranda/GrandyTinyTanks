#include "Obstacle.h"

Obstacle::Obstacle(const char* a_fileName, int a_width, int a_height, Vector2 a_position, float a_angle)
	:Sprite(a_fileName, a_width, a_height, Vector2(0.5f, 0.5f)), Shape((float)(a_width), (float)(a_height))
{
	SetPosition(a_position);
	RotateZ((float)(a_angle * M_PI / 180.f));
	MarkForDraw();
	SetLayer(0);
	MoveSprite(Vector3(0,0,0));
	Update(0);
	UpdateOutermostVertices(m3PosRot);
}

