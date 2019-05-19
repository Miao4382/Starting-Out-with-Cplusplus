//25. Mobile Service Provider
#include <iostream>
using namespace std;
int main()
{
	//variable definition
	int selection=0;
	double min, charge;

	//program input
	cout << "Choose one plan by inputting the designated number:\n";
	cout << "\t1. Package A\n\t2. Package B\n\t3. Package C\n";
	cin >> selection;
	if (selection == 1 || selection == 2 || selection == 3)
	{
		cout << "What is your call time for this month (in minutes): ";
		cin >> min;
		if (min >= 0)
		{
			switch (selection)
			{
			case 1:
				if (min > 450)
					charge = 39.99 + (min - 450)*0.45;
				else
					charge = 39.99;
				break;
			case 2:
				if (min > 900)
					charge = 59.99 + (min - 900)*0.45;
				else
					charge = 59.99;
				break;
			case 3:
				charge = 69.99;
			}

			cout << "\nYour monthly charge will be:\n";
			cout << "$" << charge << endl;
		}
		else
			cout << "Invalid minutes entered, should be numbers greater than zero.\n";

	}
	else
		cout << "Invalid selection, please check again your input.\n";

	return 0;

}