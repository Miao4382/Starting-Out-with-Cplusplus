// Programming Challenges 4
#include <iostream>
using namespace std;

int main()
{
	double maleCharge = 88.67, taxRate = 0.0675, tipRate = 0.2, totalBill, tax, tip;

	tax = maleCharge*taxRate;
	tip = tipRate*(maleCharge + tax);
	totalBill = maleCharge + tax + tip;

	cout << "The male cost is $" << maleCharge << endl;
	cout << "The tax amount is $" << tax << endl;
	cout << "The tip amount is $" << tip << endl;
	cout << "The total amount is $" << totalBill << endl;

	return 0;
}