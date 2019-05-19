//19. Pay Calculation
#include<iostream>
#include <iomanip>
//define global constants
const double PAY_RATE = 22.55;
const double BASE_HOURS = 40;
const double OT_MULTIPLIER = 1.5;

//function declaration(prototype)
double get_base_pay(double);
double get_ot_pay(double);
double get_hour();
void print_pay(double);

int main()
{
	double hour, pay;
	hour = get_hour();
	pay = get_base_pay(hour) + get_ot_pay(hour);
	print_pay(pay);
	return 0;
}

double get_hour()
{
	std::cout << "Welcome to pay calculation program. Please input the hour you worked: ";
	double hour;
	std::cin >> hour;
	while (hour <= 0)
	{
		std::cout << "Invalid input. Please input again: ";
		std::cin >> hour;
	}
	return hour;
}

double get_base_pay(double hour)
{
	if (hour <= BASE_HOURS)
		return hour*PAY_RATE;
	else
		return BASE_HOURS * PAY_RATE;
}

double get_ot_pay(double hour)
{
	if (hour <= BASE_HOURS)
		return 0;
	else
		return (hour - BASE_HOURS)*PAY_RATE*OT_MULTIPLIER;
}

void print_pay(double pay)
{
	std::cout << std::setprecision(2) << std::fixed;
	std::cout << "Your pay is: $" << pay << std::endl;
}