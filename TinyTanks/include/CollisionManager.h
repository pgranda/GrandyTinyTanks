#ifndef _COLLISIONMANAGER_H_
#define _COLLISIONMANAGER_H_

#include "PowerUpsFactory.h"

class CollisionManager
{
public:
	CollisionManager();
	/**
	Handles tanks, obstacles and power ups collision, determines the behaviour when colliding.

	@param a_pTank1 Pointer to the Tank class object.
	@param a_pTank2 Pointer to the Tank class object.
	@param a_obstacles Vector containing pointers to Obstacle class objects.
	@param a_pTank1 Vector containing pointers to PowerUp class objects.
	*/
	void GJKCollisionHandling(Tank* a_pTank1, Tank* a_pTank2, std::vector<Obstacle*> a_obstacles, std::vector<PowerUp*>& a_powerUps);
	/**
	Checks if position is occupied and determines if Power Up can be spawned there.

	@param a_shape Pointer to the Shape class object.
	@param a_pTank1 Pointer to the Tank class object.
	@param a_pTank2 Pointer to the Tank class object.
	@param a_obstacles Vector containing pointers to Obstacle class objects.
	@param a_pTank1 Vector containing pointers to PowerUp class objects.
	@return obstacleCollision Returns flag saying if the position is occupied or not.
	*/
	bool CheckIfPositionOccupied(Shape* a_shape, Tank* a_pTank1, Tank* a_pTank2, std::vector<Obstacle*> a_obstacles, std::vector<PowerUp*>& a_powerUps);

private:
	/**
	Handles the behaviour of bullets colliding with tank.

	@param a_ShootingTank Pointer to the Tank class object that shot the bullet.
	@param a_TargetTank Pointer to the Tank class object that the bullet collided with.
	@return collision Returns flag saying if the tank should receive damage.
	*/
	bool GJKBulletsVersusTankCollisionHandling(Tank* a_ShootingTank, Tank* a_TargetTank);
	/**
	Handles the behaviour of bullets colliding obstacle

	@param a_ShootingTank Pointer to the Tank class object that shot the bullet.
	@param a_TargetShape Pointer to the Shape class object that the bullet collided with.
	@return collision Returns flag saying if the shape has been hit and the bullet should explode.
	*/
	bool GJKBulletsCollisionHandling(Tank* a_ShootingTank, Shape* a_TargetShape);

	GJK gjk;
};

#endif
#pragma once
