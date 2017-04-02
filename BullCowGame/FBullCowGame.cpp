#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;
// This would be similar to impl(s) in JAVA.

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::AllUserInputStrings()
{
	return;
}

bool FBullCowGame::CheckCurrentUserInput(FString) const
{
	return false;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

// Receives valid guess, increments turn and returns count.
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	// increment the current try
	MyCurrentTry++;
	return BullCowCount();
}

void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	MyMaxTries = 8;
	HiddenWord = "planet";
	return;
}
