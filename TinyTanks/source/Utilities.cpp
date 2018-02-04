#include "Utilities.h"

/**
Function which initializes all the values needed in later game loop.
*/
void Utilities::InitialiseScreenProperties()
{
	UG::GetScreenSize(fGameplayScreenWidth, iScreenHeight);
	fGameplayScreenHeight = iScreenHeight - 50;

	fNewGameOptionY = fGameplayScreenHeight * 0.45f;
	fQuitOptionY = fGameplayScreenHeight * 0.35f;

	UG::SetBackgroundColor(UG::SColour(0x00, 0x00, 0x00, 0xFF));
	UG::AddFont("./fonts/invaders.fnt");
}

/**
Function which initializes and creates the menu indicator.
*/
void Utilities::MenuIndicator()
{
	fIndicatorX = fGameplayScreenWidth * 0.32f;
	fIndicatorY = fNewGameOptionY;
	iIndicatorID = UG::CreateSprite("./images/tank.png", 62, 80, true);
}

/**
Function which displays game logo in main menu.
*/
void Utilities::DisplayLogo()
{
	iLogoID = UG::CreateSprite("./images/grandytinytankslogo2.png", 640.f, 200.f, true);
	UG::MoveSprite(iLogoID, fGameplayScreenWidth * 0.5f, fGameplayScreenHeight * 0.75f);
	UG::DrawSprite(iLogoID);
}

/**
Function which displays controls in start game state.
*/
void Utilities::DisplayControls()
{
	iControlsID = UG::CreateSprite("./images/Controls.png", 800.f, 600.f, true);
	UG::MoveSprite(iControlsID, fGameplayScreenWidth * 0.5f, fGameplayScreenHeight * 0.65f);
	UG::DrawSprite(iControlsID);
}

/**
Function which displays menu options.
*/
void Utilities::DisplayMenu()
{
	iNewGameID = UG::CreateSprite("./images/newgame.png", 200, 50, true);
	iQuitID = UG::CreateSprite("./images/quit.png", 200, 50, true);

	UG::MoveSprite(iNewGameID, fGameplayScreenWidth * 0.5f, fGameplayScreenHeight * 0.45f);
	UG::MoveSprite(iQuitID, fGameplayScreenWidth * 0.5f, fGameplayScreenHeight * 0.35f);

	UG::DrawSprite(iNewGameID);
	UG::DrawSprite(iQuitID);
}

/**
Function which stops drawing menu options, logo and indicator.
*/
void Utilities::StopDisplayingMenu()
{
	UG::StopDrawingSprite(iIndicatorID);
	UG::StopDrawingSprite(iLogoID);
	UG::StopDrawingSprite(iNewGameID);
	UG::StopDrawingSprite(iQuitID);
}

/**
Function which handles menu behaviour.
*/
void Utilities::HandleMenu()
{
	UG::MoveSprite(iIndicatorID, fIndicatorX, fIndicatorY);

	if (UG::IsKeyDown(UG::KEY_DOWN))
	{
		if (iMenuKeyCounter > 8)
		{
			if (fIndicatorY == fQuitOptionY)
			{
				return;
			}
			fIndicatorY -= fGameplayScreenHeight * 0.1f;
			iMenuKeyCounter = 0;
		}
		iMenuKeyCounter++;
	}
	else if (UG::IsKeyDown(UG::KEY_UP))
	{
		if (iMenuKeyCounter > 8)
		{
			if (fIndicatorY == fNewGameOptionY)
			{
				return;
			}
			fIndicatorY += fGameplayScreenHeight * 0.1f;

			iMenuKeyCounter = 0;
		}
		iMenuKeyCounter++;
	}

	UG::MoveSprite(iIndicatorID, fIndicatorX, fIndicatorY);

	if (UG::IsKeyDown(UG::KEY_ENTER))
	{
		if (fIndicatorY == fNewGameOptionY)
		{
			g_currentState = START;
			StopDisplayingMenu();
			DisplayControls();
		}
		else if (fIndicatorY == fQuitOptionY)
		{
			g_currentState = QUIT;
		}
	}
}

/**
Function which displays Splash and handles the behaviour.
*/
void Utilities::HandleSplash()
{
	UG::DrawString("By Pawel Granda", (int)(fGameplayScreenWidth * 0.41), (int)(fGameplayScreenHeight * 0.45), 1.0f);
	UG::DrawString("PRESS G TO CONTINUE", (int)(fGameplayScreenWidth * 0.365), (int)(fGameplayScreenHeight * 0.20), 1.0f);
	if (UG::IsKeyDown(UG::KEY_G))
	{
		g_currentState = MENU;
		DisplayMenu();
		UG::DrawSprite(iIndicatorID);
	}
}

/**
Function which handles the start game state behaviour.
*/
void Utilities::HandleStart()
{
	UG::DrawString("PRESS P TO CONTINUE", (int)(fGameplayScreenWidth * 0.365), (int)(fGameplayScreenHeight * 0.20), 1.0f);
	if (UG::IsKeyDown(UG::KEY_P))
	{
		UG::StopDrawingSprite(iControlsID);
		g_currentState = GAMEPLAY;

		gameplayManager->LoadLevel();
	}
}

/**
Function which handles game play state behaviour.
*/
void Utilities::HandleGameplay()
{
	gameplayManager->HandleGameplay(g_fDeltaTime, fFrameTime, fExplosionFrameTime);
	if (ScoresManager::getInstance().GetIsGameOver() == true)
	{
		g_currentState = GAMEOVER;
	}
}

/**
Function which handles game over state behaviour.
*/
void Utilities::HandleGameover()
{
	std::ostringstream winnerLine1;
	std::ostringstream winnerLine2;
	int player1Points = ScoresManager::getInstance().GetPlayer1Score();
	int player2Points = ScoresManager::getInstance().GetPlayer2Score();

	iLogoID = UG::CreateSprite("./images/grandytinytankslogo2.png", 640.f, 200.f, true);
	UG::MoveSprite(iLogoID, fGameplayScreenWidth * 0.5f, fGameplayScreenHeight * 0.75f);
	UG::DrawSprite(iLogoID);

	if (player1Points > player2Points)
	{
		winnerLine1 << "Player  1  is the";
	}
	else
	{
		winnerLine1 << "Player  2  is the";
	}
	winnerLine2 << "ULTIMATE CHAMPION!";
	UG::DrawString(winnerLine1.str().c_str(), (int)(fGameplayScreenWidth * 0.35f), (int)(fGameplayScreenHeight * 0.6f), 2.0f, UG::SColour(255, 0, 0, 255));
	UG::DrawString(winnerLine2.str().c_str(), (int)(fGameplayScreenWidth * 0.25f), (int)(fGameplayScreenHeight * 0.475f), 2.0f, UG::SColour(255, 0, 0, 255));

	UG::DrawString("PRESS ESCAPE TO QUIT", (int)(fGameplayScreenWidth * 0.37f), (int)(fGameplayScreenHeight * 0.25f), 1.0f);

	if (UG::IsKeyDown(UG::KEY_ESCAPE))
	{
		g_currentState = QUIT;
	}
}

Utilities::Utilities()
{
	fFrameTime = 0.2f;
	fExplosionFrameTime = 0.075f;

	InitialiseScreenProperties();
	gameplayManager = new GameplayManager(fGameplayScreenWidth, fGameplayScreenHeight, iScreenHeight);
	iMenuKeyCounter = 0;
}