//20. Random Number Guessing Game
#include <iostream>
#include <ctime>
#include <cstdlib>
int main()
{
	int num, guess, num_max, num_min, seed;
	//ask for limit
	std::cout << "What is the upper limit of the number: ";
	std::cin >> num_max;
	std::cout << "What is the lower limit of the number: ";
	std::cin >> num_min;

	//create a random number in the range
	seed = time(0);
	srand(seed);
	num = rand()%(num_max-num_min+1)+num_min;

	//use a loop to play the game
	std::cout << "Guess a number in the range of: " << num_min << " to " << num_max << std::endl;
	do
	{
		std::cin >> guess;
		if (guess == num)
			break;
		else if (guess > num)
			std::cout << "Your guess is higher than the answer.\n";
		else
			std::cout << "Your guess is lower than the answer.\n";
	} while (guess != num);

	std::cout << "Congratulations! You guessed the number!\n";

	return 0;

}