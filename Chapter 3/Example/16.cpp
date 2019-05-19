//Program 3-16
/*This program asks for sales figures for 3 days. The total sales are calculated and displayed in a table*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int main()
{
	double day1, day2, day3, total;
	string line = "______________________________";
	cout << "Please input the sale on day 1: ";
	cin >> day1;
	cout << "\nPlease input the sale on day 2: ";
	cin >> day2;
	cout << "\nPlease input the sale on day 3:";
	cin >> day3;
	total = day1 + day2 + day3;
	cout << setprecision(4);
	cout << "\n\nThe sales figure and total sale is shown in the following table: \n"
		<< "day\tsale\nday1\t" << setw(5) << day1 << endl << "day2\t" << setw(5) << day2 << endl << "day3\t" << setw(5) << day3 << endl;
	cout << setprecision(4) << line << endl << "Total\t" << setw(5) << total << endl;
	return 0;
}