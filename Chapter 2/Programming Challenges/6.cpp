// Programming Challenges 6: Annual Pay
#include <iostream>
using namespace std;

int main()
{
	const double payAmount = 2200, payPeriods = 26;
	double annualPay;

	annualPay = payAmount*payPeriods;

	cout << "The annual pay is $" << annualPay << endl;
	return 0;
}