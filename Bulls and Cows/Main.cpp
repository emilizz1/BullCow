/* This is the consule executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

// Entry point for application
int main()
{
	do
	{
		PrintIntro();
		PlayGame();
	} 
	while (AskToPlayAgain());
	return 0; // exit the application
}

void PrintIntro()
{
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcom to Bulls and Cows.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	for (int32 i = 0; i < MaxTries; i++)
	{
		FText Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl;
	}

}

FText GetGuess()
{
	std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return Response[0] == 'y' || Response[0] == 'Y';
}