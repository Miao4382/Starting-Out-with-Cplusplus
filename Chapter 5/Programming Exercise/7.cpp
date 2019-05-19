//7. Pennies for Pay
#include <iostream>
#include <fstream>
#include<iomanip>
int main()
{
	int day;
	double pay = 0.01, total = 0.01;

	std::ofstream cout;
	cout.open("D:\\7.txt");

	std::cout << "Please input the number of days of working: ";
	std::cin >> day;

	while (day < 1)
	{
		std::cout << "Invalid input, please input again!\n";
		std::cin >> day;
	}
	std::cout << "Processing...please wait.\n";
	cout << "Days" << std::setw(15) << "Salary($)\n";
	cout << "--------------------\n";
	cout << std::setw(3) << "1" << std::setw(15) << pay << std::endl;
	cout << std::setprecision(2) << std::fixed;
	if (day > 1)
	{
		for (int i = 2; i <= day; i++)
		{
			pay *= 2;
			total += pay;
			cout << std::setw(3) << i << std::setw(15) << pay << std::endl;
		}
	}
	cout<<"--------------------\n";
	cout << "The total salary is $" << total << std::endl;
	
	std::cout << "The data was successfully written to the file.\n";
	return 0;

}