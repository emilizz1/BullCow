// the game logic (no view code or user interaction)
#pragma once
#include <string>

// to make sintax Unreal friendly
using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalis_Status,
	Ok, 
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
};

class FBullCowGame
{
public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLengh() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;
	void Reset();
	FBullCowCount SubmitValidGuess(FString);

private:
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};
