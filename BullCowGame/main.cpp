#include <iostream>
#include <string>
using namespace std;

string GetGuess();
void PlayGame(int);
void PrintIntro();

int main() {
	constexpr int MAX_NUMBER_OF_GUESSES = 5;

	PrintIntro();
	PlayGame(MAX_NUMBER_OF_GUESSES);

	return 0;
}

string GetGuess() {
	string Player_Guess = "";
	cout << "Enter your guess: ";
	getline(cin, Player_Guess);

	return Player_Guess;
}

void PlayGame(int Number_Of_Guesses) {
	for (int count = 0; count < Number_Of_Guesses; count++) {
		string Player_Guess = GetGuess();
		cout << "You entered: " << Player_Guess << endl;
		cout << endl;
	}

}
void PrintIntro() {
	// Introduce the Game.
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of? \n";

	return;
}