#include "PowerUpsFactory.h"

/**
Randomly creates new PowerUp class object that should be spawned.

@param a_id Value obtained from random function to randomly pick which PowerUp should be spawned.
@param a_GameplayScreenWidth Game play screen width.
@param a_GameplayScreenHeight Game play screen height.
@return Pointer to PowerUp class object
*/
PowerUp* PowerUpsFactory::GetPowerUp(int a_id, float a_GameplayScreenWidth, float a_GameplayScreenHeight)
{
	switch (a_id)
	{
	case 0:
		return new AmmoPowerUp("./images/ammo.png", 72, 82, Vector2(a_GameplayScreenWidth, a_GameplayScreenHeight), 0);
	case 1:
		return new HealthPowerUp("./images/hp.png", 60, 56, Vector2(a_GameplayScreenWidth, a_GameplayScreenHeight), 0);
	case 2:
		return new ImmortalityPowerUp("./images/shield.png", 60, 70, Vector2(a_GameplayScreenWidth, a_GameplayScreenHeight), 0);
	case 3:
		return new SpeedPowerUp("./images/fuel.png", 60, 84, Vector2(a_GameplayScreenWidth, a_GameplayScreenHeight), 0);
	default:
		return NULL;
	}
}