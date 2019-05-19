//1. Markup
#include <iostream>

//function prototype
double calculate_retail(double, double);
void get_price_markup_rate(double &, double &);

int main()
{
	double price, mark_up_rate, retail_price;
	get_price_markup_rate(price, mark_up_rate);
	retail_price = calculate_retail(price, mark_up_rate);

	std::cout << "The retail price of the item is: $" << retail_price << std::endl;
	return 0;
}

void get_price_markup_rate(double &price, double &rate)
{
	std::cout << "Please input the price and the markup percentage of the item:\n";
	std::cin >> price >> rate;
	while (price < 0 || rate < 0)
	{
		std::cout << "Invalid input. Please input value greater than zero.\n";
		std::cin >> price >> rate;
	}
}

double calculate_retail(double price, double rate)
{
	return price*(1 + rate / 100);
}
