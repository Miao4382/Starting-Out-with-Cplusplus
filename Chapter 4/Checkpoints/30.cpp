//Checkpoint 4-30: 1, 2, 3 game
#include <iostream>
using namespace std;

int main()
{
	int user_num;
	cout << "Enter one of the numbers 1, 2, or 3: ";
	cin >> user_num;

	switch (user_num)
	{
	case 1: 
		cout << "One\n";
		break;
	case 2:
		cout << "Two\n";
		break;
	case 3:
		cout << "Three\n";
		break;
	default:
		cout << "Invalid input!\n";
	}
	return 0;
}