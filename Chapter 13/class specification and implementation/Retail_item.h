#ifndef RETAIL_ITEM_H
#define RETAIL_ITEM_H

#include <string>

class Retail_item
{
private:
	std::string description;
	int stock;
	double price;

public:
	/* Constructor */
	//default constructor
	Retail_item()
	{
		description = "N/A";
		stock = 0;
		price = 0.0;
	}
	//constructor 
	Retail_item(std::string description_input, int stock_input, double price_input)
	{
		description = description_input;
		stock = stock_input;
		price = price_input;
	}

	/* Mutator */
	void set_description(std::string description_input);
	void set_stock(int stock);
	void set_price(double price_input);

	/* Accessor */
	std::string get_description() const
	{
		return description;
	}
	int get_stock() const
	{
		return stock;
	}
	double get_price() const
	{
		return price;
	}
};

#endif
