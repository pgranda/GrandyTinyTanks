#ifndef _LEVELTWO_H_
#define _LEVELTWO_H_

#include "Level.h"

class LevelTwo : public Level
{
public:
	LevelTwo();
	/**
	Function that draws Level Two map.

	@param fGameplayScreenWidth Game play screen width value used to position the objects on map.
	@param fGameplayScreenHeight Game play screen height value used to position the objects on map.
	*/
	void DrawMap(float fGameplayScreenWidth, float fGameplayScreenHeight);

private:
};


#endif
