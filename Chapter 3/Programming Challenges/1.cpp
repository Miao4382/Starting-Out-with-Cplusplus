//1: Miles per Gallon
#include <iostream>

using namespace std;
int main()
{
	double gas, mile, mile_per_galon;
	cout << "Please input the gas volume your car can hold: ";
	cin >> gas;
	cout << "Please input the mileage your car can drive with a full tank of gas: ";
	cin >> mile;
	mile_per_galon = mile / gas;
	cout << "Your car's mile per gallon is: " << mile_per_galon << endl;
	return 0;
}