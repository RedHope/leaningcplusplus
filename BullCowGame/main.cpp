#include <iostream>
#include <string>
using namespace std;

string GetGuess();
void PrintIntro();
int main() {
	PrintIntro();
	
	string Player_Guess = GetGuess();
	cout << "You entered: " << Player_Guess << endl;
	return 0;
}

string GetGuess() {
	string Player_Guess = "";
	getline(cin, Player_Guess);

	return Player_Guess;
}

void PrintIntro() {
	// Introduce the Game.
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of? \n";

	return;
}