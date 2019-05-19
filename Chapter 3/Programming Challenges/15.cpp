//15. Property Tax
#include <iostream>
using namespace std;
int main()
{
	const double tax_rate = 0.0075, ass_rate = 0.6;
	double value_actual, value_ass, tax;
	cout << "Please input the actual value of the land: ";
	cin >> value_actual;
	value_ass = value_actual*ass_rate;
	tax = value_ass*tax_rate;
	cout << "The assessment value of the land is: $" << value_ass << endl;
	cout << "The property tax of the land is: $" << tax << endl;
	return 0;
}