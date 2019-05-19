//10. Future Value
#include <cmath>
#include <iostream>
#include <iomanip>

double future_value(double present_value, double month_rate, int month);

int main()
{
	double value_now, value_future, month_rate;
	int month;
	char choice;
	do
	{
		std::cout << "Input your present value, monthly interest rate and the number of months that the money will stay in the account\n";
		std::cin >> value_now >> month_rate >> month;
		value_future = future_value(value_now, month_rate, month);
		std::cout << "Your future value will be $" << value_future << std:: endl;
		std::cout << "Would you want to do another calculation? (Y/N)\n";
		std::cin >> choice;
		if (choice == 'N' || choice == 'n')
			std::cout << "You quited.\n";
	} while (choice != 'N'&&choice != 'n');

	return 0;
}

//definition of future_value function
double future_value(double present_value, double month_rate, int month)
{
	double value;
	value = present_value*pow((1 + month_rate), month);
	return value;
}
