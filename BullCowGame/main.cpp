/*
Console executable that makes use of BullCow Class.
The view in MVC. Controls user int32eraction.
Game locig in FBullCowGame
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;
bool AskToPlayAgain();
FText GetValidGuess();
void PlayGame(int32);
void PrintIntro();

FBullCowGame BCGame;

int main()
{
	int32 MaxTries = BCGame.GetMaxTries();
	PrintIntro();
	do
	{
		PlayGame(MaxTries);
	} while (AskToPlayAgain());
	return 0;
}

bool AskToPlayAgain()
{
	FText User_Input;
	std::cout << "Do you wish to play again?";
	getline(std::cin, User_Input);

	return User_Input[0] == 'Y' || User_Input[0] == 'y';
}

FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::INVALID_STATUS;
	do
	{
		FText Player_Guess = "";
		int32 Current_Try = BCGame.GetCurrentTry();
		std::cout << "Try " << Current_Try << ": Enter your guess: ";
		getline(std::cin, Player_Guess);

		EGuessStatus Status = BCGame.CheckCurrentUserInput(Player_Guess);

		switch (Status)
		{
		case EGuessStatus::INVALID_LENGTH:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::NOT_ALL_LOWER_CASE:
			std::cout << "Please enter your guess in all lower case";
			break;
		case EGuessStatus::NOT_ISOGRAM:
			std::cout << "The word you entered is not an isogram";
			break;
		case EGuessStatus::NO_VALUE:
			std::cout << "No value entered!!";
			break;
		default:
			return Player_Guess;
		}
	} while (Status != EGuessStatus::OK);
}

void PlayGame(int32 Number_Of_Guesses)
{
	BCGame.Reset();
	for (int32 count = 0; count < Number_Of_Guesses; count++) {
		FText Player_Guess = GetValidGuess();
		// TODO: Submit valid guess.
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Player_Guess);
		std::cout << "You entered: " << Player_Guess << std::endl;

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << "Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}

}
void PrintIntro()
{
	// int32roduce the Game.
	const int32 WORD_LENGTH = BCGame.GetHiddenWordLength();
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of? \n";

	return;
}