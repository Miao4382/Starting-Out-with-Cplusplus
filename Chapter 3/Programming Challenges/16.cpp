//16. Senior Citizen Property Tax
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//Variable defination
	const double senior_exemption = 5000, ass_rate = 0.6;
	double value_actual, value_ass, tax_rate, tax, value_ass_exempt, payment_quart;

	//input and output
	cout << "Please input the actual value of the property: ";
	cin >> value_actual;
	cout << "Please input the current tax rate for each $100 of assessed value: ";
	cin >> tax_rate;

	//calculation
	value_ass = value_actual*ass_rate;
	value_ass_exempt = value_ass - senior_exemption;
	tax = value_ass_exempt / 100 * tax_rate;
	payment_quart = tax / 4;

	//set the display format
	cout << setprecision(2) << fixed; 

	//Output
	cout << "The owner is eligible for a senior exemption. Following table shows the amount of property tax and the quarterly tax bill.\n";
	cout << "------------------------------\n";
	cout << left << setw(20) << "Property tax:" << "$" << right << setw(8) << tax << endl;
	cout << left << setw(20) << "Quartly tax bill:" << "$" << right << setw(8) << payment_quart << endl;
	cout << "------------------------------\n";
	return 0;

}