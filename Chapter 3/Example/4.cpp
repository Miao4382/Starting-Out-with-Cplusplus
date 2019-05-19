/*This program asks the user to enter the numerator and denominator of a fraction, and it displays 
the decimal value*/

#include <iostream>
using namespace std;

int main()
{
	double numerator, denominator;
	double fractional;

	cout << "Please input the numerator and denominator, separate by space\n";
	cin >> numerator >> denominator;
	fractional = numerator / denominator;
	cout << "The decimal is: " << numerator/denominator << endl;
	return 0;
}