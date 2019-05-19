//Program 5-12: running total
#include <iostream>
using namespace std;
int main()
{
	int count, total = 0, daily_sale, days;
	cout << "For how many days do you have sales figures: ";
	cin >> days;

	for (count = 1; count <= days; count++)
	{
		cout << "Enter the sales for day " << count << endl;
		cin >> daily_sale;
		total += daily_sale;
	}

	cout << "\nThe total sales are $" << total << endl;

	return 0;
}