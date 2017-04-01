#pragma once

class FBullCowGame {
public:
	void Reset(); // Make a richer return value;
	int GetMaxTries();
	int GetCurrentTry();
	void AllUserInputStrings();
	bool CheckCurrentUserInput(string);
	bool IsGameWon();

private:
	int MyCurrentTry;
	int MyMaxTries;
};