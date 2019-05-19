//3. Ocean Levels
#include<iostream>
#include<fstream>
#include<iomanip>
int main()
{
	//define constant rise rate
	const double RISE_RATE = 1.5;

	//initiate output file stream object
	std::ofstream cout;
	cout.open("D:\\3.txt");

	//To adjust printing format
	cout << std::setprecision(1) << std::fixed;

	//define a variable to hold maximum year number
	int year;

	//input maximum years
	std::cout << "How many years you want to show in table? ";
	std::cin >> year;

	//input validation: year
	while (year <= 0)
	{
		std::cout << "Invalid input, please input a year greater than 0.\n";
		std::cin >> year;
	}

	//print out table head
	cout << "Year from Now" <<std::setw(25) << "Rised Sea Level\n";
	cout << "-------------------------------------------\n";

	//use for loop to calculate the sea level for each year
	for (int i = 1; i <= year; i++)
	{
		cout <<std::setw(7) << i << std::setw(25) << i*RISE_RATE << std::endl;
	}

	//print out table tail
	cout<< "-------------------------------------------\n";

	//show information of work completion
	std::cout << "The table has been created, check file.\n";
	cout.close();
	return 0;
}