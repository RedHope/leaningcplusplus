#pragma once
#include <string>

// Another way of thining about this, is similar to interfaces in JAVA.
class FBullCowGame {
public:
	void AllUserInputStrings();
	bool CheckCurrentUserInput(std::string);
	int GetMaxTries();
	int GetCurrentTry();
	void IncrementCurrentTry();
	bool IsGameWon();
	void Reset(); // Make a richer return value;
private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};