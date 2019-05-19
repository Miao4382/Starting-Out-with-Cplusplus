//8. Coin Toss+
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <string>

std::string coin_toss();
void welcome();
void get_time(int &);

int main()
{
	//welcome and get total time
	welcome();
	int total_times, head_times = 0;
	double head_probability;
	get_time(total_times);

	//create a file stream object
	std::ofstream cout("D:\\8.txt");
	cout << std::setprecision(2) << std::fixed;

	//print the table head
	cout << "**Coin Toss Master**\n\n"
		<< "  Number of Tossing            Result\n"
		<< "-----------------------------------------\n";

	//plant seed (although the seed is planted in main() function, it can 
	//generate a rand() series which is accessible by other function. And 
	//the calling of random number in this random number series both share
	//one sequence, demonstrated by 8-random number explore.h
	int seed;
	seed = time(0);
	srand(seed);

	//use a loop to get the result. The string variable is used to store coin_toss result
	std::string result;
	for (int i = 1; i <= total_times; i++)
	{
		result = coin_toss();
		cout << std::setw(13) << i << std::setw(24) << result << std::endl;
		result == "heads" ? head_times++ : head_times = head_times;
	}

	//print the table tail
	cout << "-----------------------------------------\n\n";

	//calculate the result
	head_probability = static_cast<double>(head_times) / total_times;

	//print the results and probability
	cout << "Total times of tossing: " << total_times << std::endl;
	cout << "Head times: " << head_times << std::endl;
	cout << "Tail times: " << total_times - head_times << std::endl;
	cout << "Head probability: " << head_probability * 100 << "%\n";
	cout << "Tail probability: " << 100 * (1 - head_probability) << "%\n";
	cout.close();

	return 0;
}

//welcome function: purpose declare
void welcome()
{
	std::cout << "Welcome to coin toss v1.00\n"
		<< "Please input the number of tossing times you want to perform: ";
}

//get total tossing time
void get_time(int &time)
{
	std::cin >> time;
	while (time <= 0)
	{
		std::cout << "Invalid input. The tossing times should be greater than zero.\n";
		std::cin >> time;
	}
}

//coin tossing function, return value to keep a record of head or tail
std::string coin_toss()
{
	int random_num;
	random_num = rand() % (2 - 1 + 1) + 1;
	if (random_num == 1)
		return "heads";
	else
		return "tails";
}