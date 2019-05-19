//Program 3-17: This program studies the application of fix manipulator
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//define variables
	double day1, day2, day3, total;

	//Get the sales for each day
	cout << "Please input the sales for day1, day2 and day3.Type in space or enter between each sale\n";
	cin >> day1 >> day2 >> day3;
	
	//calculate total
	total = day1 + day2 + day3;

	//print out
	cout << "The sales figure is shown below:\n";
	cout << "***************\n";
	cout << setprecision(2) << fixed;
	cout << "Day_1" << setw(10) << day1 << endl;
	cout << "Day_2" << setw(10) << day2 << endl;
	cout << "Day_3" << setw(10) << day3 << endl;
	cout << "_______________\n";
	cout << "Total: " << setw(10) << total;
	cout << "\n***************\n";
	return 0;

}