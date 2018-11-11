#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

// Entry point for application
int main()
{
	PrintIntro();
	GetGuessAndPrintBack();
	cout << endl;
	return 0;
}

void PrintIntro()
{
	constexpr int WORD_LENGTH = 5;
	cout << "Welcom to Bulls and Cows.\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	cout << endl;
	return;
}

string GetGuessAndPrintBack()
{
	cout << "Enter your guess: ";
	string Guess = "";
	getline(cin, Guess);
	cout << "Your guess was: " << Guess << endl;
	return Guess;
}