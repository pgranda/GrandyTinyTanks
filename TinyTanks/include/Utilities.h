#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#define _USE_MATH_DEFINES

#include <fstream>
#include <windows.h>
#include <time.h>

#include "GameplayManager.h"

class Utilities
{
public:

	/**
	Function which initializes and creates the menu indicator.
	*/
	void MenuIndicator();

	/**
	Function which displays game logo in main menu.
	*/
	void DisplayLogo();

	/**
	Function which displays controls in start game state.
	*/
	void DisplayControls();

	/**
	Function which displays menu options.
	*/
	void DisplayMenu();

	/**
	Function which handles menu behaviour.
	*/
	void HandleMenu();

	/**
	Function which displays Splash and handles the behaviour.
	*/
	void HandleSplash();

	/**
	Function which handles the start game state behaviour.
	*/
	void HandleStart();

	/**
	Function which stops drawing menu options, logo and indicator.
	*/
	void StopDisplayingMenu();

	/**
	Function which handles game play state behaviour.
	*/
	void HandleGameplay();

	/**
	Function which handles game over state behaviour.
	*/
	void HandleGameover();

	GameStates g_currentState;
	float g_fDeltaTime;
	float fFrameTime;
	float fExplosionFrameTime;

	Utilities();

private:

	/**
	Function which initializes all the values needed in later game loop.
	*/
	void InitialiseScreenProperties();

	float fNewGameOptionY;
	float fQuitOptionY;

	float fIndicatorX;
	float fIndicatorY;

	int iScreenHeight;

	int fGameplayScreenWidth;
	int fGameplayScreenHeight;

	int iMenuKeyCounter;

	int iIndicatorID;
	int iLogoID;
	int iNewGameID;
	int iQuitID;
	int iControlsID;

	int iBackground;

	GameplayManager* gameplayManager;
};

#endif
