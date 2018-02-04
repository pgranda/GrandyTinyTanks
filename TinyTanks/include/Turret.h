#ifndef _TURRET_H_
#define _TURRET_H_

#include "Bullet.h"
#include <iostream>
#include <vector>
#include <cstdio>
#include <ctime>

class Turret : public Sprite
{
public:
	Turret(const char* a_fileName, int a_width, int a_height, Vector2 a_origin, Vector4 a_UVCoords);

	short GetMoveTurretLeftKey();
	void SetMoveTurretLeftKey(short a_turretLeftKey);

	short GetMoveTurretRightKey();
	void SetMoveTurretRightKey(short a_turretRightKey);

	short GetFireKey();
	void SetFireKey(short a_fireKey);

	void TurretRotation();
	void ShootStandardBullets();
	void ShootSuperBullets();

	void UpdateTurret(float a_fDeltaTime);
	void UpdateBulletsOutermostVertices();
	void AnimateBulletsMovement();

	std::vector<Bullet*> GetStandardBullets();
	int GetLoadedStandardBullets();
	int GetLoadedSuperBullets();
	std::vector<Bullet*> GetSuperBullets();

	void MarkStandardBulletsAsNotFired();
	void MarkSuperBulletsAsNotFired();

private:
	short fireKey;
	short moveTurretLeftKey;
	short moveTurretRightKey;
	bool isShootingAvailable;

	std::clock_t start;

	std::vector<Bullet*> standardBullets;
	std::vector<Bullet*> superBullets;
};

#endif _TURRET_H_