//This program demonstrates that, main function and other functions share the same
//random number list, same random number calling sequence.
#include <iostream>
#include <cstdlib>
#include <ctime>
int random();

int main()
{
	int seed, random_num;
	seed = time(0);
	srand(seed);
	
	for (int i = 1; i <= 10; i++)
	{
		std::cout << random() << std::endl;
	}

	std::cout << "Back in main:\n";

	for (int i = 1; i <= 10; i++)
	{
		std::cout << rand() << std::endl;
	}

	return 0;
}

int random()
{
	return rand();
}