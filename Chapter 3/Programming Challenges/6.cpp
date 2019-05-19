//6. Ingredient Adjuster
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double sugar = 1.5/48, butter = 1.0/48, flour = 2.75/48;
	double cookie;
	cout << "Please input the number of cookies you want to make: ";
	cin >> cookie;
	cout << setprecision(1) << fixed;
	cout << "You will need " << sugar*cookie << " cups of sugar, "
		<< butter*cookie << " cups of butter and " << flour*cookie << " cups of flour.\n";
	return 0;
}