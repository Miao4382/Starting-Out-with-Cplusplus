//23. Stock Transaction Program
#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	//variable definition
	double
		share = 1000,
		price_b = 45.5,
		price_s = 56.9,
		commission_r = 0.02,
		payment,
		sale,
		commission_fee_b,
		commission_fee_s;

	//calculation
	payment = share*price_b;
	commission_fee_b = commission_r*payment;
	sale = share*price_s;
	commission_fee_s = commission_r*sale;

	//output
	cout << "Joe paied $" << payment << " for the stock. He paid $" << commission_fee_b << " to his stock broker when he bought the stock.\n";
	cout << "He sold the stock for $" << sale << ". He paied $" << commission_fee_s << " to his stock broker when he sold the stock.\n";
	cout << "In this transaction, Joe got " << sale - payment - commission_fee_b - commission_fee_s << " dollars.\n";
	return 0;

}