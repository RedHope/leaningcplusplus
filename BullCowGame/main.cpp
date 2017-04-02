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
FText GetGuess();
void PlayGame(int32);
void Print32int32ro();

FBullCowGame BCGame;

int main()
{
	int32 MaxTries = BCGame.GetMaxTries();
	Print32int32ro();
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

FText GetGuess()
{
	FText Player_Guess = "";
	int32 Current_Try = BCGame.GetCurrentTry();
	std::cout << "Try " << Current_Try << ": Enter your guess: ";
	getline(std::cin, Player_Guess);

	return Player_Guess;
}

void PlayGame(int32 Number_Of_Guesses)
{	
	BCGame.Reset();
	for (int32 count = 0; count < Number_Of_Guesses; count++) {
		FText Player_Guess = GetGuess();
		// TODO: Validate Guess.
		// TODO: Submit valid guess.
		// TODO: Print32 number of bulls and cows. 
		std::cout << "You entered: " << Player_Guess << std::endl;
		std::cout << std::endl;
	}

}
void Print32int32ro()
{
	// int32roduce the Game.
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of? \n";

	return;
}