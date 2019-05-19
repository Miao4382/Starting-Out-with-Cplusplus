//3. Magic Dates
#include <iostream>
using namespace std;
int main()
{
	int day, month, year,d_m;

	cout << "Please input a month:	";
	cin >> month;
	cout << "Please input a day:";
	cin >> day;
	cout << "Please input a year:";
	cin >> year;
	if ((month >= 1 && month <= 12) && (day >= 1 && day <= 31) && (year >= 0 && year <= 99))
		cout << (month*day == year ? "This date is a magic date!\n" : "This date is not a magic date!\n");
	else
		cout << "Your input is invalid, please check the numbers!\n";
	return 0;
}