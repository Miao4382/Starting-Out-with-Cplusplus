//26. Mobile Service Provider, Part_2
#include <iostream>
#include <string>
using namespace std;
int main()
{
	//constant definition
	const int M31 = 44640, M30 = 43200, M28 = 40320;
	
	//variable definition
	int selection=0;
	double min, charge1, charge2, charge3, charge, max_min;
	string month;

	//program input
	cout << "Choose one plan by inputting the designated number:\n";
	cout << "\t1. Package A\n\t2. Package B\n\t3. Package C\n";
	cin >> selection;
	if (selection == 1 || selection == 2 || selection == 3)
	{
		//To input month name
		cout << "What is the month?\n";
		cin >> month;

		//To validate month name input
		while (!(month == "January" || month == "March" || month == "May" || month == "July" || month == "August" || month == "October" || month == "December" || month == "April" || month == "June" || month == "September" || month == "November" || month == "February"))
		{
			cout << "Your input is invalid, please input a proper month name.\n";
			cin >> month;
		}

		//To assign the maximum minutes according to the month name
		if (month == "January" || month == "March" || month == "May" || month == "July" || month == "August" || month == "October" || month == "December")
			max_min = M31;
		else if (month == "April" || month == "June" || month == "September" || month == "November")
			max_min = M30;
		else if (month == "February")
			max_min = M28;

		//To input the call time
		cout << "What is your call time for this month (in minutes): ";
		cin >> min;

		//To check if call time is larger than maximum time in that month. If so, re-input call time (min)
		while (min > max_min)
		{
			cout << "Invalid input! Your call time is larger than the maximum time in " << month << ". Please input again\n";
			cin >> min;
		}

		//calculate charges for three package
		if (min >= 0)
		{
			//package 1
			if (min > 450)
				charge1 = 39.99 + (min - 450)*0.45;
			else
				charge1 = 39.99;
			//package 2
			if (min > 900)
				charge2 = 59.99 + (min - 900)*0.45;
			else
				charge2 = 59.99;
			//package 3
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