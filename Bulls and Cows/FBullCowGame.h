#pragma once
#include <string>

class FBullCowGame
{
public:
	void Reset();
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string);


private:
	int MyCurrentTry = 1;
	int MYMaxTries = 5;
};
