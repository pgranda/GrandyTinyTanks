#include "Turret.h"
#define _USE_MATH_DEFINES
#include <math.h>

/**
Function which rotates the tanks turret after pressing move turret key.
*/
void Turret::TurretRotation()
{
	//Turret Rotation
	if (UG::IsKeyDown(moveTurretLeftKey))
	{
		RotateZ((float)(0.5f * M_PI / 180.f));
	}

	if (UG::IsKeyDown(moveTurretRightKey))
	{
		RotateZ((float)(-0.5f * M_PI / 180.f));
	}
}

/**
Function which handles standard bullets shooting, reloading and movement.
*/
void Turret::ShootStandardBullets()
{
	if (GetLoadedStandardBullets() == 0)
	{
		double duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;

		if (duration >= 3)
		{
			MarkStandardBulletsAsNotFired();
		}
	}

	if (!UG::IsKeyDown(fireKey))
	{
		isShootingAvailable = true;
	}

	//move already shot bullets
	for (int i = 0; i < standardBullets.size(); i++)
	{
		if (standardBullets[i]->GetIsDrawing())
		{
			standardBullets[i]->Move();
		}
	}
	for (int i = 0; i < superBullets.size(); i++)
	{
		if (superBullets[i]->GetIsDrawing())
		{
			superBullets[i]->Move();
		}
	}

	if (UG::IsKeyDown(fireKey) && isShootingAvailable)
	{
		for (int i = 0; i < standardBullets.size(); i++)
		{
			if (!standardBullets[i]->GetIsShot())
			{
				Matrix3 worldTx;
				GetWorldTransform(worldTx);
				Vector3 worldPos;
				worldTx.GetRow(2, worldPos);
				Vector3 forwardVec;
				worldTx.GetRow(1, forwardVec);

				standardBullets[i]->Shoot(Vector2(worldPos.GetX() + forwardVec.GetX()*(38.f + 38.f*0.21f),
					worldPos.GetY() + forwardVec.GetY()*(64.f - 64.f*0.29f)), forwardVec);
				//standardBullets[i]->Shoot(Vector2(worldPos.GetX(), worldPos.GetY()), forwardVec);

				isShootingAvailable = false;

				if (i == standardBullets.size() - 1)
				{
					start = std::clock();
				}

				return;
			}
		}
	}
}

/**
Function which handles super bullets shooting, reloading and movement.
*/
void Turret::ShootSuperBullets()
{
	if (!UG::IsKeyDown(fireKey))
	{
		isShootingAvailable = true;
	}

	//move already shot bullets
	for (int i = 0; i < standardBullets.size(); i++)
	{
		if (standardBullets[i]->GetIsDrawing())
		{
			standardBullets[i]->Move();
		}
	}
	for (int i = 0; i < superBullets.size(); i++)
	{
		if (superBullets[i]->GetIsDrawing())
		{
			superBullets[i]->Move();
		}
	}

	if (UG::IsKeyDown(fireKey) && isShootingAvailable)
	{
		for (int i = 0; i < superBullets.size(); i++)
		{
			if (!superBullets[i]->GetIsShot())
			{
				Matrix3 worldTx;
				GetWorldTransform(worldTx);
				Vector3 worldPos;
				worldTx.GetRow(2, worldPos);
				Vector3 forwardVec;
				worldTx.GetRow(1, forwardVec);

				superBullets[i]->Shoot(Vector2(worldPos.GetX() + forwardVec.GetX()*(38.f + 38.f*0.21f),
					worldPos.GetY() + forwardVec.GetY()*(64.f - 64.f*0.29f)), forwardVec);
				//superBullets[i]->Shoot(Vector2(worldPos.GetX(), worldPos.GetY()), forwardVec);

				isShootingAvailable = false;

				return;
			}
		}
	}
}

/**
Setter which sets standard bullets as not fired.
*/
void Turret::MarkStandardBulletsAsNotFired()
{
	for (int i = 0; i < standardBullets.size(); i++)
	{
		standardBullets[i]->SetIsShot(false);
	}
}

/**
Setter which sets super bullets as not fired.
*/
void Turret::MarkSuperBulletsAsNotFired()
{
	for (int i = 0; i < superBullets.size(); i++)
	{
		superBullets[i]->SetIsShot(false);
	}
}

/**
Getter which gets the move turret left key.

@return moveTurretLeftKey Returns move turret left key value.
*/
short Turret::GetMoveTurretLeftKey()
{
	return moveTurretLeftKey;
}

/**
Getter which gets the move turret right key.

@return moveTurretRightKey Returns move turret right key value.
*/
short Turret::GetMoveTurretRightKey()
{
	return moveTurretRightKey;
}

/**
Getter which gets the fire key.

@return fireKey Returns fire key value.
*/
short Turret::GetFireKey()
{
	return fireKey;
}

/**
Setter which sets the move turret left key.

@param a_turretLeftKey Key Value for move turret left action.
*/
void Turret::SetMoveTurretLeftKey(short a_turretLeftKey)
{
	moveTurretLeftKey = a_turretLeftKey;
}

/**
Setter which sets the move turret right key.

@param a_turretRightKey Key Value for move turret right action.
*/
void Turret::SetMoveTurretRightKey(short a_turretRightKey)
{
	moveTurretRightKey = a_turretRightKey;
}

/**
Setter which sets the fire key.

@param a_fireKey Key Value for fire action.
*/
void Turret::SetFireKey(short a_fireKey)
{
	fireKey = a_fireKey;
}

/**
Function which updates turret and bullets.
*/
void Turret::UpdateTurret(float a_fDeltaTime)
{
	Update(a_fDeltaTime);
	for (int i = 0; i < standardBullets.size(); i++)
	{
		standardBullets[i]->UpdateBullet(a_fDeltaTime);
	}
	for (int i = 0; i < superBullets.size(); i++)
	{
		superBullets[i]->UpdateBullet(a_fDeltaTime);
	}
}

/**
Function updates bullets outermost vertices.
*/
void Turret::UpdateBulletsOutermostVertices()
{
	for (int i = 0; i < standardBullets.size(); i++)
	{
		if (standardBullets[i]->GetIsDrawing())
		{
			standardBullets[i]->UpdateOutermostVertices(standardBullets[i]->m3PosRot);
		}
	}
	for (int i = 0; i < superBullets.size(); i++)
	{
		if (superBullets[i]->GetIsDrawing())
		{
			superBullets[i]->UpdateOutermostVertices(superBullets[i]->m3PosRot);
		}
	}
}

/**
Function which iterates through vector of bullets and animates their explosion.
*/
void Turret::AnimateBulletsMovement()
{
	for (int i = 0; i < standardBullets.size(); i++)
	{
		standardBullets[i]->AnimateExplosion();
	}
	for (int i = 0; i < superBullets.size(); i++)
	{
		superBullets[i]->AnimateExplosion();
	}
}

/**
Getter that gets the vector container of bullet class pointers of standard bullet objects.

@return superBullets vector container of bullet class pointers of standard bullet objects.
*/
std::vector<Bullet*> Turret::GetStandardBullets()
{
	return standardBullets;
}

/**
Getter that gets number of loaded standard bullets in the magazine.

@return counter number of bullets.
*/
int Turret::GetLoadedStandardBullets()
{
	int counter = 0;
	for (int i = 0; i < standardBullets.size(); i++)
	{
		if (!standardBullets[i]->GetIsShot())
		{
			counter++;
		}
	}
	return counter;
}

/**
Getter that gets number of loaded super bullets in the magazine.

@return counter number of bullets.
*/
int Turret::GetLoadedSuperBullets()
{
	int counter = 0;
	for (int i = 0; i < superBullets.size(); i++)
	{
		if (!superBullets[i]->GetIsShot())
		{
			counter++;
		}
	}
	return counter;
}

/**
Getter that gets the vector container of bullet class pointers of super bullet objects.

@return superBullets vector container of bullet class pointers of super bullet objects.
*/
std::vector<Bullet*> Turret::GetSuperBullets()
{
	return superBullets;
}

Turret::Turret(const char* a_fileName, int a_width, int a_height, Vector2 a_origin, Vector4 a_UVCoords)
	:Sprite(a_fileName, a_width, a_height, a_origin, a_UVCoords)
{
	std::vector<Vector4> animationFrames;
	animationFrames.push_back(Vector4(0.f, 0.f, 0.535f, 1.f));
	animationFrames.push_back(Vector4(0.535f, 0.f, 0.611f, 0.14f));
	animationFrames.push_back(Vector4(0.615f, 0.f, 0.724f, 0.242f));
	animationFrames.push_back(Vector4(0.728f, 0.f, 0.862f, 0.25f));
	animationFrames.push_back(Vector4(0.866f, 0.f, 1.f, 0.1875f));
	animationFrames.push_back(Vector4(0.866f, 0.f, 1.f, 0.1875f));

	for (int i = 0; i < 10; ++i)
	{
		standardBullets.push_back(new Bullet("./images/bullet1.png", 10, 10, Vector2(0.5f, 0.29f), animationFrames, 20));
	}

	for (int i = 0; i < 5; ++i)
	{
		superBullets.push_back(new Bullet("./images/bullet2.png", 10, 10, Vector2(0.5f, 0.29f), animationFrames, 40));
	}

	isShootingAvailable = true;
}