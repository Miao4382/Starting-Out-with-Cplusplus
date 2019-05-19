// Programming Challenges 13: Circuit Board Price
#include <iostream>
using namespace std;

int main()
{
	double cost = 14.95, profit_rate = 0.35, profit, sale_price;

	profit = cost*profit_rate;
	sale_price = cost + profit;

	cout << "The retail price for the circuit board is: " << sale_price << endl;
	return 0;
}