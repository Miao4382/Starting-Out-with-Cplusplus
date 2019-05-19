// Program 3-5 calculating the area of a circle
#include <iostream>
using namespace std;

int main()
{
	double radius, area;
	const double pi = 3.1415926;

	cout << "This program calculates the area of a circle\n";
	cout << "What is the radius of the circle?\n";
	cin >> radius;
	area = pi*pow(radius, 2);
	cout << "The area is " << area << "\n";
	return 0;
}