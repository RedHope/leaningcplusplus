#include "FBullCowGame.h"

// This would be similar to impl(s) in JAVA.

void FBullCowGame::AllUserInputStrings()
{
	return;
}

bool FBullCowGame::CheckCurrentUserInput(std::string) const
{
	return false;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

void FBullCowGame::IncrementCurrentTry()
{
	MyCurrentTry++;
}

void FBullCowGame::Reset()
{
	return;
}
