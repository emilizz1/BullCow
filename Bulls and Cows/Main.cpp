#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
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
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcom to Bulls and Cows.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	int MaxTries = BCGame.GetMaxTries();
	for (int i = 0; i < MaxTries; i++)
	{
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl;
	}

}

std::string GetGuess()
{
	std::cout << "Try " << BCGame.GetCurrentTry() << ". Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? ";
	std::string Response = "";
	std::getline(std::cin, Response);
	return Response[0] == 'y' || Response[0] == 'Y';
}