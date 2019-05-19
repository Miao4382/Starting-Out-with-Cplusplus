//11. Automobile Costs
#include <iostream>
using namespace std;
int main()
{
	double loan, insurance, gas, oil, tire, maintenance, month_total, year_total;
	cout << "Please input the following monthly payments for your car:\nloan\ninsurance\ngas\noil\ntire\nmaintenance\n";
	cin >> loan >> insurance >> gas >> oil >> tire >> maintenance;
	month_total = loan + insurance + gas + oil + tire + maintenance;
	year_total = month_total * 12;
	cout << "The monthly total cost for your car is: " << month_total << endl << "The year total cost for your car is: " << year_total << endl;
	return 0;
}