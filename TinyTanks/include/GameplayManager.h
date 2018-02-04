#ifndef _GAMEPLAYMANAGER_H_
#define _GAMEPLAYMANAGER_H_

#include <vector>
#include "GameStates.h"
#include "Tank.h"
#include "PowerUpsFactory.h"
#include "MapManager.h"
#include "CollisionManager.h"
#include "ScoresManager.h"

class GameplayManager
{
public:
	GameplayManager(int a_iGameplayScreenWidth, int a_iGameplayScreenHeight, int a_iScreenHeight);

	/**
	Function inside which everything during game play phase is being handled.

	@param a_fDeltaTime The time in seconds it took to complete the last frame.
	@param fFrameTime Variable which helps in animation handling.
	@param fExplosionFrameTime Variable which helps in explosion animation handling.
	*/
	void HandleGameplay(float a_fDeltaTime, float& fFrameTime, float& fExplosionFrameTime);

	/**
	Function which creates and initalizes tanks.
	*/
	void CreateAndInitialiseTanks();

	/**
	Function which draws players hp images on HUD.
	*/
	void DrawPlayersHpImages();

	/**
	Function which undraws players hp images from HUD.
	*/
	void UndrawPlayersHpImages();

	/**
	Function which loads First Level
	*/
	void LoadLevel();

	/**
	Function which loads new level.
	*/
	void LoadNewLevel();

	/**
	Function which unloads the level, by destroying tanks and clearing power ups.
	*/
	void UnloadLevel();

	/**
	Function displays text on HUD.
	*/
	void DisplayHUDStrings();

	/**
	Function displays game over messages.
	*/
	void DisplayGameOver();

private:
	/**
	Function which creates first tank.
	*/
	void CreateFirstTank();

	/**
	Function which creates second tank.
	*/
	void CreateSecondTank();

	/**
	Function which assigns controls to first tank.
	*/
	void InitialiseFirstTankControls();

	/**
	Function which assigns controls to second tank.
	*/
	void InitialiseSecondTankControls();

	/**
	Function which unpins controls to from tank.
	*/
	void UnpinTankControls(Tank* a_pTank);

	/**
	Function which destroys tank sprites.
	*/
	void DestroyTanks();

	/**
	Function which destroys tank sprite.
	*/
	void DestroyTank(Tank* a_pTank);

	/**
	Function manages power up spawning system.
	*/
	void ManagePowerUpSpawn();

	/**
	Function which clears power ups from map, by undrawing and destroying sprites.
	*/
	void ClearPowerUps();


	int iGameplayScreenWidth;
	int iGameplayScreenHeight;
	int iScreenHeight;

	int iPreviousExplosionCounter;
	int iExplosionCounter;

	bool isScoreUpdated;

	Tank* pTank1;
	Tank* pTank2;
	std::vector<PowerUp*> powerUps;

	MapManager* mapManager;
	CollisionManager* collisionManager;
};

#endif
#pragma once
