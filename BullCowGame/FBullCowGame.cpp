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

EGuessStatus FBullCowGame::CheckCurrentUserInput(FString input) const
{
	//TODO Add check, return error / success

	if (input.length() != HiddenWord.length()) {
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

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
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

void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	MyMaxTries = 8;
	HiddenWord = "planet";
	return;
}
