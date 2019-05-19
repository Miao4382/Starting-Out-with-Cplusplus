//14. Lottery Application
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>

const int NUM_DIGIT = 5, N_min = 0, N_max = 9;

//function prototype
void generate_lottery(long long lottery[NUM_DIGIT]);
void input_lottery(long long user_num[NUM_DIGIT]);
void compare(long long lottery[NUM_DIGIT], long long user_num[NUM_DIGIT], std::vector<int> &matching);

int main()
{
	long long lottery[NUM_DIGIT], user_num[NUM_DIGIT];
	std::vector<int> matching;
	char choice;


	do
	{
		//use a function to generate lottery number
		generate_lottery(lottery);

		//ask user to input his or her lottery
		input_lottery(user_num);

		//compare these two array, to see the number of matchese
		compare(lottery, user_num, matching);

		//determine if the user win, and display details
		if (matching.size() == NUM_DIGIT)
			std::cout << "Congratulations! You won a grand prize!\n";
		else
			std::cout << "Better luck next time!\n";
		//show lottery number and user input number
		std::cout << "Lottery number: ";
		for (int i = 0; i < NUM_DIGIT; i++)
			std::cout << lottery[i] << " ";
		std::cout << "\nUser number: ";
		for (int i = 0; i < NUM_DIGIT; i++)
			std::cout << user_num[i] << " ";
		std::cout << "\n";
		//show number of matching digits and which are them
		std::cout << "Total matching number: " << matching.size() << ".";
		if (matching.size() > 0)
		{
			std::cout << " You matches with: ";
			for (int i = 0; i < matching.size(); i++)
				std::cout << "number " << matching[i] + 1 << ", ";
			std::cout << "\n\n";
		}
		std::cout << "\n\nWant another run? (Y/N) ";
		std::cin >> choice;
	} while (choice != 'N' && choice != 'n');

	if (choice == 'N' || choice == 'n')
		std:: cout << "You quited.\n";
	compare(lottery, user_num, matching);

	std::cout << matching.size();
	return 0;

}

//generate random lottery number
void generate_lottery(long long lottery[NUM_DIGIT])
{
	int seed;
	seed = time(0);
	srand(seed);

	for (int i = 0; i < NUM_DIGIT; i++)
		lottery[i] = rand() % (N_max - N_min + 1) + N_min;
}

//ask user to input lottery
void input_lottery(long long user_num[NUM_DIGIT])
{
	long long number;
	std::cout << "\n\nPlease input a " << NUM_DIGIT << " digit lottery number: ";
	std::cin >> number;

	for (int i = 0; i < NUM_DIGIT; i++)
	{
		user_num[NUM_DIGIT - 1 - i] = number % 10;
		number /= 10;
	}

}

//compare function
void compare(long long lottery[NUM_DIGIT], long long user_num[NUM_DIGIT], std::vector<int> &matching)
{
	matching.clear(); //to remove previous matching information
	for (int i = 0; i < NUM_DIGIT; i++)
	{
		if (lottery[i] == user_num[i])
			matching.push_back(i);
	}
}
