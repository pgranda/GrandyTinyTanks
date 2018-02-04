#ifndef _POWERUPSFACTORY_H_
#define _POWERUPSFACTORY_H_

#include "AmmoPowerUp.h"
#include "HealthPowerUp.h"
#include "ImmortalityPowerUp.h"
#include "SpeedPowerUp.h"
#include "GJK.h"

class PowerUpsFactory
{
public:
	/**
	Randomly creates new PowerUp class object that should be spawned.

	@param a_id Value obtained from random function to randomly pick which PowerUp should be spawned.
	@param a_GameplayScreenWidth Game play screen width.
	@param a_GameplayScreenHeight Game play screen height.
	@return Pointer to PowerUp class object
	*/
	static PowerUp* GetPowerUp(int a_id, float a_GameplayScreenWidth, float a_GameplayScreenHeight);

private:
};


#endif