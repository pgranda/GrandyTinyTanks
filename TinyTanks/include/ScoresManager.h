#ifndef _SCORESMANAGER_H_
#define _SCORESMANAGER_H_

//The classic lazy evaluated and correctly destroyed singleton.
class ScoresManager
{
public:
	static ScoresManager& getInstance()
	{
		static ScoresManager    instance; // Guaranteed to be destroyed.
										  // Instantiated on first use.
		return instance;
	}
private:
	ScoresManager();                   // Constructor? (the {} brackets) are needed here.

	int player1Score;
	int player2Score;
	bool isGameOver;

public:
	ScoresManager(ScoresManager const&) = delete;
	void operator=(ScoresManager const&) = delete;

	/**
	Sets the Player 1 score

	@param a_playerScore Score that we want to set.
	*/
	void SetPlayer1Score(int a_playerScore);

	/**
	Sets the Player 2 score

	@param a_playerScore Score that we want to set.
	*/
	void SetPlayer2Score(int a_playerScore);

	/**
	Gets the Player 1 score

	@return Player 1 Score
	*/
	int GetPlayer1Score();

	/**
	Gets the Player 2 score

	@return Player 2 Score
	*/
	int GetPlayer2Score();

	/**
	Sets the game over flag.

	@param a_isGameOver is game over flag.
	*/
	void SetIsGameOver(bool a_isGameOver);

	/**
	Gets the game over flag value

	@return is game over flag
	*/
	bool GetIsGameOver();

	// Note: Scott Meyers mentions in his Effective Modern
	//       C++ book, that deleted functions should generally
	//       be public as it results in better error messages
	//       due to the compilers behavior to check accessibility
	//       before deleted status
};

#endif