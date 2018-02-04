#ifndef _TANK_H_
#define _TANK_H_

#include <iostream>
#include "Health.h"
#include "Shape.h"

class PowerUp;
class Tank : public Sprite, public Shape
{
public:
	Tank(const char* a_fileName, int a_width, int a_height, Vector2 a_origin, std::vector<Vector4> a_animationFrames, int a_healthBarPosX, int a_healthBarPosY);

	short GetMoveLeftKey();
	void SetMoveLeftKey(short a_leftKey);

	short GetMoveRightKey();
	void SetMoveRightKey(short a_rightKey);

	short GetMoveForwardKey();
	void SetMoveForwardKey(short a_forwardKey);

	short GetMoveBackwardKey();
	void SetMoveBackwardKey(short a_backwardKey);

	int GetHp();
	void SetHp(int a_hp);

	Vector3 GetMovementVector();
	void SetMovementVector(Vector3 a_movementVector);

	float GetCurrentVelocity();
	void SetCurrentVelocity(float a_currentVelocity);

	PowerUp* GetPowerUp();
	void SetPowerUp(PowerUp* a_powerUp);

	bool GetIsImmortal();
	void SetIsImmortal(bool a_isImmortal);

	bool GetHasSuperBullets();
	void SetHasSuperBullets(bool a_hasSuperBullets);

	void SetMaxVelocity(float a_fMaxVelocity);
	float GetMaxVelocity();

	void SetAccelerationMultiplicator(float a_fAccelerationMultiplicator);
	float GetAccelerationMultiplicator();

	void ResetPowerUpEffect();
	std::clock_t GetPowerUpStart();

	void SetMovementProperties();
	void TankRotation();

	void SetAccelleration(float a_fAccelleration);
	void ChangeTanksSpeedAndMove(float a_deltaTime);
	void UpdateCurrentVelocity(float a_fDeltaTime);
	void AnimateMovement();
	void Shoot();

	Turret* Turret;
	Matrix3 PreviousM3PosRot;
	Health* health;

protected:

	short moveLeftKey;
	short moveRightKey;
	short moveForwardKey;
	short moveBackwardKey;
	float fAccelerationMultiplicator;
	Vector3 movementVector;
	float currentVelocity;
	float fAccelleration;
	float fDrag;
	float fMaxVelocity;

	bool isImmortal;
	bool hasSuperBullets;
	PowerUp* powerUp;
	std::clock_t powerUpStart;
	int spriteIndex;
	std::vector<Vector4> animationFrames;
};

#endif