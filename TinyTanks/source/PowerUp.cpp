#include "PowerUp.h"

/**
VIRTUAL FUNCTION
Executes the power up event on a tank.

@param a_pTank Pointer to the Tank class object that collided with power up.
*/
void PowerUp::ExecutePowerUpEvent(Tank* a_pTank)
{

}

/**
VIRTUAL FUNCTION
Displays information on the HUD saying if the tank has the power up effect.

@param a_fGameplayScreenWidth Game play screen width
@param a_iScreenHeight Screen height
@param a_multiplicator Value which we use to multiply the a_fGameplayScreenWidth to set the right position on screen.
*/
void PowerUp::DisplayPowerUpInformation(float a_fGameplayScreenWidth, int a_iScreenHeight, float a_multiplicator)
{

}

PowerUp::PowerUp(const char* a_fileName, int a_width, int a_height, Vector2 a_position, float a_angle) 
	:Obstacle(a_fileName, a_width, a_height, a_position, a_angle)
{

}