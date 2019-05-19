//10. How Much Insurance
#include <iostream>
using namespace std;
int main()
{
	double property_value, insurance;
	const double rate = 0.8;
	cout << "What is the replacement cost of your building?";
	cin >> property_value;
	insurance = property_value*rate;
	cout << "The minimum insurance you should pay is: " << insurance << endl;
	return 0;
}