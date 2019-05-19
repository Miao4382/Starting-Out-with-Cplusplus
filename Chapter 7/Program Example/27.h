//7-27. Gross Pay, can choose number of employees, use of push_back member function
#include<vector>
#include<iostream>

int main()
{
	int num_employee;
	std::vector<int> hours;
	std::vector<double> pay_rates;

	//input the number of employee
	std::cout << "Please input the number of employee: ";
	std::cin >> num_employee;
	while (num_employee <= 0)
	{
		std::cout << "Invalid input! Number of employee must be greater than zero. Please re-input: ";
		std::cin >> num_employee;
	}

	//use an iteration to get data
	int hour;
	double pay_rate;
	for (int i = 0; i < num_employee; i++)
	{
		std::cout << "How many hours employee " << (i + 1) << " worked: ";
		std::cin >> hour;
		std::cout << "What is the pay rate for employee " << (i + 1) << ": ";
		std::cin >> pay_rate;
		hours.push_back(hour);
		pay_rates.push_back(pay_rate);
	}

	//calculate and display total
	double gross_pay;
	for (int i = 0; i < num_employee; i++)
	{
		gross_pay = hours[i] * pay_rates[i];
		std::cout << "The gross pay for employee " << (i + 1) << " is $" << gross_pay << std::endl;
	}

	return 0;
}