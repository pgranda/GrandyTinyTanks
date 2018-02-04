#include "Tank.h"
#include "PowerUp.h"
#define _USE_MATH_DEFINES

#include <math.h>

/**
Setter to set move left key value to control the tank.

@param a_leftKey Value that we want to pass as width of bullet.
*/
void Tank::SetMoveLeftKey(short a_leftKey)
{
	moveLeftKey = a_leftKey;
}

/**
Setter to set move right key value to control the tank.

@param a_rightKey Value that we want to pass as width of bullet.
*/
void Tank::SetMoveRightKey(short a_rightKey)
{
	moveRightKey = a_rightKey;
}

/**
Setter to set move forward key value to control the tank.

@param a_forwardKey Value that we want to pass as width of bullet.
*/
void Tank::SetMoveForwardKey(short a_forwardKey)
{
	moveForwardKey = a_forwardKey;
}

/**
Setter to set move backward key value to control the tank.

@param a_backwardKey Value that we want to pass as width of bullet.
*/
void Tank::SetMoveBackwardKey(short a_backwardKey)
{
	moveBackwardKey = a_backwardKey;
}

/**
Setter that sets the movement vector value.

@param a_movementVector Movement vector by which we want to move our tank.
*/
void Tank::SetMovementVector(Vector3 a_movementVector)
{
	movementVector = a_movementVector;
}

/**
Setter to set current velocity value.

@param a_currentVelocity Value that we want to pass as current velocity of our tank.
*/
void Tank::SetCurrentVelocity(float a_currentVelocity)
{
	currentVelocity = a_currentVelocity;
}

/**
Setter to set our tanks acceleration value.

@param a_fAccelleration Value that we want to pass as acceleration value.
*/
void Tank::SetAccelleration(float a_fAccelleration)
{
	fAccelleration = a_fAccelleration;
}

/**
Setter to set our tanks health points value.

@param a_hp Value that we want to pass as health points value.
*/
void Tank::SetHp(int a_hp)
{
	if (a_hp < 0)
	{
		a_hp = 0;
	}
	health->SetHp(a_hp);
}

/**
Setter to set power up on our tank.

@param a_powerUp Power up that we want to set on our tank.
*/
void Tank::SetPowerUp(PowerUp* a_powerUp)
{
	ResetPowerUpEffect();
	powerUpStart = std::clock();
	powerUp = a_powerUp;
	powerUp->ExecutePowerUpEvent(this);
}

/**
Setter to set our tank immortality value.

@param a_isImmortal Flag saying if the tank is immortal or not.
*/
void Tank::SetIsImmortal(bool a_isImmortal)
{
	isImmortal = a_isImmortal;
}

/**
Setter to set our tanks maximum velocity value.

@param a_fMaxVelocity Value that we want to pass as maximum velocity value.
*/
void Tank::SetMaxVelocity(float a_fMaxVelocity)
{
	fMaxVelocity = a_fMaxVelocity;
}

/**
Setter to set acceleration multiplication value.

@param a_fAccelerationMultiplicator Value that we want our acceleration to multiply by.
*/
void Tank::SetAccelerationMultiplicator(float a_fAccelerationMultiplicator)
{
	fAccelerationMultiplicator = a_fAccelerationMultiplicator;
}

/**
Setter to set flag indicating the possession of super bullets.

@param a_hasSuperBullets Flag indicating the possession of super bullets.
*/
void Tank::SetHasSuperBullets(bool a_hasSuperBullets)
{
	hasSuperBullets = a_hasSuperBullets;
}

/**
Getter which gets the flag indicating the possession of super bullets.

@return hasSuperBullets Flag indicating the possession of super bullets.
*/
bool Tank::GetHasSuperBullets()
{
	return hasSuperBullets;
}

/**
Getter which gets the value used to multiply the acceleration value.

@return fAccelerationMultiplicator Value used to multiply acceleration value.
*/
float Tank::GetAccelerationMultiplicator()
{
	return fAccelerationMultiplicator;
}

/**
Getter which gets the maximum velocity value.

@return fMaxVelocity Maximum velocity value.
*/
float Tank::GetMaxVelocity()
{
	return fMaxVelocity;
}

/**
Getter which gets the flag indicating the immortality.

@return isImmortal Flag indicating the immortality.
*/
bool Tank::GetIsImmortal()
{
	return isImmortal;
}

/**
Getter which gets the pointer to power up.

@return powerUp Pointer to power up.
*/
PowerUp* Tank::GetPowerUp()
{
	return powerUp;
}

/**
Getter which gets the tank health points value.

@return hp Returns the tank health points value.
*/
int Tank::GetHp()
{
	return health->GetHp();
}

/**
Getter which gets the move tank left key.

@return moveLeftKey Returns move tank left key value.
*/
short Tank::GetMoveLeftKey()
{
	return moveLeftKey;
}

/**
Getter which gets the move tank right key.

@return moveRightKey Returns move tank right key value.
*/
short Tank::GetMoveRightKey()
{
	return moveRightKey;
}

/**
Getter which gets the move tank forward key.

@return moveForwardKey Returns move tank forward key value.
*/
short Tank::GetMoveForwardKey()
{
	return moveForwardKey;
}

/**
Getter which gets the move tank backward key.

@return moveBackwardKey Returns move tank backward key value.
*/
short Tank::GetMoveBackwardKey()
{
	return moveBackwardKey;
}

/**
Getter which gets movement vector.

@return movementVector Returns movement vector.
*/
Vector3 Tank::GetMovementVector()
{
	return movementVector;
}

/**
Getter which gets current velocity value.

@return currentVelocity Returns current velocity value.
*/
float Tank::GetCurrentVelocity()
{
	return currentVelocity;
}

/**
Function which resets power up effects.
*/
void Tank::ResetPowerUpEffect()
{
	powerUpStart = 0;
	powerUp = NULL;
	isImmortal = false;
	fMaxVelocity = 10.f;
	fAccelerationMultiplicator = 1.f;
	SetHasSuperBullets(false);
	Turret->MarkSuperBulletsAsNotFired();
}
/**
Function which starts power up timer.
*/
std::clock_t Tank::GetPowerUpStart()
{
	return powerUpStart;
}

/**
Function which sets tank movement properties.
*/
void Tank::SetMovementProperties()
{
	if (UG::IsKeyDown(moveForwardKey))
	{
		fAccelleration += 3.f * fAccelerationMultiplicator;
		fDrag = 0.f;
	}
	if (UG::IsKeyDown(moveBackwardKey))
	{
		fAccelleration -= 2.f * fAccelerationMultiplicator;
		fDrag = 0.f;
	}
	if (!UG::IsKeyDown(moveBackwardKey) && !UG::IsKeyDown(moveForwardKey))
	{
		fDrag = 0.08f;
	}
}

/**
Function which changes tanks speed and moves them.

@param a_fDeltaTime The time in seconds it took to complete the last frame.
*/
void Tank::ChangeTanksSpeedAndMove(float a_deltaTime)
{
	if (fabsf(currentVelocity) > fMaxVelocity)
	{
		currentVelocity = currentVelocity / fabsf(currentVelocity) * fMaxVelocity;
	}
	if (fabsf(currentVelocity) > FLT_EPSILON)
	{
		movementVector = movementVector * (currentVelocity * a_deltaTime);
		movementVector = movementVector * 32.f; //why 32.f? 32 pixels is 1 meter.
		MoveSprite(movementVector);
	}
}

/**
Function updates current tank velocity.

@param a_fDeltaTime The time in seconds it took to complete the last frame.
*/
void Tank::UpdateCurrentVelocity(float a_fDeltaTime)
{
	currentVelocity = currentVelocity + fAccelleration * a_fDeltaTime;
	currentVelocity = currentVelocity - currentVelocity * fDrag;
}

/**
Function which allows us to rotate our tank by pressing the keys assigned to this action.
*/
void Tank::TankRotation()
{
	if (UG::IsKeyDown(moveLeftKey))
	{
		RotateZ((float)(0.5f * M_PI / 180.f));
	}
	if (UG::IsKeyDown(moveRightKey))
	{
		RotateZ((float)(-0.5f * M_PI / 180.f));
	}
}

/**
Function which allows us to shoot.
*/
void Tank::Shoot()
{
	if (!hasSuperBullets)
	{
		Turret->ShootStandardBullets();
	}
	else
	{
		Turret->ShootSuperBullets();
		//if all super bullets are shot then tank should shoot using standard bullets again
		if (Turret->GetLoadedSuperBullets() == 0)
		{
			ResetPowerUpEffect();
		}
	}
}

/**
Function which animates the Tank while moving, by changing its UV coordinates.
*/
void Tank::AnimateMovement()
{
	spriteIndex = (spriteIndex + 1) % 2;
	SetSpriteUVCoordinates(animationFrames.at(spriteIndex));
}

Tank::Tank(const char* a_fileName, int a_width, int a_height, Vector2 a_origin, std::vector<Vector4> a_animationFrames, int a_healthBarPosX, int a_healthBarPosY)
	:Sprite(a_fileName, a_width, a_height, a_origin, a_animationFrames.at(0)), Shape((float)(a_width), (float)(a_height))
{
	movementVector = Vector3::AXIS_Y;
	currentVelocity = 0.f;
	fDrag = 0.03f;
	fAccelleration = 0.f;
	fMaxVelocity = 10.f;
	health = new Health(100, a_healthBarPosX, a_healthBarPosY);
	isImmortal = false;
	fAccelerationMultiplicator = 1.f;
	hasSuperBullets = false;
	spriteIndex = 0;
	animationFrames = a_animationFrames;
}