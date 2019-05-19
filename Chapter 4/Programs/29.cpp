//Program 4-29: Variable definition inside a block
#include <iostream>
using namespace std;

int main()
{
	//define standard
	const double MINI_INCOME = 35000, MINI_YEAR = 5;

	cout << "Please input your annual income: ";
	double income;
	cin >> income;
	if (income >= MINI_INCOME)
	{
		double year;
		cout << "How long have you stayed on this job?\n";
		cin >> year;
		cout << (year >= MINI_YEAR ? "You're qualified.\n" : "You are not qualified because you must have a job for at least five years!\n");
	}
	else
		cout << "You are not qualified because your income is below 35000.\n";

	return 0;
}