#include <iostream>
#include <string>
using namespace std;

int main() {
	// Introduce the Game.
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows\n"; 
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of? \n";

	//Ask the player for the guess.
	string Player_Guess = "";
	cin >> Player_Guess;

	cout << "You entered: " << Player_Guess << "\n";
	return 0;
}