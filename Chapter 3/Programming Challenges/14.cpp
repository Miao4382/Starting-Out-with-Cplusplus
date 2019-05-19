//14. Monthly Sales Tax
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
	string month, year;
	double total, sale, county_tax, state_tax, total_tax;
	const double county_rate = 0.02, state_rate = 0.04;

	cout << "Please input the month: ";
	cin >> month;
	cout << "Please input the year: ";
	cin >> year;
	cout << "Please input the total amount collected at the cash register: ";
	cin >> total;
	sale = total / (1 + county_rate + state_rate);
	county_tax = sale*county_rate;
	state_tax = sale*state_rate;
	total_tax = county_tax + state_tax;
	cout << "Details are shown below:\n " << endl;
	cout << "Month: " << month << endl;
	cout << "Year: " << year << endl;
	cout << "--------------------";

	cout << setprecision(2) << fixed << endl;

	cout << left << setw(23) << "Total Collected:" << "$" << right << setw(10) << total << endl;
	cout << left << setw(23) << "Sales:" << "$" << right << setw(10) << sale << endl;
	cout << left << setw(23) << "County Sales Tax:" << "$" << right << setw(10) << county_tax << endl;
	cout << left << setw(23) << "State Sales Tax:" << "$" << right << setw(10) << state_tax << endl;
	cout << left << setw(23) << "Total Sales Tax:" << "$" << right << setw(10) << total_tax << endl;
	cout << endl;
	return 0;
}