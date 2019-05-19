//12. Celsius to Fahrenheit
#include <iostream>
using namespace std;
int main()
{
	double F, C;
	cout << "Input the temperature in Celsius, this program will transfer it to Fahrenheit to you!";
	cin >> C;
	F = 9.0 / 5 * C + 32;
	cout << "The corresponding Fahrenheit temperature is: " << F << " degrees" << endl;
	return 0;
}