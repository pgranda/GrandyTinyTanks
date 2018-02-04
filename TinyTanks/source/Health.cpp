#include "Health.h"

/**
Gets Health Points.

@return Returns number of health points.
*/
int Health::GetHp()
{
	return hp;
}

/**
Sets Health Points number.

@param a_hp number of health points to set.
*/
void Health::SetHp(int a_hp)
{
	hp = a_hp;
}

/**
Function that draws Player HP Image on the HUD regarding to Players tank health points.
*/
void Health::SetPlayerHPImage()
{
	if (iHealthBarID != -1)
	{
		UG::StopDrawingSprite(iHealthBarID);
		UG::DestroySprite(iHealthBarID);
	}
	std::stringstream imagePathStream;
	imagePathStream << "./images/hp-bar" << hp << ".png";
	std::string imagePath = imagePathStream.str();
	iHealthBarID = UG::CreateSprite(imagePath.c_str(), 128.f, 24.f, true);
	UG::MoveSprite(iHealthBarID, (float)(healthBarPosX), (float)(healthBarPosY));
	UG::DrawSprite(iHealthBarID);
}

/**
Function that undraws and destroys player health bar image.
*/
void Health::UndrawPlayerHpImages()
{
	UG::StopDrawingSprite(iHealthBarID);
	UG::DestroySprite(iHealthBarID);
}

Health::Health(int a_hp, int a_healthBarPosX, int a_healthBarPosY)
{
	hp = a_hp;
	healthBarPosX = a_healthBarPosX;
	healthBarPosY = a_healthBarPosY;
	iHealthBarID = -1;
}