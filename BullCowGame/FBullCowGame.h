#pragma once
#include <string>

using FString = std::string;
using int32 = int;
// Another way of thining about this, is similar to interfaces in JAVA.
class FBullCowGame {
public:
	FBullCowGame(); // Constructor
	void AllUserInputStrings();
	bool CheckCurrentUserInput(FString) const;
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	void IncrementCurrentTry();
	bool IsGameWon() const;
	void Reset(); // Make a richer return value;
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
};