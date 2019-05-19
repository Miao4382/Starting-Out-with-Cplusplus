//14. Order Status
#include <iostream>

//function prototype
void get_data(int &spool_order, int &spool_stock, int &special_handling);
void display_report(int spool_order, int spool_stock, int special_handling);

const double UNIT_PRICE = 100;

int main()
{
	int spool_order, spool_stock, special_handling;
	get_data(spool_order, spool_stock, special_handling);
	display_report(spool_order, spool_stock, special_handling);
}

//get data function: to input the desired data
void get_data(int &spool_order, int &spool_stock, int &special_handling)
{
	char choice;
	std::cout << "How many spool is ordered: ";
	std::cin >> spool_order;
	std::cout << "How many spool in stock: ";
	std::cin >> spool_stock;
	std::cout << "Is there a special handling charge: (y/n)";
	std::cin >> choice;
	while (choice != 'y' && choice != 'n')
	{
		std::cout << "Please input again, y/n:\n";
		std::cin >> choice;
	}
	if (choice == 'y')
	{
		std::cout << "What is the charge for special handling: ";
		std::cin >> special_handling;
	}
	else
		special_handling = 10;
}

void display_report(int spool_order, int spool_stock, int special_handling=10)
{
	
	if (spool_order <= spool_stock)
	{
		std::cout << "Number of spools ready to ship: " << spool_order << "\n";
		std::cout << "Subtotal of the spools ready to ship: " << spool_order*UNIT_PRICE << "\n";
		std::cout << "Total shipping and handling charge: " << spool_order*special_handling << "\n";
		std::cout << "Total of the order: " << spool_order*(UNIT_PRICE + special_handling) << "\n";
	}
	else
	{
		std::cout << "Number of spools ready to ship: " << spool_stock << std::endl;
		std::cout << "Number of spools on backorder: " << spool_order - spool_stock << std::endl;
		std::cout << "Subtotal of the spools ready to ship: " << spool_stock*UNIT_PRICE << std::endl;
		std::cout << "Total shipping and handling charge: " << spool_stock*special_handling << std::endl;
		std::cout << "Total of the order ready to ship: " << spool_stock*(UNIT_PRICE + special_handling) << std::endl;
	}
}
