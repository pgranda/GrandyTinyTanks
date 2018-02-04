#ifndef _HEALTH_H_
#define _HEALTH_H_

#include "Turret.h"
#include <sstream>

class Health
{
public:
	Health(int a_hp, int a_healthBarPosX, int a_healthBarPosY);
	int GetHp();
	void SetHp(int a_hp);
	void SetPlayerHPImage();
	void UndrawPlayerHpImages();

private:
	int hp;
	int healthBarPosX;
	int healthBarPosY;
	int iHealthBarID;
};

#endif