//Program 5-9: Squares (for-loop approach)
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	//variable definition
	int N_min, N_max, count, power;

	//display input information
	cout << "This program will do math for you.\n";
	cout << "Please input the minimum number to start (an integer): ";
	cin >> N_min;
	cout << "Please input the maximum number to start (an integer): ";
	cin >> N_max;
	cout << "Please input the power of the number you want to calculate: ";
	cin >> power;

	//display the table head
	cout << "number\tnumber^" << power << endl;
	cout << "_____________________\n";

	//display the result using for loop
	cout << setprecision(5);
	for (count = N_min; count <= N_max; count++)
	{
		cout << count << "\t" << pow(count, power) << endl;
	}

	//finish the table
	cout << "_____________________\n";

	return 0;

}