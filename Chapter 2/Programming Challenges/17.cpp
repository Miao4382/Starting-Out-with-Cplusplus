// Programming Challenges 17: Stock Commission
#include <iostream>
using namespace std;

int main()
{
	double shares = 750, price = 35, commission_rate = 0.02, stock, commission, total;

	stock = shares*price;
	commission = commission_rate*stock;
	total = commission + stock;

	cout << "The amount paid for the stock alone: $" << stock << endl;
	cout << "The amount of the commission: $" << commission << endl;
	cout << "The total amount paid: " << total << endl;
	return 0;
}