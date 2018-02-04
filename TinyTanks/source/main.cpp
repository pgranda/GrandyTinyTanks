//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Project: GrandyTinyTanks - Remake of 2D action game called Tiny Tanks
//
// Author: Pawel Granda
//
// Date Created: 09/02/2017
//
// Brief: 
//////////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma region Libraries and Header Files
#include "Utilities.h"
#pragma endregion

#pragma region Defining Global Variables

#pragma endregion

int main()
{
	//Seeding rand with a random number
	srand(static_cast<unsigned int>(time(nullptr)));

	if (UG::Create(1280, 1010, false, "GrandyTinyTanks", 100, 100))
	{
		Utilities gameUtility;

		gameUtility.g_currentState = SPLASH;
		gameUtility.DisplayLogo();
		gameUtility.MenuIndicator();

		do
		{
			gameUtility.g_fDeltaTime = UG::GetDeltaTime();
			gameUtility.fFrameTime -= gameUtility.g_fDeltaTime;
			gameUtility.fExplosionFrameTime -= gameUtility.g_fDeltaTime;


			UG::ClearScreen();

			switch (gameUtility.g_currentState)
			{
			case SPLASH:
			{
				gameUtility.HandleSplash();
				break;
			}
			case MENU:
			{
				gameUtility.HandleMenu();
				break;
			}

			case START:
			{
				gameUtility.HandleStart();
				break;
			}

			case GAMEPLAY:
			{
				gameUtility.HandleGameplay();
				break;
			}

			case GAMEOVER:
			{
				gameUtility.HandleGameover();
				break;
			}

			case QUIT:
			{
				UG::Close();
				break;
			}

			default:
				break;
			}

			UG::SetFont(nullptr);

		} while (UG::Process());

		UG::Dispose();
	}
	return 0;
}