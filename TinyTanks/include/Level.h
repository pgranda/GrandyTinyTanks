#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "Pencil.h"

class Level
{
public:
	virtual void DrawMap(float fGameplayScreenWidth, float fGameplayScreenHeight);
	/**
	Function that undraws the map.
	*/
	void UndrawMap();

	std::vector<Obstacle*> obstacles;
	int levelID;

protected:

	int backgroundID;
};

#endif
