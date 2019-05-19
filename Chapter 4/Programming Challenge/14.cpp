//14. Bank Charges
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	//variable definition
	double balance, num, fee=0;
	
	//program input
	cout << "What is your starting balance?\n";
	cin >> balance;
	cout << "How many checks are written this month?\n";
	cin >> num;

	if (!(num >= 0 && balance >= 0))
	{
		cout << "Error message:\n";
		if (num < 0)
			cout << "Number of checks written cannot be negative number.\n";
		if (balance < 0)
			cout << "Your bank account is overdrawn!\n";
	}
	else
	{
		balance <= 400 ? fee = 15 : fee = 0;
		if (num < 20)
			fee = fee + 10 + 0.1*num;
		else if (num < 40)
			fee = fee + 10 + 0.08*num;
		else if (num < 60)
			fee = fee + 10 + 0.06*num;
		else if (num >= 60)
			fee = fee + 10 + 0.04*num;
		else
			cout << "Error occurred while calculating check fee.\n";
		cout << "Your bank charge is: $" << fee << endl;
	}
	
	return 0;
}