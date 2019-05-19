// Programming Challenges 3
#include <iostream>
using namespace std;

int main()
{
	double state_rate = 0.04, county_rate = 0.02, purchase = 95, tax;
	tax = purchase*state_rate + purchase*county_rate;
	cout << "The total sales tax is $" << tax << endl;
	return 0;
}