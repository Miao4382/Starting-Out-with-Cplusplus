//20. Stock Profit
#include <iostream>

void get_info(int &NS, double &PP, double &PC, double &SP, double &SC);
double calc_profit(int NS, double PP, double PC, double SP, double SC);

int main()
{
	//variable definition
	int NS;
	double PP, PC, SP, SC;

	//get info using get_info function
	get_info(NS, PP, PC, SP, SC);

	//use calc_profit function to calculate the profit
	double profit;
	profit=calc_profit(NS, PP, PC, SP, SC);

	//print out result
	if (profit > 0)
	{
		std::cout << "You gained $" << profit << std::endl;
	}
	else if (profit < 0)
		std::cout << "You lost $" << profit << std::endl;
	else
		std::cout << "You didn't lose and gain.\n";

	return 0;
}

//input function
void get_info(int &NS, double &PP, double &PC, double &SP, double &SC)
{
	std::cout << "Please input number of stock, purchase price, purchase commision fee, sale price and sale comission fee:\n";
	std::cin >> NS >> PP >> PC >> SP >> SC;
}

//calculate
double calc_profit(int NS, double PP, double PC, double SP, double SC)
{
	return NS*(SP - PP) - SC - PC;
}
