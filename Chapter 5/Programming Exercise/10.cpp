//10. Average Rainfall
#include <iostream>
#include <fstream>
int main()
{
	//variable definition
	int year, month_total = 0;
	double rainfall, rainfall_total = 0, rainfall_average;

	//create a file stream object
	std::ofstream cout;
	cout.open("D:\\10.txt");

	//data input: year. And data check.
	std::cout << "How many years: ";
	std::cin >> year;
	while (year < 1)
	{
		std::cout << "Invalid input, please input again.\n";
		std::cin >> year;
	}

	//use a loop to input monthly rainfall
	for (int i = 1; i <= year; i++)
	{
		for (int j = 1; j <= 12; j++)
		{
			month_total++;
			std::cout << "What is the rainfall for month " << j << " year " << i << " : ";
			std::cin >> rainfall;
			while (rainfall < 0)
			{
				std::cout << "Invalid rainfall inputted, please input again:	";
				std::cin >> rainfall;
			}
			rainfall_total += rainfall;
		}
	}

	//calculate average
	rainfall_average = rainfall_total / month_total;

	//output
	std::cout << "Input complete, please check files for result.\n";
	cout << "Number of month: " << month_total << std::endl;
	cout << "The total inches or rainfall: " << rainfall_total << std::endl;
	cout << "Average rainfall per month: " << rainfall_average << " inches" << std::endl;
	cout.close();
	return 0;
}