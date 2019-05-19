//7-14 Array counter
#include <iostream>
#include<fstream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::ofstream cout("D:\\random number.txt");

	//random number generation
	int seed;
	seed = time(0);
	srand(seed);

	//write random number into txt file
	for (int i = 1; i <= 100; i++)
	{
		cout << rand() % (100) << std::endl;
	}
	cout.close();

	//read number to the array, stop if finish reading or reach maximum array elements number
	std::ifstream cin("D:\\random number.txt");
	const int ARRAY_SIZE = 40;
	int number[ARRAY_SIZE];
	int count = 0;
	while (count < ARRAY_SIZE && cin >> number[count])
		count++;
	cin.close();

	//print out number
	std::cout << "The random numbers are:\n";
	for (int i = 0; i < count; i++)
		std::cout << number[i] <<" (" << (i+1) <<") "<< std::endl;

	return 0;
}