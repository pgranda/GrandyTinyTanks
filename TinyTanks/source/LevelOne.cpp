#include "LevelOne.h"

/**
Function that draws Level One map.

@param fGameplayScreenWidth Game play screen width value used to position the objects on map.
@param fGameplayScreenHeight Game play screen height value used to position the objects on map.
*/
void LevelOne::DrawMap(float fGameplayScreenWidth, float fGameplayScreenHeight)
{
	UndrawMap();

	//Background
	backgroundID = UG::CreateSprite("./images/woodtex.png", 1280, 960, true);
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
	obstacles.push_back(new Obstacle("./images/eraser2.png", 150, 56, Vector2(fGameplayScreenWidth * 0.75f, fGameplayScreenHeight * 0.75f), 180));

	obstacles.push_back(new Obstacle("./images/eraser2.png", 150, 56, Vector2(fGameplayScreenWidth * 0.86f, fGameplayScreenHeight * 0.80f), 225));

	obstacles.push_back(new Obstacle("./images/eraser2.png", 150, 56, Vector2(fGameplayScreenWidth * 0.25f, fGameplayScreenHeight * 0.25f), 0));

	obstacles.push_back(new Obstacle("./images/eraser2.png", 150, 56, Vector2(fGameplayScreenWidth * 0.14f, fGameplayScreenHeight * 0.20f), 45));

	//Pencils
	obstacles.push_back(new Pencil("./images/pencil2.png", 400, 20, Vector2(fGameplayScreenWidth * 0.5f, fGameplayScreenHeight * 0.5f), 45, 2));

	obstacles.push_back(new Pencil("./images/pencil2.png", 400, 20, Vector2(fGameplayScreenWidth * 0.5f, fGameplayScreenHeight * 0.5f), 135, 2));

	//Sharpeners
	obstacles.push_back(new Obstacle("./images/sharpener3.png", 200, 148, Vector2(fGameplayScreenWidth * 0.2f, fGameplayScreenHeight * 0.65f), 180));

	obstacles.push_back(new Obstacle("./images/sharpener3.png", 200, 148, Vector2(fGameplayScreenWidth * 0.8f, fGameplayScreenHeight * 0.35f), 0));
}

LevelOne::LevelOne()
{
	levelID = 1;
}