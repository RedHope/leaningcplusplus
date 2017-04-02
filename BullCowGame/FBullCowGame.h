#pragma once
#include <string>

// Another way of thining about this, is similar to interfaces in JAVA.
class FBullCowGame {
public:
	void AllUserInputStrings();
	bool CheckCurrentUserInput(std::string) const;
	int GetMaxTries() const;
	int GetCurrentTry() const;
	void IncrementCurrentTry();
	bool IsGameWon() const;
	void Reset(); // Make a richer return value;
private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};