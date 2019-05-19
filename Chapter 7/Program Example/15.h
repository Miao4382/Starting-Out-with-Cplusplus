//7-15 Gross payroll
#include <iostream>
#include <iomanip>
int main()
{
	std::cout << std::setprecision(2) << std::fixed;
	const int NUM_EMPLOYEE = 5;
	double work_hour[NUM_EMPLOYEE], pay_rate[NUM_EMPLOYEE], pay[NUM_EMPLOYEE];
	std::cout << "Enter the hours worked by 5 employee and their hourly pay rates:\n";
	for (int i = 0; i < NUM_EMPLOYEE; i++)
	{
		std::cout << "Hours worked by employee #" << (i + 1) << ": ";
		std::cin >> work_hour[i];
		std::cout << "Hourly payrate for employee #" << (i + 1) << ": ";
		std::cin >> pay_rate[i];
		pay[i] = pay_rate[i] * work_hour[i];
	}

	std::cout << "Here is the gross pay for each employee:\n";
	for (int i = 0; i < NUM_EMPLOYEE; i++)
	{
		std::cout << "Employee #" << (i + 1) << ": $" << pay[i] << std::endl;
	}

	return 0;
}