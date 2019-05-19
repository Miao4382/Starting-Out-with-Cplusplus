// Programming Challenges 8: Total Purchase
#include <iostream>
using namespace std;

int main()
{
	double item_1 = 15.95, item_2 = 24.95, 
		   item_3 = 6.95, item_4 = 12.95, 
		   item_5 = 3.95, tax_rate=0.07, 
		   tax, subtotal, total;

	subtotal = item_1 + item_2 + item_3 + item_4 + item_5;
	tax = subtotal*tax_rate;
	total = subtotal + tax;

	cout << "The price of each item is shown in the following table:\n\n";
	cout << "item #\t1\t2\t3\t4\t5\n";
	cout << "Price\t" << item_1 << "\t" << item_2 << "\t" << item_3 << "\t" << item_4 << "\t" << item_5 << endl;
	cout << "\nSale subtotal: " << subtotal << endl;
	cout << "Sales tax: " << tax << endl;
	cout << "Total: " << total << endl;
	return 0;
 }