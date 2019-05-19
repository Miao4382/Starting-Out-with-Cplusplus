#include "Cash_register.h"
#include "Inventory_item.h"

#include <string>
#include <iostream>

/* Constructor */
Cash_register::Cash_register() //default constructor, set profit rate to 0.3, tax rate to 0.06
{
	profit_rate = 0.3;
	tax_rate = 0.06;
	cost = 0.0;
	quantity = 0;
	item_name = "N/A";
}

/* Mutator */
void Cash_register::set_tax_rate(double rate) //set tax rate 
{
	tax_rate = rate;
}
void Cash_register::set_profit_rate(double rate) //set profit rate 
{
	profit_rate = rate;
}
void Cash_register::input_purchase_info() //ask user to input purchase information, including quantity and item name
{
	std::cout << "Input item name of your purchase: ";
	getline(std::cin, item_name);
	std::cout << "How many you want to purchase: ";
	std::cin >> quantity;
	while (quantity <= 0)
	{
		std::cout << "Please input a value greater than zero: ";
		std::cin >> quantity;
	}
	std::cin.ignore();
}
void Cash_register::set_cost(Inventory_item *ptr, int size) //set cost of the item, it is read from inventory list 
{
	//find out the matched item in inventory data base
	bool found = false;
	int i;
	for (i = 0; i<size; i++)
		if (item_name == ptr[i].get_description())
		{
			found = true;
			break;
		}

	if (found && (quantity <= ptr[i].get_stock())) //if record is found, and quantity is less than stock, set cost
	{
		cost = ptr[i].get_cost();
		ptr[i].set_stock(ptr[i].get_stock() - quantity); //update stock number
	}
	else if (found) //quantity is larger than stock 
	{
		std::cout << "Purchase failed. There is only " << ptr[i].get_stock() << " item in stock.\n";
	}
	else if (!found) //item not found
	{
		std::cout << "Purchase failed. Item not found!\n";
	}

}

void Cash_register::set_cost(double num) //set cost back to zero after one purchase
{
	cost = 0.0;
}
/* Accessor */
void Cash_register::display_sales_detail() const //display subtotal, tax and total on screen
{
	if (cost != 0.0)
	{
		std::cout << "Purchase details:\n"
			<< "Unit price: $" << cost * (1 + profit_rate) << "\n"
			<< "Subtotal: $" << cost * (1 + profit_rate) * quantity << "\n"
			<< "Tax: $" << cost * (1 + profit_rate) * quantity * tax_rate << "\n"
			<< "Total: $" << (1 + tax_rate) * (cost * (1 + profit_rate) * quantity) << "\n";

	}
}









