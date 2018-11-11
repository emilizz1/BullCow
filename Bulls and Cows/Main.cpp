#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

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
	cout << "Welcom to Bulls and Cows.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}

void PlayGame()
{
	constexpr int numberOfTurns = 5;
	for (int i = 0; i < numberOfTurns; i++)
	{
		string Guess = GetGuess();
		cout << "Your guess was: " << Guess << endl;
	}

}

string GetGuess()
{
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again? ";
	string Response = "";
	getline(cin, Response);
	return Response[0] == 'y' || Response[0] == 'Y';
}