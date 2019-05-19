#include <iostream>
using namespace std;

int main()
{
	short int small=2;
	double a,b;
	cout << "The size of small before the calculation is: " << sizeof(small) << ". Please enter a fractional value to calculate with small.";
	cin >> a;
	a = a*small;
	cout << "The size of small after the calculate is: " << sizeof(small) << ".\n";
	return 0;
}