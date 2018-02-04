#include "MapManager.h"
#include "LevelOne.h"
#include "LevelTwo.h"
#include "LevelThree.h"

/**
Function that returns the Vector containing pointers of Obstacle class objects..

@return std::vector<Obstacle*> Vector of Obstacle objects pointers.
*/
std::vector<Obstacle*> MapManager::GetObstacles()
{
	return level->obstacles;
}

/**
Function that draws Level map.

@param fGameplayScreenWidth Game play screen width value used to position the objects on map.
@param fGameplayScreenHeight Game play screen height value used to position the objects on map.
*/
void MapManager::DrawLevelMap(float fGameplayScreenWidth, float fGameplayScreenHeight)
{
	level->DrawMap(fGameplayScreenWidth, fGameplayScreenHeight);
}

/**
Function that sets which level is going to be drawn.

@param a_level Level number.
*/
void MapManager::SetLevel(int a_level)
{
	if (level != NULL)
	{
		level->UndrawMap();
	}

	switch (a_level)
	{
	case 1:
		level = new LevelOne();
		break;
	case 2:
		level = new LevelTwo();
		break;
	case 3:
		level = new LevelThree();
		break;
	default:
		break;
	}
}

/**
Gets level ID.

@return levelID.
*/
int MapManager::GetLevel()
{
	return level->levelID;
}

/**
Function that undraws Level map.
*/
void MapManager::UndrawMap()
{
	level->UndrawMap();
}

MapManager::MapManager(int a_level)
{
	SetLevel(a_level);
}