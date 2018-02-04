#include "ScoresManager.h"

/**
Sets the Player 1 score

@param a_playerScore Score that we want to set.
*/
void ScoresManager::SetPlayer1Score(int a_playerScore)
{
	player1Score = a_playerScore;
}

/**
Sets the Player 2 score

@param a_playerScore Score that we want to set.
*/
void ScoresManager::SetPlayer2Score(int a_playerScore)
{
	player2Score = a_playerScore;
}

/**
Gets the Player 1 score

@return Player 1 Score
*/
int ScoresManager::GetPlayer1Score()
{
	return player1Score;
}

/**
Gets the Player 2 score

@return Player 2 Score
*/
int ScoresManager::GetPlayer2Score()
{
	return player2Score;
}

/**
Sets the game over flag.

@param a_isGameOver is game over flag.
*/
void ScoresManager::SetIsGameOver(bool a_isGameOver)
{
	isGameOver = a_isGameOver;
}

/**
Gets the game over flag value

@return is game over flag
*/
bool ScoresManager::GetIsGameOver()
{
	return isGameOver;
}

ScoresManager::ScoresManager()
{
	player1Score = 0;
	player2Score = 0;
	isGameOver = false;
}