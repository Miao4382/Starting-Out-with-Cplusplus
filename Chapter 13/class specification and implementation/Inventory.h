#ifndef INVENTORY_H
#define INVENTORY_H

#include <cstdlib> //for exit(EXIT_FAILURE) function
#include <iostream>

class Inventory
{
private:
	int item_number;
	int stock;
	double cost_unit;
	double cost_total;

public:
	Inventory()
	{
		item_number = 0;
		stock = 0;
		cost_unit = 0;
		cost_total = 0;
	}

	Inventory(int item_number_input, int stock_input, double cost_unit_input)
	{
		if (item_number_input <= 0 || stock_input < 0 || cost_unit_input <0)
		{
			std::cout << "Invalid input...quitting...\n";
			exit(EXIT_FAILURE);
		}

		else
		{
			item_number = item_number_input;
			stock = stock_input;
			cost_unit = cost_unit_input;

			set_total_cost();
		}

	}

	/* Mutator */
	void set_item_number(int item_number_input)
	{
		if (item_number_input < 0)
		{
			std::cout << "Invalid input...quitting...\n";
			exit(EXIT_FAILURE);
		}

		item_number = item_number_input;
	}

	void set_stock(int stock_input)
	{
		if (stock_input < 0)
		{
			std::cout << "Invalid input...quitting...\n";
			exit(EXIT_FAILURE);
		}

		stock = stock_input;
	}

	void set_cost(double cost_unit_input)
	{
		if (cost_unit_input < 0)
		{
			std::cout << "Invalid input...quitting...\n";
			exit(EXIT_FAILURE);
		}

		cost_unit = cost_unit_input;
	}

	void set_total_cost()
	{
		cost_total = stock * cost_unit;
	}

	/* Accessor */
	int get_item_number() const
	{
		return item_number;
	}
	int get_stock() const
	{
		return stock;
	}
	double get_cost_unit() const
	{
		return cost_unit;
	}
	double get_cost_total() const
	{
		return cost_total;
	}

};

#endif
