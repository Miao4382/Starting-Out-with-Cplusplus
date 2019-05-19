//Random number producer
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
int main()
{
	//variable definition
	int N_max, N_min, num, seed, random_number;
	std::string path;

	//create a file stream object
	std::ofstream cout;

	//program description and input
	std::cout << "This program will produce random numbers for you and store them in a txt file.\n\n";
	std::cout << "Please input the lower limit of your random number set: ";
	std::cin >> N_min;
	std::cout << "Please input the upper limit of your random number set: ";
	std::cin >> N_max;
	std::cout << "How many random numbers you want to produce: ";
	std::cin >> num;
	//std::cout << "Please input the path you want to store your file: ";
	//std::cin.ignore();
	//getline(std::cin, path);

	//connect the file stream object with the file
	cout.open("D:\\random.txt");

	//notice of beginning
	std::cout << "Processing.....Please wait.....\n";

	//produce random number set
	seed = time(0);
	srand(seed);
	
	//use a for loop to produce the random numbers
	for (int i = 1; i <= num; i++)
	{
		random_number = rand() % (N_max - N_min + 1) + N_min;
		cout << random_number << std::endl;
	}

	//finish notice
	std::cout << "The processing is complete, please check the file.\n";
	cout.close();

	return 0;
}