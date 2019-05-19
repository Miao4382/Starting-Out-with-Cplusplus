//28. Overloaded functions: calculate pay
#include <iostream>
#include <iomanip>

void calc_pay(double);
void calc_pay(double, int);
void get_choice(char &);

int main()
{
	char choice;
	get_choice(choice);
	std::cout << std::setprecision(2) << std::fixed;

	if (choice == 'H' || choice == 'h')
	{
		double pay_rate;
		int hour;
		std::cout << "How many hours were worked? ";
		std::cin >> hour;
		std::cout << "What is the hourly pay rate? ";
		std::cin >> pay_rate;
		calc_pay(pay_rate, hour);
	}
	else
	{
		double annual_rate;
		std::cout << "What is the annual salary? ";
		std::cin >> annual_rate;
		calc_pay(annual_rate);
	}

	return 0;
}

void calc_pay(double pay_rate, int hour)
{
	double salary = pay_rate*hour;
	std::cout << "The gross weekly pay is &" << salary << std::endl;
}

void calc_pay(double annual_rate)
{
	std::cout << "The gross weekly pay is $" << annual_rate / 52 << std::endl;
}

void get_choice(char &choice)
{
	std::cout << "Do you want to calculate the weekly pay of\n"
		<< "(H) an hourly paid employee, or\n"
		<< "(S) a salaried employee?\n"
		<< "Enter your choice (H or S): ";
	std::cin >> choice;
	while (choice != 'H' && choice != 'h' && choice != 'S' && choice != 's')
	{
		std::cout << "Invalid input, please input again!\n";
		std::cin >> choice;
	}
}