/*
Console executable that makes use of BullCow Class.
The view in MVC. Controls user interaction.
Game logic in FBullCowGame
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;
bool AskToPlayAgain();
FText GetValidGuess();
int32 GetWordLengthFromUser();
void PlayGame(int32);
void PrintIntro();
void PrintLossSummary();
void PrintGameSummary(bool);
void PrintWinSummary();

FBullCowGame BCGame;

int main()
{
	PrintIntro();
	const int32 UserWordLength = GetWordLengthFromUser();
	do
	{
		PlayGame(UserWordLength);
	} while (AskToPlayAgain());
	return 0;
}

bool AskToPlayAgain()
{
	FText User_Input;
	std::cout << "Do you wish to play again? \n";
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

		EGuessStatus Status = BCGame.ValidateUserInput(Player_Guess);

		switch (Status)
		{
		case EGuessStatus::INVALID_LENGTH:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::NOT_ALL_LOWER_CASE:
			std::cout << "Please enter your guess in all lower case. \n";
			break;
		case EGuessStatus::NOT_ISOGRAM:
			std::cout << "The word you entered is not an isogram. \n";
			break;
		case EGuessStatus::NO_VALUE:
			std::cout << "No value entered!!. \n";
			break;
		default:
			return Player_Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);

	return Player_Guess;
}


int32 GetWordLengthFromUser()
{
	FString User_Input;
	std::cout << "What length of word would you like to play with?\n";
	std::cout << "Pick one from 3 to 6: " << std::endl;

	getline(std::cin, User_Input);

	return std::stoi(User_Input);
}

void PlayGame(int32 User_Word_Length)
{
	const int32 Number_Of_Guesses = BCGame.GetMaxTries(User_Word_Length);
	BCGame.Reset(User_Word_Length);
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() < Number_Of_Guesses)
	{

		FText Player_Guess = GetValidGuess();
		// TODO: Submit valid guess.
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Player_Guess);
		std::cout << "You entered: " << Player_Guess << std::endl;

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
		std::cout << "You have " << Number_Of_Guesses - BCGame.GetCurrentTry() + 1 << " turns left. \n";
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
	if (bPlayerWon) { PrintWinSummary(); }
	else { PrintLossSummary(); }
	return;
}

void PrintWinSummary() {
	std::cout << "Congratulations! That is the right word\n";
	std::cout << "You guessed the right word in: " << BCGame.GetCurrentTry() - 1 << " turn(s)\n";
	return;
}