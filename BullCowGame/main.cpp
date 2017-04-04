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
void PrintLossSummary();
void PrintGameSummary(bool);
void PrintWinSummary();

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
	FText Player_Guess = "";
	EGuessStatus Status = EGuessStatus::INVALID_STATUS;
	do
	{
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

	return Player_Guess;
}

void PlayGame(int32 Number_Of_Guesses)
{
	BCGame.Reset();
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() < Number_Of_Guesses)
	{

		FText Player_Guess = GetValidGuess();
		// TODO: Submit valid guess.
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Player_Guess);
		std::cout << "You entered: " << Player_Guess << std::endl;

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << "Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}

	PrintGameSummary(BCGame.IsGameWon());

	return;
}
void PrintIntro()
{
	// int32roduce the Game.
	const int32 WORD_LENGTH = BCGame.GetHiddenWordLength();
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of? \n";

	return;
}

void PrintLossSummary() {
	std::cout << "Oh no, you lost!\n";
	std::cout << "You've exhausted all your available turns\n";
	return;
}

void PrintGameSummary(bool bPlayerWon) {
	if (bPlayerWon == true)
	{
		PrintWinSummary();
	}
	else
	{
		PrintLossSummary();
	}
	return;
}

void PrintWinSummary() {
	std::cout << "Congratulations! That is the right word\n";
	std::cout << "You guessed the right word in: " << BCGame.GetCurrentTry() - 1 << " turn(s)\n";
	return;
}