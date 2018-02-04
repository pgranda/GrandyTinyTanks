#include "GameplayManager.h"

/**
Function inside which everything during game play phase is being handled.

@param a_fDeltaTime The time in seconds it took to complete the last frame.
@param fFrameTime Variable which helps in animation handling.
@param fExplosionFrameTime Variable which helps in explosion animation handling.
*/
void GameplayManager::HandleGameplay(float a_fDeltaTime, float& fFrameTime, float& fExplosionFrameTime)
{
	pTank1->PreviousM3PosRot = pTank1->m3PosRot;
	pTank2->PreviousM3PosRot = pTank2->m3PosRot;

	iPreviousExplosionCounter = iExplosionCounter;
	if (fExplosionFrameTime < 0.f)
	{
		iExplosionCounter++;
		fExplosionFrameTime = 0.075f;
	}

	double pTank1PowerUpDuration = (std::clock() - pTank1->GetPowerUpStart()) / (double)CLOCKS_PER_SEC;
	if (pTank1->GetPowerUpStart() != 0 && pTank1PowerUpDuration >= 5)
	{
		pTank1->ResetPowerUpEffect();
	}

	double pTank2PowerUpDuration = (std::clock() - pTank2->GetPowerUpStart()) / (double)CLOCKS_PER_SEC;
	if (pTank2->GetPowerUpStart() != 0 && pTank2PowerUpDuration >= 5)
	{
		pTank2->ResetPowerUpEffect();
	}

	if (pTank1->GetPowerUp() != NULL)
	{
		pTank1->GetPowerUp()->DisplayPowerUpInformation((float)(iGameplayScreenWidth), iScreenHeight, 0.15f);
	}
	if (pTank2->GetPowerUp() != NULL)
	{
		pTank2->GetPowerUp()->DisplayPowerUpInformation((float)(iGameplayScreenWidth), iScreenHeight, 0.755f);
	}

	pTank1->SetMovementVector(Vector3::AXIS_Y);
	pTank2->SetMovementVector(Vector3::AXIS_Y);

	pTank1->SetAccelleration(0.f);
	pTank2->SetAccelleration(0.f);

	pTank1->SetMovementProperties();
	pTank2->SetMovementProperties();

	pTank1->Shoot();
	pTank2->Shoot();

	pTank1->UpdateCurrentVelocity(a_fDeltaTime);
	pTank2->UpdateCurrentVelocity(a_fDeltaTime);

	pTank1->ChangeTanksSpeedAndMove(a_fDeltaTime);
	pTank2->ChangeTanksSpeedAndMove(a_fDeltaTime);

	pTank1->TankRotation();
	pTank2->TankRotation();

	pTank1->Turret->TurretRotation();
	pTank2->Turret->TurretRotation();

	pTank1->UpdateOutermostVertices(pTank1->m3PosRot);
	pTank2->UpdateOutermostVertices(pTank2->m3PosRot);

	pTank1->Turret->UpdateBulletsOutermostVertices();
	pTank2->Turret->UpdateBulletsOutermostVertices();

	collisionManager->GJKCollisionHandling(pTank1, pTank2, mapManager->GetObstacles(), powerUps);

	UG::ClearScreen();

	if (fFrameTime < 0.f)
	{
		fFrameTime = 0.2f;

		if (!(pTank1->m3PosRot == pTank1->PreviousM3PosRot))
		{
			pTank1->AnimateMovement();
		}
		if (!(pTank2->m3PosRot == pTank2->PreviousM3PosRot))
		{
			pTank2->AnimateMovement();
		}
	}
	if (iExplosionCounter != iPreviousExplosionCounter)
	{
		pTank1->Turret->AnimateBulletsMovement();
		pTank2->Turret->AnimateBulletsMovement();
	}

	pTank1->Update(a_fDeltaTime);
	pTank1->Turret->UpdateTurret(a_fDeltaTime);

	pTank2->Update(a_fDeltaTime);
	pTank2->Turret->UpdateTurret(a_fDeltaTime);

	ManagePowerUpSpawn();

	DisplayHUDStrings();
}

/**
Function which creates and initalizes tanks.
*/
void GameplayManager::CreateAndInitialiseTanks()
{
	CreateFirstTank();
	CreateSecondTank();
	InitialiseFirstTankControls();
	InitialiseSecondTankControls();
}

/**
Function which draws players hp images on HUD.
*/
void GameplayManager::DrawPlayersHpImages()
{
	pTank1->health->SetPlayerHPImage();
	pTank2->health->SetPlayerHPImage();
}

/**
Function which undraws players hp images from HUD.
*/
void GameplayManager::UndrawPlayersHpImages()
{
	pTank1->health->UndrawPlayerHpImages();
	pTank2->health->UndrawPlayerHpImages();
}

/**
Function which creates first tank.
*/
void GameplayManager::CreateFirstTank()
{
	std::vector<Vector4> animationFrames;
	animationFrames.push_back(Vector4(0.0f, 0.481f, 0.247f, 1.0f));
	animationFrames.push_back(Vector4(0.502f, 0.481f, 0.749f, 1.0f));

	//Create a sprite for our tank's base
	pTank1 = new Tank("./images/tanks.png", 64, 71, Vector2(0.5f, 0.5f), animationFrames, (int)(iGameplayScreenWidth * 0.13f), iScreenHeight - 34);
	pTank1->SetPosition(Vector2(iGameplayScreenWidth * 0.5f, iGameplayScreenHeight * 0.2f));
	pTank1->PreviousM3PosRot = pTank1->m3PosRot;
	pTank1->MarkForDraw();
	pTank1->SetLayer(2);

	//Create a sprite for our tank's turret
	pTank1->Turret = new Turret("./images/tanks.png", 38, 64, Vector2(0.5f, 0.29f), Vector4(0.0f, 0.0f, 0.143f, 0.459f)); //0.552
	pTank1->Turret->SetParent(pTank1);
	pTank1->Turret->MarkForDraw();
	pTank1->Turret->SetLayer(4);
}

/**
Function which creates second tank.
*/
void GameplayManager::CreateSecondTank()
{
	std::vector<Vector4> animationFrames;
	animationFrames.push_back(Vector4(0.251f, 0.481f, 0.498f, 1.0f));
	animationFrames.push_back(Vector4(0.753f, 0.481f, 1.0f, 1.0f));

	//Create a sprite for our tank's base
	pTank2 = new Tank("./images/tanks.png", 64, 71, Vector2(0.5f, 0.5f), animationFrames, (int)(iGameplayScreenWidth * 0.73f), iScreenHeight - 34);
	pTank2->SetPosition(Vector2(iGameplayScreenWidth * 0.5f, iGameplayScreenHeight * 0.8f));
	pTank2->RotateZ((float)(M_PI));
	pTank2->PreviousM3PosRot = pTank2->m3PosRot;
	pTank2->MarkForDraw();
	pTank2->SetLayer(2);

	//Create a sprite for our tank's turret
	pTank2->Turret = new Turret("./images/tanks.png", 38, 64, Vector2(0.5f, 0.29f), Vector4(0.251f, 0.0f, 0.39f, 0.459f));
	pTank2->Turret->SetParent(pTank2);
	pTank2->Turret->MarkForDraw();
	pTank2->Turret->SetLayer(4);
}

/**
Function which assigns controls to first tank.
*/
void GameplayManager::InitialiseFirstTankControls()
{
	pTank1->SetMoveForwardKey(UG::KEY_W);
	pTank1->SetMoveBackwardKey(UG::KEY_S);
	pTank1->SetMoveLeftKey(UG::KEY_A);
	pTank1->SetMoveRightKey(UG::KEY_D);
	pTank1->Turret->SetMoveTurretLeftKey(UG::KEY_Q);
	pTank1->Turret->SetMoveTurretRightKey(UG::KEY_E);
	pTank1->Turret->SetFireKey(UG::KEY_X);
}

/**
Function which assigns controls to second tank.
*/
void GameplayManager::InitialiseSecondTankControls()
{
	pTank2->SetMoveForwardKey(UG::KEY_KP_8);
	pTank2->SetMoveBackwardKey(UG::KEY_KP_5);
	pTank2->SetMoveLeftKey(UG::KEY_KP_4);
	pTank2->SetMoveRightKey(UG::KEY_KP_6);
	pTank2->Turret->SetMoveTurretLeftKey(UG::KEY_KP_7);
	pTank2->Turret->SetMoveTurretRightKey(UG::KEY_KP_9);
	pTank2->Turret->SetFireKey(UG::KEY_KP_2);
}

/**
Function which unpins controls to from tank.
*/
void GameplayManager::UnpinTankControls(Tank* a_pTank)
{
	a_pTank->SetMoveForwardKey(UG::KEY_UNKNOWN);
	a_pTank->SetMoveBackwardKey(UG::KEY_UNKNOWN);
	a_pTank->SetMoveLeftKey(UG::KEY_UNKNOWN);
	a_pTank->SetMoveRightKey(UG::KEY_UNKNOWN);
	a_pTank->Turret->SetMoveTurretLeftKey(UG::KEY_UNKNOWN);
	a_pTank->Turret->SetMoveTurretRightKey(UG::KEY_UNKNOWN);
	a_pTank->Turret->SetFireKey(UG::KEY_UNKNOWN);
}

/**
Function which destroys tank sprites.
*/
void GameplayManager::DestroyTanks()
{
	DestroyTank(pTank1);
	DestroyTank(pTank2);
}

/**
Function which destroys tank sprite.
*/
void GameplayManager::DestroyTank(Tank* a_pTank)
{
	a_pTank->StopDrawing();
	a_pTank->Turret->StopDrawing();
	a_pTank->DestroySprite();
	a_pTank->Turret->DestroySprite();
	a_pTank->health->UndrawPlayerHpImages();
	std::vector<Bullet*> standardBullets = a_pTank->Turret->GetStandardBullets();
	for (int i = 0; i < standardBullets.size(); i++)
	{
		standardBullets.at(i)->StopDrawing();
		standardBullets.at(i)->DestroySprite();
	}
	std::vector<Bullet*> superBullets = a_pTank->Turret->GetSuperBullets();
	for (int i = 0; i < superBullets.size(); i++)
	{
		superBullets.at(i)->StopDrawing();
		superBullets.at(i)->DestroySprite();
	}
}

/**
Function manages power up spawning system.
*/
void GameplayManager::ManagePowerUpSpawn()
{
	if (powerUps.size() >= 10)
	{
		return;
	}
	int random = rand() % 350;
	if (random == 0)
	{
		int randomPowerUpId = rand() % 4;
		int powerUpWidth = rand() % iGameplayScreenWidth;
		int powerUpHeight = rand() % iGameplayScreenHeight;
		PowerUp* powerUp = PowerUpsFactory::GetPowerUp(randomPowerUpId, (float)(powerUpWidth), (float)(powerUpHeight));
		std::vector<Shape*> allObstacles;

		while (collisionManager->CheckIfPositionOccupied(powerUp, pTank1, pTank2, mapManager->GetObstacles(), powerUps))
		{
			powerUp->StopDrawing();
			powerUp->DestroySprite();
			powerUpWidth = rand() % iGameplayScreenWidth;
			powerUpHeight = rand() % iGameplayScreenHeight;
			powerUp = PowerUpsFactory::GetPowerUp(randomPowerUpId, (float)(powerUpWidth), (float)(powerUpHeight));
		}
		powerUps.push_back(powerUp);
	}
}

/**
Function which clears power ups from map, by undrawing and destroying sprites.
*/
void GameplayManager::ClearPowerUps()
{
	for (int i = 0; i < powerUps.size(); i++)
	{
		powerUps.at(i)->StopDrawing();
		powerUps.at(i)->DestroySprite();
	}
	powerUps.clear();
}

/**
Function which loads First Level
*/
void GameplayManager::LoadLevel()
{
	CreateAndInitialiseTanks();
	mapManager->DrawLevelMap((float)(iGameplayScreenWidth), (float)(iGameplayScreenHeight));
	DrawPlayersHpImages();
}

/**
Function which loads new level.
*/
void GameplayManager::LoadNewLevel()
{
	if (ScoresManager::getInstance().GetIsGameOver())
	{
		return;
	}
	CreateAndInitialiseTanks();
	mapManager->SetLevel(mapManager->GetLevel() + 1);
	mapManager->DrawLevelMap((float)(iGameplayScreenWidth), (float)(iGameplayScreenHeight));
	DrawPlayersHpImages();
}

/**
Function which unloads the level, by destroying tanks and clearing power ups.
*/
void GameplayManager::UnloadLevel()
{
	DestroyTanks();
	ClearPowerUps();

	if (ScoresManager::getInstance().GetPlayer1Score() == 3 || ScoresManager::getInstance().GetPlayer2Score() == 3)
	{
		mapManager->UndrawMap();
		ScoresManager::getInstance().SetIsGameOver(true);
	}
}

/**
Function displays text on HUD.
*/
void GameplayManager::DisplayHUDStrings()
{
	std::ostringstream player1;
	std::ostringstream player2;

	std::ostringstream player1StandardBullets;
	std::ostringstream player2StandardBullets;

	std::ostringstream player1SuperBullets;
	std::ostringstream player2SuperBullets;

	std::ostringstream player1Score;
	std::ostringstream player2Score;

	UG::SetFont("./fonts/invaders.fnt");

	player1 << "Player 1";
	player2 << "Player 2";

	player1Score << ScoresManager::getInstance().GetPlayer1Score();
	player2Score << ScoresManager::getInstance().GetPlayer2Score();


	if (pTank1->GetHasSuperBullets() == false)
	{
		player1StandardBullets << "Ammo: " << pTank1->Turret->GetLoadedStandardBullets() << " / 10";
		UG::DrawString(player1StandardBullets.str().c_str(), (int)(iGameplayScreenWidth * 0.2f), iScreenHeight - 24, 0.7f);
	}
	else
	{
		player1SuperBullets << "Ammo: " << pTank1->Turret->GetLoadedSuperBullets() << " / 5";
		UG::DrawString(player1SuperBullets.str().c_str(), (int)(iGameplayScreenWidth * 0.2f), iScreenHeight - 24, 0.7f);
	}

	if (pTank2->GetHasSuperBullets() == false)
	{
		player2StandardBullets << "Ammo: " << pTank2->Turret->GetLoadedStandardBullets() << " / 10";
		UG::DrawString(player2StandardBullets.str().c_str(), (int)(iGameplayScreenWidth * 0.8f), iScreenHeight - 24, 0.7f);
	}
	else
	{
		player2SuperBullets << "Ammo: " << pTank2->Turret->GetLoadedSuperBullets() << " / 5";
		UG::DrawString(player2SuperBullets.str().c_str(), (int)(iGameplayScreenWidth * 0.8f), iScreenHeight - 24, 0.7f);
	}


	UG::DrawString(player1.str().c_str(), (int)(iGameplayScreenWidth * 0.1f), iScreenHeight - 2, 0.7f);
	UG::DrawString(player2.str().c_str(), (int)(iGameplayScreenWidth * 0.7f), iScreenHeight - 2, 0.7f);

	UG::DrawString(player1Score.str().c_str(), (int)(iGameplayScreenWidth * 0.4f), iScreenHeight - 2, 2.f);
	UG::DrawString(" : ", (int)(iGameplayScreenWidth * 0.5f), iScreenHeight - 2, 2.f);
	UG::DrawString(player2Score.str().c_str(), (int)(iGameplayScreenWidth * 0.6f), iScreenHeight - 2, 2.f);

	DisplayGameOver();
}

/**
Function displays game over messages.
*/
void GameplayManager::DisplayGameOver()
{
	std::ostringstream winner;
	if (pTank1->GetHp() == 0)
	{
		winner << "Player  2  wins!";
		if (!isScoreUpdated)
		{
			ScoresManager::getInstance().SetPlayer2Score(ScoresManager::getInstance().GetPlayer2Score() + 1);
			isScoreUpdated = true;
		}
	}
	else if (pTank2->GetHp() == 0)
	{
		winner << "Player  1  wins!";
		if (!isScoreUpdated)
		{
			ScoresManager::getInstance().SetPlayer1Score(ScoresManager::getInstance().GetPlayer1Score() + 1);
			isScoreUpdated = true;
		}
	}
	else
	{
		return;
	}

	UG::DrawString(winner.str().c_str(), (int)(iGameplayScreenWidth * 0.35f), (int)(iGameplayScreenHeight * 0.525f), 2.0f, UG::SColour(255, 0, 0, 255));
	UG::DrawString("PRESS ENTER TO CONTINUE", (int)(iGameplayScreenWidth * 0.37f), (int)(iGameplayScreenHeight * 0.35f), 1.0f, UG::SColour(0, 0, 0, 255));
	UnpinTankControls(pTank1);
	UnpinTankControls(pTank2);

	if (UG::IsKeyDown(UG::KEY_ENTER))
	{
		isScoreUpdated = false;
		UnloadLevel();
		LoadNewLevel();
	}
}

GameplayManager::GameplayManager(int a_iGameplayScreenWidth, int a_iGameplayScreenHeight, int a_iScreenHeight)
{
	iGameplayScreenWidth = a_iGameplayScreenWidth;
	iGameplayScreenHeight = a_iGameplayScreenHeight;
	iScreenHeight = a_iScreenHeight;

	iPreviousExplosionCounter = 0;
	iExplosionCounter = 0;

	isScoreUpdated = false;

	mapManager = new MapManager(1);
	collisionManager = new CollisionManager();
}