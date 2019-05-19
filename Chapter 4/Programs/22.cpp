//Program 4-22: Using value of conditional operator
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	//variable definition
	const double PAY_RATE = 50, MINI_HOUR = 5;
	double hours, charge;

	//input data
	cout << "how many hours worked?\n";
	cin >> hours;

	//determine work time and total charge (PS: you can still assign value to hours!!)
	charge = hours > MINI_HOUR ? PAY_RATE*hours : PAY_RATE*MINI_HOUR;

	//output
	cout << setprecision(2) << fixed;
	cout << "The total charge is: $" << charge << endl;

	return 0;
}