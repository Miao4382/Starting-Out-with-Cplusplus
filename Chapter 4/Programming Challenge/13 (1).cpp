//13. Book Club Points
#include <iostream>
using namespace std;
int main()
{
	int num, point;

	cout << "Please input the number of books purchased.\n";
	cin >> num;
	if (num >= 0)
	{
		switch (num)
		{
		case 0: point = 0; break;
		case 1: point = 5; break;
		case 2: point = 15; break;
		case 3: point = 30; break;
		default: point = 60; break;
		}
		cout << "You have earned: " << point << " points\n";
	}
	else
		cout << "Your input is invalid.\n";
	
	return 0;
}