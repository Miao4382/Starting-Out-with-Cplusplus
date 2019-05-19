//7. Time calculator
#include <iostream>
using namespace std;
int main()
{
	unsigned long long second, day, hour, min, second_0;

	cout << "Please input the number of seconds you want to transfer: ";
	cin >> second;
	second_0 = second;
	day = second / 86400;
	second %= 86400;
	hour = second / 3600;
	second %= 3600;
	min = second / 60;
	second %= 60;

	cout << second_0 << " seconds is: \n";
	if (day)
		cout << day << (day == 1 ? " day " : " days ");
	if (hour)
		cout << hour << (hour == 1 ? " hour " : " hours ");
	if (min)
		cout << min << (min == 1 ? " min " : " mins ");
	if (second)
		cout << second << (second == 1 ? " second " : " seconds ");

	cout << "\n";

	return 0;
}