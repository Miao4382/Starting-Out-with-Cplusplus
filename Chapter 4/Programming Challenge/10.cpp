//10. Days in a Month
#include <iostream>
using namespace std;
int main()
{
	int month, year;

	cout << "Please input the month and year: ";
	cin >> month >> year;
	switch (month)
	{
	case 1: cout << "31 days\n"; break;
	case 2:
		if (year % 100 == 0)
			cout << (year % 4 == 0 ? "29 days.\n" : "28 days.\n");
		else if (year % 4 == 0)
			cout << "29 days.\n";
		else
			cout << "28 days.\n";
		break;
	case 3: cout << "31 days\n"; break;
	case 4: cout << "30 days\n"; break;
	case 5: cout << "31 days\n"; break;
	case 6: cout << "30 days\n"; break;
	case 7: cout << "31 days\n"; break;
	case 8: cout << "31 days\n"; break;
	case 9: cout << "30 days\n"; break;
	case 10: cout << "31 days\n"; break;
	case 11: cout << "30 days\n"; break;
	case 12: cout << "31 days\n"; break;
	default: cout << "Invalid input!\n";
	}
	return 0;
}