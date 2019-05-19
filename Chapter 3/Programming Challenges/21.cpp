//21. How many Pizzas?
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	//variable definition
	double diameter, radius, area, slice, N;
	double ppl;
	const double pi = 3.14159, area_slice = 14.125;

	//input
	cout << "How many people will attend the party?\n";
	cin >> ppl;
	cout << "What is the diameter of your pizza?\n";
	cin >> diameter;

	//calculation
	radius = diameter / 2;
	area = pi*pow(radius, 2);
	slice = area / area_slice;
	N = ppl * 4 / slice;

	//output
	cout << setprecision(1) << fixed;
	cout << "You should buy " << N << " pizzas.\n";

	return 0;
}