#include "LevelTwo.h"

/**
Function that draws Level Two map.

@param fGameplayScreenWidth Game play screen width value used to position the objects on map.
@param fGameplayScreenHeight Game play screen height value used to position the objects on map.
*/
void LevelTwo::DrawMap(float fGameplayScreenWidth, float fGameplayScreenHeight)
{
	UndrawMap();

	//Background
	backgroundID = UG::CreateSprite("./images/papertex.png", 1280, 960, true);
	UG::MoveSprite(backgroundID, fGameplayScreenWidth * 0.5f, fGameplayScreenHeight * 0.5f);
	UG::SetSpriteLayer(backgroundID, 0);
	UG::DrawSprite(backgroundID);

	//Borders

	//Top
	obstacles.push_back(new Pencil("./images/halfpencil.png", 1280, 40, Vector2(fGameplayScreenWidth * 0.5f, fGameplayScreenHeight), 0, 1));

	//Bottom
	obstacles.push_back(new Pencil("./images/pencil.png", 1280, 40, Vector2(fGameplayScreenWidth * 0.5f, 0), 180, 1));

	//Right
	obstacles.push_back(new Pencil("./images/pencil.png", 960, 40, Vector2(fGameplayScreenWidth, fGameplayScreenHeight * 0.5f), 270, 1));

	//Left
	obstacles.push_back(new Pencil("./images/pencil.png", 960, 40, Vector2(0, fGameplayScreenHeight * 0.5f), 90, 1));

	//Obstacles

	//Erasers
	obstacles.push_back(new Obstacle("./images/eraser2.png", 150, 56, Vector2(fGameplayScreenWidth * 0.81f, fGameplayScreenHeight * 0.725f), -25));

	obstacles.push_back(new Obstacle("./images/eraser2.png", 150, 56, Vector2(fGameplayScreenWidth * 0.925f, fGameplayScreenHeight * 0.70f), 0));

	obstacles.push_back(new Obstacle("./images/eraser2.png", 150, 56, Vector2(fGameplayScreenWidth * 0.19f, fGameplayScreenHeight * 0.275f), 155));

	obstacles.push_back(new Obstacle("./images/eraser2.png", 150, 56, Vector2(fGameplayScreenWidth * 0.075f, fGameplayScreenHeight * 0.30f), 180));

	//Pencils
	obstacles.push_back(new Pencil("./images/pencil2.png", 400, 20, Vector2(fGameplayScreenWidth * 0.5f, fGameplayScreenHeight * 0.5f), 0, 2));

	obstacles.push_back(new Pencil("./images/pencil2.png", 400, 20, Vector2(fGameplayScreenWidth * 0.5f, fGameplayScreenHeight * 0.5f), 90, 2));

	//Sharpeners
	obstacles.push_back(new Obstacle("./images/sharpener3.png", 200, 148, Vector2(fGameplayScreenWidth * 0.905f, fGameplayScreenHeight * 0.3f), 180));

	obstacles.push_back(new Obstacle("./images/sharpener3.png", 200, 148, Vector2(fGameplayScreenWidth * 0.095f, fGameplayScreenHeight * 0.7f), 0));

}

LevelTwo::LevelTwo()
{
	levelID = 2;
}