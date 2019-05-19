#ifndef Sale_h
#define Sale_h

class Sale
{
private:
	double item_cost;
	double tax_rate;
public:
	//constructor
	Sale(double price, double rate);
	//return price
	double get_price() const
	{
		return item_cost;
	}
	//return tax rate 
	double get_rate() const
	{
		return tax_rate;
	}
	//show tax 
	double get_tax() const
	{
		return item_cost*tax_rate;
	}
	//show retail price 
	double get_retail_price() const
	{
		return item_cost + get_tax();
	}
};

#endif