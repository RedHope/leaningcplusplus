#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// All values initialized to zero.
struct FBullCowCount
{
	int Bulls = 0;
	int Cows = 0;
};

enum class EGuessStatus
{
	OK,
	INVALID_LENGTH,
	INVALID_STATUS,
	NOT_ALL_LOWER_CASE,
	NOT_ISOGRAM,
	NO_VALUE
};
// Another way of thining about this, is similar to interfaces in JAVA.
class FBullCowGame {
public:
	FBullCowGame(); // Constructor
	void AllUserInputStrings();
	EGuessStatus CheckCurrentUserInput(FString) const;
	bool IsGameWon() const;

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	FBullCowCount SubmitValidGuess(FString);
	void Reset(); // Make a richer return value;
private:
	bool bGameWon;
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString HiddenWord;

	bool IsIsogram(FString) const;
};