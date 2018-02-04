#include "CollisionManager.h"

/**
Handles tanks, obstacles and power ups collision, determines the behaviour when colliding.

@param a_pTank1 Pointer to the Tank class object.
@param a_pTank2 Pointer to the Tank class object.
@param a_obstacles Vector containing pointers to Obstacle class objects.
@param a_pTank1 Vector containing pointers to PowerUp class objects.
*/
void CollisionManager::GJKCollisionHandling(Tank* a_pTank1, Tank* a_pTank2, std::vector<Obstacle*> a_obstacles, std::vector<PowerUp*>& a_powerUps)
{
	bool collision = gjk.DetectCollision(a_pTank1, a_pTank2);

	if (collision)
	{
		a_pTank1->m3PosRot = a_pTank1->PreviousM3PosRot;
		a_pTank2->m3PosRot = a_pTank2->PreviousM3PosRot;
	}

	bool isTank2Damaged = GJKBulletsVersusTankCollisionHandling(a_pTank1, a_pTank2);
	if (isTank2Damaged)
	{
		a_pTank2->health->SetPlayerHPImage();
	}
	for (int i = 0; i < a_obstacles.size(); i++)
	{
		GJKBulletsCollisionHandling(a_pTank1, a_obstacles.at(i));
	}

	bool isTank1Damaged = GJKBulletsVersusTankCollisionHandling(a_pTank2, a_pTank1);
	if (isTank1Damaged)
	{
		a_pTank1->health->SetPlayerHPImage();
	}
	for (int i = 0; i < a_obstacles.size(); i++)
	{
		GJKBulletsCollisionHandling(a_pTank2, a_obstacles.at(i));
	}

	for (int i = 0; i < a_powerUps.size(); i++)
	{
		if (gjk.DetectCollision(a_pTank1, a_powerUps.at(i)))
		{
			a_pTank1->SetPowerUp(a_powerUps.at(i));

			if (dynamic_cast<HealthPowerUp*>(a_powerUps.at(i)) != NULL)
			{
				a_pTank1->health->SetPlayerHPImage();
			}
			a_powerUps.at(i)->StopDrawing();
			a_powerUps.at(i)->DestroySprite();
			a_powerUps.erase(a_powerUps.begin() + i);
		}
	}

	bool obstacleCollision = false;
	for (int i = 0; i < a_obstacles.size(); i++)
	{
		obstacleCollision |= gjk.DetectCollision(a_pTank1, a_obstacles.at(i));
	}

	if (obstacleCollision)
	{
		a_pTank1->m3PosRot = a_pTank1->PreviousM3PosRot;
	}

	for (int i = 0; i < a_powerUps.size(); i++)
	{
		if (gjk.DetectCollision(a_pTank2, a_powerUps.at(i)))
		{
			a_pTank2->SetPowerUp(a_powerUps.at(i));

			if (dynamic_cast<HealthPowerUp*>(a_powerUps.at(i)) != NULL)
			{
				a_pTank2->health->SetPlayerHPImage();
			}
			a_powerUps.at(i)->StopDrawing();
			a_powerUps.at(i)->DestroySprite();
			a_powerUps.erase(a_powerUps.begin() + i);
		}
	}

	obstacleCollision = false;
	for (int i = 0; i < a_obstacles.size(); i++)
	{
		obstacleCollision |= gjk.DetectCollision(a_pTank2, a_obstacles.at(i));
	}
	if (obstacleCollision)
	{
		a_pTank2->m3PosRot = a_pTank2->PreviousM3PosRot;
	}
}

/**
Checks if position is occupied and determines if Power Up can be spawned there.

@param a_shape Pointer to the Shape class object.
@param a_pTank1 Pointer to the Tank class object.
@param a_pTank2 Pointer to the Tank class object.
@param a_obstacles Vector containing pointers to Obstacle class objects.
@param a_pTank1 Vector containing pointers to PowerUp class objects.
@return obstacleCollision Returns flag saying if the position is occupied or not.
*/
bool CollisionManager::CheckIfPositionOccupied(Shape* a_shape, Tank* a_pTank1, Tank* a_pTank2, std::vector<Obstacle*> a_obstacles, std::vector<PowerUp*>& a_powerUps)
{
	bool obstacleCollision = false;
	obstacleCollision |= gjk.DetectCollision(a_shape, a_pTank1);
	obstacleCollision |= gjk.DetectCollision(a_shape, a_pTank2);

	for (int i = 0; i < a_obstacles.size(); i++)
	{
		obstacleCollision |= gjk.DetectCollision(a_shape, a_obstacles.at(i));
	}

	for (int i = 0; i < a_powerUps.size(); i++)
	{
		obstacleCollision |= gjk.DetectCollision(a_shape, a_powerUps.at(i));
	}

	return obstacleCollision;
}

/**
Handles the behaviour of bullets colliding with tank.

@param a_ShootingTank Pointer to the Tank class object that shot the bullet.
@param a_TargetTank Pointer to the Tank class object that the bullet collided with.
@return collision Returns flag saying if the tank should receive damage.
*/
bool CollisionManager::GJKBulletsVersusTankCollisionHandling(Tank* a_ShootingTank, Tank* a_TargetTank)
{
	bool collision = false;
	int finalDamage = 0;
	std::vector<Bullet*> standardBullets = a_ShootingTank->Turret->GetStandardBullets();
	std::vector<Bullet*> superBullets = a_ShootingTank->Turret->GetSuperBullets();
	for (int i = 0; i < standardBullets.size(); i++)
	{
		if (!standardBullets[i]->GetIsDrawing())
		{
			continue;
		}
		if (gjk.DetectCollision(standardBullets[i], a_TargetTank))
		{
			collision = true;
			finalDamage += standardBullets[i]->GetDamage();
			standardBullets[i]->MarkAsExploding();
		}
	}
	for (int i = 0; i < superBullets.size(); i++)
	{
		if (!superBullets[i]->GetIsDrawing())
		{
			continue;
		}
		if (gjk.DetectCollision(superBullets[i], a_TargetTank))
		{
			collision = true;
			finalDamage += superBullets[i]->GetDamage();
			superBullets[i]->MarkAsExploding();
		}
	}

	if (a_TargetTank->GetIsImmortal())
	{
		return false;
	}

	a_TargetTank->SetHp(a_TargetTank->GetHp() - finalDamage);

	return collision;
}

/**
Handles the behaviour of bullets colliding obstacle

@param a_ShootingTank Pointer to the Tank class object that shot the bullet.
@param a_TargetShape Pointer to the Shape class object that the bullet collided with.
@return collision Returns flag saying if the shape has been hit and the bullet should explode.
*/
bool CollisionManager::GJKBulletsCollisionHandling(Tank* a_ShootingTank, Shape* a_TargetShape)
{
	bool collision = false;
	std::vector<Bullet*> standardBullets = a_ShootingTank->Turret->GetStandardBullets();
	std::vector<Bullet*> superBullets = a_ShootingTank->Turret->GetSuperBullets();
	for (int i = 0; i < standardBullets.size(); i++)
	{
		if (!standardBullets[i]->GetIsDrawing())
		{
			continue;
		}
		if (gjk.DetectCollision(standardBullets[i], a_TargetShape))
		{
			collision = true;
			standardBullets[i]->MarkAsExploding();
		}
	}
	for (int i = 0; i < superBullets.size(); i++)
	{
		if (!superBullets[i]->GetIsDrawing())
		{
			continue;
		}
		if (gjk.DetectCollision(superBullets[i], a_TargetShape))
		{
			collision = true;
			superBullets[i]->MarkAsExploding();
		}
	}
	return collision;
}


CollisionManager::CollisionManager()
{

}