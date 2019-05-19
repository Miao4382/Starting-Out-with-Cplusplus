//22. Angle Calculator
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	//variable definition
	double angle;

	//input
	cout << "Please input the angle (in radians)";
	cin >> angle;

	//output
	cout << "sin(" << angle << ") = " << sin(angle) << endl;
	cout << "cos(" << angle << ") = " << cos(angle) << endl;
	cout << "tan(" << angle << ") = " << tan(angle) << endl;
	return 0;
}