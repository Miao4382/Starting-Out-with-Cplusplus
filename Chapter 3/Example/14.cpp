//Program 3-14: This program demonstrate the setw manipulation being used with values of various data type;
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int a = 500;
	double b = 29.51;
	string c = "Today is a fine day!";

	cout << "(" << setw(15) << a << ")\n";
	cout << "(" << setw(15) << b << ")\n";
	cout << "(" << setw(15) << c << ")\n";
	return 0;
}