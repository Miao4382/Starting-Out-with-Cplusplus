//Monthly Payments
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main()
{
	//variable definition
	double rate, N, L, payment, amount, interest;

	//input instruction and input
	cout << "Please input the amount of the loan: ";
	cin >> L;
	cout << "Please input the monthly interest rate: ";
	cin >> rate;
	cout << "Please input the number of payments: ";
	cin >> N;

	//Calculation
	payment = (rate*pow(1 + rate, N)) / (pow(1 + rate, N) - 1)*L;
	amount = payment*N;
	interest = amount - L;

	//Output
	cout << setprecision(2) << fixed;
	cout << left << setw(26) << "Loan Amount:" << "$" << right << setw(10) << L << endl;
	cout << left << setw(26) << "Monthly Interest Rate:" << right << setw(10) << rate * 100 << "%" << endl;
	cout << left << setw(26) << "Number of Payments:" << " " << right << setw(10) << static_cast<int>(N) << endl;
	cout << left << setw(26) << "Monthly Payment:" << "$" << right << setw(10) << payment << endl;
	cout << left << setw(26) << "Amount Paid Back:" << "$" << right << setw(10) << amount << endl;
	cout << left << setw(26) << "Interest Paid:" << "$" << right << setw(10) << interest << endl;
	return 0;
}