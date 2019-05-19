//7. Number Analysis Program
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<fstream>
#include<string>

void generate_random_number(std::string path, int, int, int);
void find_high_low(std::vector<int> numbers);

int main()
{

	//generate a random number file
	int N_min = 1, N_max = 10000, num=120000;
	std::string random_path = "D:\\random_numbers.txt";
	generate_random_number(random_path, N_min, N_max, num);
	
	//file read streamer
	std::ifstream cin;
	cin.open(random_path);

	//read the random number file to the vector
	std::vector<int> numbers;
	int transfer_num;
	while (cin >> transfer_num)
		numbers.push_back(transfer_num);

	//print out the highest and lowest, also the average and total
	std::cout << "In " << num << " random numbers with a range of " << N_min << " - " << N_max << std::endl;
	find_high_low(numbers);

}

//random number file
void generate_random_number(std::string path, int N_min, int N_max, int num)
{
	int seed;
	seed = time(0);
	srand(seed);

	//file streamer
	std::ofstream cout;
	cout.open(path);

	//create random number file
	for (int i = 1; i <= num; i++)
		cout << (rand() % (N_max - N_min + 1) + N_min) << std::endl;

	//close the file
	cout.close();
}

//find highest and lowest
void find_high_low(std::vector<int> numbers)
{
	int total = 0;
	int high = numbers[0], low = numbers[0];
	for (int i = 0; i < numbers.size(); i++)
	{
		if (high < numbers[i])
			high = numbers[i];
		if (low > numbers[i])
			low = numbers[i];
		total += numbers[i];
	}

	std::cout << "The highest number is: " << high << "\n";
	std::cout << "The lowest number is: " << low << "\n";
	std::cout << "The sum of the number is: " << total << "\n";
	std::cout << "The average of the number is: " << static_cast<double>(total) / numbers.size() << "\n";

}
