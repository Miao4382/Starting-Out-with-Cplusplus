//Program 3-15 This program demonstrates how setprecision rounds a floating point value
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double quotient, a = 1322.342, b = 26.91;
	quotient = a / b;
	cout << quotient << endl;
	cout << setprecision(1) << quotient << endl;
	cout << setprecision(2) << quotient << endl;
	cout << setprecision(3) << quotient << endl;
	cout << setprecision(4) << quotient << endl;
	cout << setprecision(5) << quotient << endl;
	cout << setprecision(120) << quotient << endl;
	return 0;
}