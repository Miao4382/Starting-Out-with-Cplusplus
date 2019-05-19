// Programming Challenges 7: Ocean Levels
#include <iostream>
using namespace std;

int main()
{
	const double rise = 1.5;
	double five, seven, ten;
	five = rise * 5;
	seven = rise * 7;
	ten = rise * 10;

	cout << "After five years, the sea level will be " << five << " milimeters higher than today.\n";
	cout << "After seven years, the sea level will be " << seven << " milimeters higher than today.\n";
	cout << "After ten years, the sea level will be " << ten << " milimeters higher than today.\n";

	return 0;
}