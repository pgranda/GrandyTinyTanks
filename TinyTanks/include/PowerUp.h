#ifndef _POWERUP_H_
#define _POWERUP_H_

#include "Obstacle.h"

class PowerUp : public Obstacle
{
public:
	PowerUp(const char* a_fileName, int a_width, int a_height, Vector2 a_position, float a_angle);

	/**
	VIRTUAL FUNCTION
	Executes the power up event on a tank.

	@param a_pTank Pointer to the Tank class object that collided with power up.
	*/
	virtual void ExecutePowerUpEvent(Tank* a_pTank);

	/**
	VIRTUAL FUNCTION
	Displays information on the HUD saying if the tank has the power up effect.

	@param a_fGameplayScreenWidth Game play screen width
	@param a_iScreenHeight Screen height
	@param a_multiplicator Value which we use to multiply the a_fGameplayScreenWidth to set the right position on screen.
	*/
	virtual void DisplayPowerUpInformation(float a_fGameplayScreenWidth, int a_iScreenHeight, float a_multiplicator);

private:
};


#endif
