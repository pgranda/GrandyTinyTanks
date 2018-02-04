#ifndef _LEVELONE_H_
#define _LEVELONE_H_

#include "Level.h"

class LevelOne : public Level
{
public:
	LevelOne();
	/**
	Function that draws Level One map.

	@param fGameplayScreenWidth Game play screen width value used to position the objects on map.
	@param fGameplayScreenHeight Game play screen height value used to position the objects on map.
	*/
	void DrawMap(float fGameplayScreenWidth, float fGameplayScreenHeight);

private:
};


#endif
