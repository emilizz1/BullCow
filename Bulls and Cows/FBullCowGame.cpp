#pragma once

#include "FBullCowGame.h"
#include <map>
#define TMap std::map // to make sintax Unreal friendly

FBullCowGame::FBullCowGame(){ Reset(); } // dedault constructor

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLengh() const{	return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const{ return bGameIsWon; }
int32 FBullCowGame::GetMaxTries() const 
{ 
	TMap<int32, int32>WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,15}, {7,20} };	
	 return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet"; // this Must be an Isogram
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (Guess.length() != GetHiddenWordLengh())
	{
		return EGuessStatus::Wrong_Length;
	}
	else if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	else
	{
		return EGuessStatus::Ok;
	}
}

// Recieves a VALID guess, incriments turn, return bulls and cows
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLengh = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < WordLengh; MHWChar++)
	{
		for (int32 GChar = 0; GChar < WordLengh; GChar++)
		{
			if (MyHiddenWord[MHWChar] == Guess[GChar])
			{
				if (MHWChar == GChar)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLengh)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
	//treat 0 or 1 letter words as isograms	
	if (Guess.length() <= 1) { return true; }

	TMap <char, bool> LetterSeen;
	for (auto Letter : Guess)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter])
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
		}
	}
	return true;
}

bool FBullCowGame::IsLowerCase(FString Guess) const
{
	for (auto Letter : Guess)
	{
		if (!islower(Letter))
		{
			return false;
		}
	}
	return true;
}
