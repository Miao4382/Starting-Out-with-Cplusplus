//26. Mobile Service Provider, Part_2
#include <iostream>
using namespace std;
int main()
{
	//variable definition
	int selection=0;
	double min, charge1, charge2, charge3, charge;

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
			//calculate charges for three package
			if (min > 450)
				charge1 = 39.99 + (min - 450)*0.45;
			else
				charge1 = 39.99;

			if (min > 900)
				charge2 = 59.99 + (min - 900)*0.45;
			else
				charge2 = 59.99;

			charge3 = 69.99;

			//decide user's charge and display
			switch (selection)
			{
			case 1: charge = charge1; break;
			case 2: charge = charge2; break;
			case 3: charge = charge3; break;
			}
			cout << "Your charge for this month is:	$" << charge << endl;

			//compare user's charge with other charges
			if (charge1 < charge)
				cout << "If you select plan A, you'll save: $" << charge - charge1 << endl;
			if (charge2 < charge)
				cout << "If you select plan B, you'll save: $" << charge - charge2 << endl;
			if (charge3 < charge)
				cout << "If you select plan C, you'll save: $" << charge - charge3 << endl;

		}
		else
			cout << "Invalid minutes entered, should be numbers greater than zero.\n";

	}
	else
		cout << "Invalid selection, please check again your input.\n";

	return 0;

}