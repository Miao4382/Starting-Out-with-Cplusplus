//11. Population
#include <iostream>
#include <fstream>
#include <iomanip>
int main()
{
	std::ofstream cout;
	cout.open("D:\\11.txt");

	double num, day, rate;
	
	//input and data check, for initial number, increase percent, days
	std::cout << "What is the initial number of organisms: ";
	std::cin >> num;
	while (num < 2)
	{
		std::cout << "The number of organisms should be equal or greater than 2, please input again: ";
		std::cin >> num;
	}

	std::cout << "What is the daily population increase percent: ";
	std::cin >> rate;
	while (rate < 0)
	{
		std::cout << "Daily population increase percent should be greater than zero, please input again: ";
		std::cin >> rate;
	}


	std::cout << "How many days of reproduction?\n";
	std::cin >> day;
	while (day < 1)
	{
		std::cout << "Reproduction time should  >= 1 day, please input again: ";
		std::cin >> day;
	}

	std::cout << "Running...please wait.\n";
	
	//print the table head
	cout << std::left << std::setw(19) << "# of days" << "Population\n";
	cout << "--------------------------------\n";
	cout << std::right;

	//use a loop to print all the data
	for (int i = 0; i <= day; i++)
	{
		cout << std::setw(9) << i << std::setw(20) << num << std::endl;
		num *= 1 + rate / 100;
	}

	//print a table tail
	cout << "--------------------------------\n";

	//display successfull information
	std::cout << "The process is complete. Please check the text file.\n";

	cout.close();

	return 0;
}