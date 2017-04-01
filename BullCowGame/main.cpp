#include <iostream>
#include <string>

bool AskToPlayAgain();
std::string GetGuess();
void PlayGame(int);
void PrintIntro();

int main()
{
	constexpr int MAX_NUMBER_OF_GUESSES = 5;

	PrintIntro();
	do
	{
		PlayGame(MAX_NUMBER_OF_GUESSES);
	} while (AskToPlayAgain());
	return 0;
}

bool AskToPlayAgain()
{
	std::string User_Input;
	std::cout << "Do you wish to play again?";
	getline(std::cin, User_Input);

	return User_Input[0] == 'Y' || User_Input[0] == 'y';
}

std::string GetGuess()
{
	std::string Player_Guess = "";
	std::cout << "Enter your guess: ";
	getline(std::cin, Player_Guess);

	return Player_Guess;
}

void PlayGame(int Number_Of_Guesses)
{
	for (int count = 0; count < Number_Of_Guesses; count++) {
		std::string Player_Guess = GetGuess();
		std::cout << "You entered: " << Player_Guess << std::endl;
		std::cout << std::endl;
	}

}
void PrintIntro()
{
	// Introduce the Game.
	constexpr int WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of? \n";

	return;
}