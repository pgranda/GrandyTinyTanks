#ifndef _MAPMANAGER_H_
#define _MAPMANAGER_H_

#include "Level.h"

class MapManager
{
public:
	MapManager(int a_level);
	/**
	Function that draws Level map.

	@param fGameplayScreenWidth Game play screen width value used to position the objects on map.
	@param fGameplayScreenHeight Game play screen height value used to position the objects on map.
	*/
	void DrawLevelMap(float fGameplayScreenWidth, float fGameplayScreenHeight);

	/**
	Function that undraws Level map.
	*/
	void UndrawMap();

	/**
	Function that returns the Vector containing pointers of Obstacle class objects..

	@return std::vector<Obstacle*> Vector of Obstacle objects pointers.
	*/
	std::vector<Obstacle*> GetObstacles();

	/**
	Function that sets which level is going to be drawn.

	@param a_level Level number.
	*/
	void SetLevel(int a_level);

	/**
	Gets level ID.

	@return levelID.
	*/
	int GetLevel();
private:
	Level* level;
};

#endif
