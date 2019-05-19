//3. Winning Division
#include <iostream>
#include <string>

double get_sales(std::string);
void findHighest(double sale1, double sale2, double sale3, double sale4);

double sale_NE, sale_SE, sale_NW, sale_SW;

int main()
{
	sale_NE = get_sales("Northeast");
	sale_SE = get_sales("Southeast");
	sale_NW = get_sales("Northwest");
	sale_SW = get_sales("Southwest");
	findHighest(sale_NE, sale_SE, sale_NW, sale_SW);

	return 0;
}

//get sales function
double get_sales(std::string name)
{
	double sales;
	std::cout << "Please input the sales figure for " << name << std::endl;
	std::cin >> sales;
	while (sales < 0)
	{
		std::cout << "Invalid input, please input again:\n";
		std::cin >> sales;
	}

	return sales;
}

//find highest function
void findHighest(double sale1, double sale2, double sale3, double sale4)
{
	double high=sale1;
	if (high < sale2)
		high = sale2;
	if (high < sale3)
		high = sale3;
	if (high < sale4)
		high = sale4;
	if (high == sale1)
		std::cout << "Northeast division has highest sale: $" << sale1 << std::endl;
	else if(high==sale2)
		std::cout << "Southeast division has highest sale: $" << sale2 << std::endl;
	else if (high==sale3)
		std::cout << "Northwest division has highest sale: $" << sale3 << std::endl;
	else
		std::cout << "Southwest division has highest sale: $" << sale4 << std::endl;


}