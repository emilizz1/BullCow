#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(){ Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MYMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLengh() const{	return MyHiddenWord.length; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MYMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (Guess.length != GetHiddenWordLengh())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::Ok;
	}
}

// Recieves a VALID guess, incriments turn, return bulls and cows
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 HiddenWordLengh = MyHiddenWord.length;
	for (int32 MHWChar = 0; MHWChar < HiddenWordLengh; MHWChar++)
	{
		for (int32 GChar = 0; GChar < HiddenWordLengh; GChar++)
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
	return BullCowCount;
}
