#include "FBullCowGame.h"

// This would be similar to impl(s) in JAVA.

void FBullCowGame::AllUserInputStrings()
{
	return;
}

bool FBullCowGame::CheckCurrentUserInput(std::string)
{
	return false;
}

bool FBullCowGame::IsGameWon()
{
	return false;
}

int FBullCowGame::GetMaxTries()
{
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry()
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
