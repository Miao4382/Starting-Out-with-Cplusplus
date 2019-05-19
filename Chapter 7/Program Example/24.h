//7-24. Gross Pay program, achieved by vector
#include <vector>
#include<iostream>
#include<iomanip>

int main()
{
	const int NUM_EMPLOYEE = 5;

	//create two vectors to store the hour data and payrate data
	std::vector<int> hours(NUM_EMPLOYEE);
	std::vector<double> pay_rate(NUM_EMPLOYEE);

	//collect hour data and pay rate data
	for (int i = 0; i < NUM_EMPLOYEE; i++)
	{
		std::cout << "How many hours employee " << (i + 1) << " worked: ";
		std::cin >> hours[i];
		std::cout << "What is the pay rate for employee " << (i + 1) << ": ";
		std::cin >> pay_rate[i];
	}

	//display the gross pay
	std::cout << std::setprecision(2) << std::fixed;
	for (int i = 0; i < NUM_EMPLOYEE; i++)
	{
		double gross_pay = hours[i] * pay_rate[i];
		std::cout << "The gross pay of employee " << (i + 1) << " is: $" << gross_pay << std::endl;
	}

	return 0;
}