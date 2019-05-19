#ifndef CASH_REGISTER_H
#define CASH_REGISTER_H

#include <string>
#include "Inventory_item.h"

class Cash_register
{
private:
	double cost; //cost of the item, read from corresponding inventory_item object
	double profit_rate; //default 30%, initialized in constructor
	double tax_rate; //default 6%, sales tax rate
	int quantity; //amount of purchase
	std::string item_name; //hold name of the item, used as keyword to search in inventory list
	
public:
	/* Constructor */
	Cash_register(); //default constructor, set profit rate to 0.3, tax rate to 0.06
	
	/* Mutator */
	void set_tax_rate(double rate); //set tax rate 
	void set_profit_rate(double rate); //set profit rate 
	void input_purchase_info(); //ask user to input purchase information, including quantity and item name
	void set_cost(Inventory_item *ptr, int size); //set cost of the item, it is read from inventory list 
	void Cash_register::set_cost(double num); //reset cost of the item, only called after sales info displayed

	/* Accessor */
	void display_sales_detail() const; //display subtotal, tax and total on screen
};

#endif