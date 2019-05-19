//Checkpoint 3-19: Convert degrees to radiants
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double pi = 3.14159;
	double degrees, radians;

	cout << "Enter an angle in degrees and I will convert it to radians for you: ";
	cin >> degrees;
	radians = degrees / 180 * pi;
	cout << "\nThe radians is: ";
	cout << setprecision(15) << fixed << radians << endl;
	return 0;
}