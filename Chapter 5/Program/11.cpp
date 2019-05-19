//Program 5-11: MPH-KPH convertor
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double kph, mph;
	const double RATE = 0.6214;
	cout << "KPH\tMPH\n";
	cout << "______________\n";
	cout << setprecision(1) << fixed;
	
	for (kph = 60; kph <= 130; kph += 10)
	{
		mph = kph*RATE;
		cout << kph << "\t" << mph << endl;
	}

	cout << "______________\n\n";
	return 0;
}