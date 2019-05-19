//Exercise 3-26: Total Sales
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double tax_rate, sales, tax, total;
	cout << "Please input the total sales: ";
	cin >> sales;
	cout << "Please input the tax rate: ";
	cin >> tax_rate;
	tax = tax_rate*sales;
	total = sales + sales*tax_rate;
	cout << right << endl;
	cout << setw(5) << "Sales" << setw(15) << sales << endl
		<< setw(5) << "Tax" << setw(15) << tax << endl
		<< "____________________\n"
		<< "Total" << setw(15) << total << endl;
	return 0;
}