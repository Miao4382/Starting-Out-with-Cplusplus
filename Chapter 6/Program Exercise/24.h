//24. Rock, paper, scissors game
#include<iostream>
#include<cstdlib>
#include<ctime>

int random_num();
void choose_shape(int &pick);
void result(int pick_user, int pick_computer);

int main()
{
	//create a random number series
	int seed;
	seed = time(0);
	srand(seed);

	//pick define, choice is to ask user if he wants to continue or not
	int pick_user, pick_computer;
	char choice;

	//play the game while user decides to
	do
	{
		choose_shape(pick_user);
		pick_computer = random_num();
		result(pick_user, pick_computer);

		std::cout << "Would you want another trial? (Y/N)\n";
		std::cin >> choice;
		while (choice != 'Y'&&choice != 'y' && choice != 'N' && choice != 'n')
		{
			std::cout << "Please input Y or N: ";
			std::cin >> choice;
		}

	} while (choice != 'N'&&choice != 'n');

	if (choice == 'N' || choice == 'n')
		std::cout << "You quited.\n";

	return 0;
}

//return random number from 1 ~ 3
int random_num()
{
	return rand() % (3 - 1 + 1) + 1;
}

//show menu and ask for a pick
void choose_shape(int &pick)
{
	std::cout << "Pick one choice below:\n";
	std::cout << "1. Rock\n2. Paper\n3. Scissor\n";
	std::cin >> pick;
	while (pick != 1 && pick != 2 && pick != 3)
	{
		std::cout << "Invalid input. Please input 1 2 or 3:\n";
		std::cin >> pick;
	}
}

//decide the result and print on screen
void result(int pick_user, int pick_computer)
{
	if (pick_computer - pick_user == 0)
	{
		std::cout << "It's a draw! You and computer both chose: ";
		switch (pick_computer)
		{
		case 1: std::cout << "Rock\n"; break;
		case 2: std::cout << "Paper\n"; break;
		case 3: std::cout << "Scissor\n"; break;
		}
	}

	else if (pick_computer - pick_user == -1 || pick_computer - pick_user == 2)
	{
		switch (pick_user)
		{
		case 1: std::cout << "You chose: Rock, computer chose: Scissor. You win!\n"; break;
		case 2: std::cout << "You chose: Paper, computer chose: Rock. You win!\n"; break;
		case 3: std::cout << "You chose: Scissor, computer chose: Paper. You win!\n"; break;
		}
	}

	else
	{
		switch (pick_user)
		{
		case 1: std::cout << "You chose: Rock, computer chose: Paper. You lose!\n"; break;
		case 2: std::cout << "You chose: Paper, computer chose: Scissor. You lose!\n"; break;
		case 3: std::cout << "You chose: Scissor, computer chose: Rock. You lose!\n"; break;
		}
	}
}