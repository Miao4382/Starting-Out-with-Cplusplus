//Program 3-28: General Crates, Inc. Crates calculate program.
#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	//variable statement
	const double cost_unit = 0.23, charge_unit = 0.5;
	double 
		profit_unit,
		cost,
		charge,
		profit,
		length,
		width,
		height,
		volume;
	//input
	cout << "Please input the length of the crate: ";
	cin >> length;
	cout << "Please input the width of the crate: ";
	cin >> width;
	cout << "Please input the height of the crate: ";
	cin >> height;
	//calculation
	volume = length*width*height;
	profit_unit = charge_unit - cost_unit;
	cost = cost_unit*volume;
	charge = charge_unit*volume;
	profit = profit_unit*volume;
	//output
	cout << setprecision(2) << fixed;
	cout << "\n\nThe dimension of customer's crate is: " << length << " * " << width << " * " << height << ". \n";
	cout << "Volume is: " << volume << " cubic feet.\n";
	cout << "Cost of the crate would be: $" << cost << endl;
	cout << "Retail price of the crate would be: $" << charge << endl;
	cout << "Profit of the crate would be: $" << profit << endl;
	return 0;
}