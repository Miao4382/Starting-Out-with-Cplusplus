//Program 4-4: Comparing floating-point numbers
#include <iostream>
using namespace std;

int main()
{
	double a = 1.5, b = 1.5;
	b += 0.0000000000000001;

	if (a > b)
		cout << "a is not equal to b.\n";
	else if (a < b)
		cout << "a is not equal to b.\n";
	else
		cout << "a is equal to b.\n";
	return 0;
}