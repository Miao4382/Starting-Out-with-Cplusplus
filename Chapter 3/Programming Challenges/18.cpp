//18. Interest Earned
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int main()
{
	//variable definition
	double rate, principal, amount, interest;
	int T;

	//Input instruction and input
	cout << "Please input the principal: ";
	cin >> principal;
	cout << "Please input the interest rate: ";
	cin >> rate;
	cout << "Please input the times compounded: ";
	cin >> T;

	//calculate the amount and the interest
	amount = principal*pow(1 + rate / T, T);
	interest = amount - principal;

	//Output
	cout << "The report is shown below: \n\n";
	cout << setprecision(2) << fixed;
	cout << left << setw(22) << "Interest Rate:" << " " << right << setw(9) << rate * 100 << "%" << endl;
	cout << left << setw(22) << "Times Compounded:" << " " << right << setw(9) << T << endl;
	cout << left << setw(22) << "Principal:" << "$" << right << setw(9) << principal << endl;
	cout << left << setw(22) << "Interest:" << "$" << right << setw(9) << interest << endl;
	cout << left << setw(22) << "Amount in Savings:" << "$" << right << setw(9) << amount << endl;
	return 0;

}