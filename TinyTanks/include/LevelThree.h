#ifndef _LEVELTHREE_H_
#define _LEVELTHREE_H_

#include "Level.h"

class LevelThree : public Level
{
public:
	LevelThree();
	/**
	Function that draws Level Three map.

	@param fGameplayScreenWidth Game play screen width value used to position the objects on map.
	@param fGameplayScreenHeight Game play screen height value used to position the objects on map.
	*/
	void DrawMap(float fGameplayScreenWidth, float fGameplayScreenHeight);

private:
};


#endif
