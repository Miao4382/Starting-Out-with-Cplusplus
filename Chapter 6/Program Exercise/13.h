//13. Days Out
#include <iostream>

int get_employee_num();
double get_absent_days_total(int employee_num);
double calc_absent_days_average(int employee_num, double days);

int main()
{
	int employee_num;
	double days, average_days;
	employee_num = get_employee_num();
	days = get_absent_days_total(employee_num);
	average_days=calc_absent_days_average(employee_num, days);

	std::cout << "The average absent days are: " << average_days << std::endl;
	return 0;
}

//get employee number
int get_employee_num()
{
	int num;
	std::cout << "How many employees in the company: ";
	std::cin >> num;
	while (num < 1)
	{
		std::cout << "Invalid input. Number of employee can't be lower than 1, please re-input:\n";
		std::cin >> num;
	}

	return num;
}

//get total absent days
double get_absent_days_total(int employee_num)
{
	double total = 0, days;
	for (int i = 1; i <= employee_num; i++)
	{
		std::cout << "What is the absent day for employee " << i << std::endl;
		std::cin >> days;
		total += days;
	}

	return total;
}

//calculate average days
double calc_absent_days_average(int employee_num, double days)
{
	double average;
	average = days / employee_num;
	return average;
}