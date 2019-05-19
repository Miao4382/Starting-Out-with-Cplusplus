//13. Currency
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	const double YEN_PER_DOLLAR = 98.93, EUROS_PER_DOLLAR = 0.74;
	double dollar, yen, euro;
	cout << "This program can transfer US dollars to Yen and Euro. Please input the amount of US dollars below: ";
	cin >> dollar;
	yen = dollar*YEN_PER_DOLLAR;
	euro = dollar*EUROS_PER_DOLLAR;
	cout << setprecision(2) << fixed;
	cout << "$" << dollar << " = " << yen << " yen";
	cout << "\n$" << dollar << " = " << euro << " euro" << endl;
	return 0;

}