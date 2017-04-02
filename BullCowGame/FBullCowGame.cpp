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

int32 FBullCowGame::GetHiddenWordLength() const
{
	return HiddenWord.length();
}

// Receives valid guess, increments turn and returns count.
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the current try
	MyCurrentTry++;

	FBullCowCount CurrentTryBullCowCount;
	const int32 HIDDEN_WORD_LENGTH = HiddenWord.length();
	for (int32 i = 0; i < HIDDEN_WORD_LENGTH; i++) {
		for (int32 j = 0; j < HIDDEN_WORD_LENGTH; j++) {
			if (Guess[i] == HiddenWord[j] && i == j) {
				CurrentTryBullCowCount.Bulls++;
			}
			else if (Guess[i] == HiddenWord[j] && i != j ){
				CurrentTryBullCowCount.Cows++;
			}
		}
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
