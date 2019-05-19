#ifndef INVENTORY_ITEM_H
#define INVENTORY_ITEM_H

#include <string>

class Inventory_item
{
private:
	std::string description; //the item description
	double cost; //the item's cost 
	int stock; //the number of stock 
public:
	/* Overload constructor */
	//constructor 1
	Inventory_item()
	{
		description = "";
		cost = 0;
		stock = 0;
	}
	//constructor 2
	Inventory_item(std::string str)
	{
		description = str;
		cost = 0;
		stock = 0;
	}
	//constructor 3
	Inventory_item(std::string str, double cost_input)
	{
		description = str;
		cost = cost_input;
		stock = 0;
	}
	//constructor 4
	Inventory_item(std::string str, double cost_input, int stock_input)
	{
		description = str;
		cost = cost_input;
		stock = stock_input;
	}

	/* Mutator function */
	//set description 
	void set_description(std::string str)
	{
		description = str;
	}
	//set price
	void set_cost(double cost_input)
	{
		cost = cost_input;
	}
	//set stock number 
	void set_stock(int stock_input)
	{
		stock = stock_input;
	}

	/* Accessor function */
	//get description
	std::string get_description() const
	{
		return description;
	}
	//get cost 
	double get_cost() const
	{
		return cost;
	}
	//get stock 
	int get_stock() const
	{
		return stock;
	}

};

#endif


