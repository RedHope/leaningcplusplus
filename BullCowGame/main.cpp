#include <iostream>
#include <string>
#include "FBullCowGame.h"

bool AskToPlayAgain();
std::string GetGuess();
void PlayGame(int);
void PrintIntro();

FBullCowGame BCGame;

int main()
{
	int MaxTries = BCGame.GetMaxTries();
	PrintIntro();
	do
	{
		PlayGame(MaxTries);
	} while (AskToPlayAgain());
	return 0;
}

bool AskToPlayAgain()
{
	std::string User_Input;
	std::cout << "Do you wish to play again?";
	getline(std::cin, User_Input);

	return User_Input[0] == 'Y' || User_Input[0] == 'y';
}

std::string GetGuess()
{
	std::string Player_Guess = "";
	int Current_Try = BCGame.GetCurrentTry();
	std::cout << "Try " << Current_Try << ": Enter your guess: ";
	getline(std::cin, Player_Guess);

	return Player_Guess;
}

void PlayGame(int Number_Of_Guesses)
{	
	BCGame.Reset();
	for (int count = 0; count < Number_Of_Guesses; count++) {
		std::string Player_Guess = GetGuess();
		std::cout << "You entered: " << Player_Guess << std::endl;
		BCGame.IncrementCurrentTry();
		std::cout << std::endl;
	}

}
void PrintIntro()
{
	// Introduce the Game.
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of? \n";

	return;
}