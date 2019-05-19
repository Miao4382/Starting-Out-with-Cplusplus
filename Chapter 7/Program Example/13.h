//7-13. Working with array: calculate the gross pay
#include <iostream>
int main()
{
	int hours[5];
	double pay_rate, wage;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Please input the working hours of employee " << i + 1 << ": ";
		std::cin >> hours[i];
	}

	std::cout << "Please input the hourly pay rate for the employee: ";
	std::cin >> pay_rate;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "The wage for employee " << i + 1 << " is: $" << hours[i] * pay_rate << std::endl;
	}

	return 0;
}