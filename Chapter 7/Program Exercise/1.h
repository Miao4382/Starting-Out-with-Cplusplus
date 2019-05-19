//1. Largest/Smallest Array Values
#include<iostream>

int main()
{
	int numbers[10];
	int large, low;

	//ask for input for the first element
	std::cout << "Please input number 1: ";
	std::cin >> numbers[0];
	large = numbers[0];
	low = numbers[0];

	//use a loop to input the rest number
	for (int i = 1; i < 10; i++)
	{
		std::cout << "Please input number " << i + 1 << ": ";
		std::cin >> numbers[i];
		if (low > numbers[i])
			low = numbers[i];
		if (large < numbers[i])
			large = numbers[i];
	}

	//print out result
	std::cout << "Input complete\n\n"
		<< "The largest number in this list is: " << large << "\n"
		<< "The lowest number in this list is: " << low << "\n";

	return 0;
}