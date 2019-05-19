//Exercise-25: Available Credit
#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	double maximum_credit, used_credit, available_credit;
	cout << "Please input your maximum credit: ";
	cin >> maximum_credit;
	cout << "Please input your used credit: ";
	cin >> used_credit;
	available_credit = maximum_credit - used_credit;
	cout << "Your available credit is: " << available_credit << endl;
	return 0;
}