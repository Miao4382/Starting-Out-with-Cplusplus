//21. Multiple Stock Profit
#include <iostream>

void get_info(int &NS, double &PP, double &PC, double &SP, double &SC, int stock_num);
double calc_profit(int NS, double PP, double PC, double SP, double SC);
double total(int num_stock);

int main()
{
	int num_stock;

	//input total number of stock
	std::cout << "What is the total number of stock: ";
	std::cin >> num_stock;

	//calculate the total using a function
	double total_profit;
	total_profit = total(num_stock);

	//print out total profit
	std::cout << "Your total profit is: $" << total_profit << std::endl;

	return 0;
}

//input function
void get_info(int &NS, double &PP, double &PC, double &SP, double &SC, int stock_num)
{
	std::cout << "Please input number of stock, purchase price, purchase commision fee, sale price and sale comission fee for sotck " << stock_num << std::endl;
	std::cin >> NS >> PP >> PC >> SP >> SC;
}

//calculate
double calc_profit(int NS, double PP, double PC, double SP, double SC)
{
	return NS*(SP - PP) - SC - PC;
}

//get total profit
double total(int num_stock)
{
	//variable definition
	double total = 0, profit_per_stock;
	int NS;
	double PP, PC, SP, SC;

	for (int i = 1; i <= num_stock; i++)
	{
		get_info(NS, PP, PC, SP, SC,i);
		profit_per_stock = calc_profit(NS, PP, PC, SP, SC);
		total += profit_per_stock;
	}

	return total;
}