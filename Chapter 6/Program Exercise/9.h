//9. Present Value
#include <iostream>

//function prototype
double present_value(double future_value, double annual_rate, int year);
double pow2(double num, int exponent);

int main()
{
	double future_value, annual_rate,deposit;
	int year;
	char choice;

	//input
	do
	{
		std::cout << "What is your future value:";
		std::cin >> future_value;
		std::cout << "What is the annual interest rate: ";
		std::cin >> annual_rate;
		std::cout << "How many years of deposit: ";
		std::cin >> year;
		deposit = present_value(future_value, annual_rate, year);
		std::cout << "You need to deposit $" << deposit << " to meet this goal.\n";
		
		//ask if the user wants another test
		std::cout << "Would you want to do another calculation: Y/N\n";
		std::cin >> choice;
		if (choice == 'N' || choice == 'n')
			std::cout << "You quited.\n";
	} while (choice != 'N'&&choice != 'n');

	return 0;
}

//a pow function, used to perform exponential calculation
double pow2(double num, int exponent)
{
	double result=1;
	for (int i = 1; i <= exponent; i++)
		result *= num;

	return result;
}

//present value fuction
double present_value(double future_value, double annual_rate, int year)
{
	double deposit;
	deposit = future_value / (pow2((1 + annual_rate), year));
	
	return deposit;
}
