// Programming Challenges 10: Miles per Gallon
#include <iostream>
using namespace std;

int main()
{
	const double gas = 15;
	double distance = 375, mpg;

	mpg = distance / gas;
	cout << "The car has a MPG of " << mpg << endl;
	return 0;
}