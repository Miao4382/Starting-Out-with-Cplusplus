//20. Pizza Pi
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	//variable definition
	double diameter, radius, area, slice;
	const double pi = 3.14159, area_slice = 14.125;

	//input
	cout << "What is the diameter of your pizza?\n";
	cin >> diameter;

	//calculation
	radius = diameter / 2;
	area = pi*pow(radius, 2);
	slice = area / area_slice;

	//output
	cout << setprecision(1) << fixed;
	cout << "The pizza can be cut into " << slice << " slices.\n";

	return 0;
}