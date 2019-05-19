#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

//constant
const int N = 10000;

//function prototype
void initialize_num(int num[], int total);
void find_num(int num[], int array_size, std::vector<int> &position, int &total_match, int number);

int main()
{
	int num[N];
	int total_match;
	int number;
	std::vector<int> position;
	char choice;

	//initialize num[] with random number
	initialize_num(num, N);

	do
	{
		//initialize
		total_match = 0;
		position.clear();

		//ask user to input a number
		std::cout << "What is the number you looking for: ";
		std::cin >> number;

		//use the find_num() to find out time of occurance and store subscript in position
		find_num(num, N, position, total_match, number);

		//print out total times of match and the position
		std::cout << "Total times of match: " << total_match << std::endl;
		std::cout << "The positions are: \n";
		for (int i = 0; i<position.size(); i++)
			std::cout << position[i] << std::endl;

		//ask for if user wants to repeat or not
		std::cout << "Do you want to test another number? (Y/N): ";
		std::cin >> choice;
		while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
		{
			std::cout << "Invalid input, please input Y or N: ";
			std::cin >> choice;
		}

	} while (choice == 'Y' || choice == 'y');

	std::cout << "You quitted.\n";

	return 0;

}

void initialize_num(int num[], int total)
{
	//initialize random generator
	int seed;
	seed = time(0);
	srand(seed);
	int N_max = 1000, N_min = 1;

	//begin recording
	for (int i = 0; i<total; i++)
		num[i] = rand() % (N_max - N_min + 1) + N_min;
}

//find number function
void find_num(int num[], int array_size, std::vector<int> &position, int &total_match, int number)
{
	for (int i = 0; i < array_size; i++)
	{
		if (num[i] == number)
		{
			total_match++;
			position.push_back(i + 1);
		}
	}
}