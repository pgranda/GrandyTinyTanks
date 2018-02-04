#include "Level.h"

/**
Function that undraws the map.
*/
void Level::UndrawMap()
{
	UG::StopDrawingSprite(backgroundID);
	UG::DestroySprite(backgroundID);

	for (int i = 0; i < obstacles.size(); i++)
	{
		obstacles.at(i)->StopDrawing();
		obstacles.at(i)->DestroySprite();
	}
	obstacles.clear();
}

void Level::DrawMap(float fGameplayScreenWidth, float fGameplayScreenHeight)
{

}