/*
Implementation of the BullCowGame class. 
*/
#pragma once
#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;

// This would be similar to impl(s) in JAVA.

FBullCowGame::FBullCowGame()
{
	Reset(0);
}

void FBullCowGame::AllUserInputStrings()
{
	return;
}

// Validates user input and returns a status fron Enum.
EGuessStatus FBullCowGame::ValidateUserInput(FString input) const
{
	if (!IsLowerCase(input)) {
		return EGuessStatus::NOT_ALL_LOWER_CASE;
	}
	else if (!IsIsogram(input)) {
		return EGuessStatus::NOT_ISOGRAM;
	}
	else if (input.length() != HiddenWord.length()) {
		return EGuessStatus::INVALID_LENGTH;
	}
	else {
		return EGuessStatus::OK;
	}
}

bool FBullCowGame::IsGameWon() const
{
	return bGameWon == true;
}

// Checks whether the user input is an isogram. 
bool FBullCowGame::IsIsogram(FString User_Input) const
{
	TMap<char, bool> LetterSeen; // instantiate map

	for (auto Letter : User_Input)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter] == true) {
			return false;
		}
		else {
			LetterSeen[Letter] = true;
		}
	}

	return true;
}

//checks if user input is all lower case.
bool FBullCowGame::IsLowerCase(FString User_Input) const
{
	for (auto Letter : User_Input)
	{
		if (!islower(Letter)) { return false; }
	}

	return true;
}

int32 FBullCowGame::GetMaxTries(int32 wordLength) const
{
	TMap<int32, int32> WordLengthToMaxTurnsMap = { {2,3}, {3,5}, {4,5}, {5,10}, {6, 14} };

	return WordLengthToMaxTurnsMap[wordLength];
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return HiddenWord.length();
}

// Receives valid guess, increments turn and returns count.
// Sets the isGameWon if user enters the correct word.
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	// increment the current try
	MyCurrentTry++;

	FBullCowCount CurrentTryBullCowCount;
	const int32 WORD_LENGTH = HiddenWord.length(); //assuming guess is valid.
	for (int32 i = 0; i < WORD_LENGTH; i++) {
		for (int32 j = 0; j < WORD_LENGTH; j++) {
			if (Guess[i] == HiddenWord[j] && i == j) {
				CurrentTryBullCowCount.Bulls++;
			}
			else if (Guess[i] == HiddenWord[j] && i != j) {
				CurrentTryBullCowCount.Cows++;
			}
		}
	}

	if (CurrentTryBullCowCount.Bulls == WORD_LENGTH && CurrentTryBullCowCount.Cows == 0)
	{
		bGameWon = true;
	}
	return CurrentTryBullCowCount;
}

// Initializer function.
void FBullCowGame::Reset(int32 User_Word_Length)
{
	TMap<int32, FString> WordLengthToWordMap = { { 0, ""},  {3, "car"}, {4, "home"}, {5, "plane"}, {6, "string"} };
	MyCurrentTry = 1;
	HiddenWord = WordLengthToWordMap[User_Word_Length];
	return;
}
