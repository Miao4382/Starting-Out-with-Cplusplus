//Program 5-7: The health plan
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double choice, month;
	double charge;
	const double ADULT_RATE = 40, SENIOR_RATE = 30, CHILD_RATE = 20;

	do
	{
		//show menue and get input
		cout << "Pick a plan by inpoutting the number:\n";
		cout << "1. Adult\n2.Senior\n3.Child\n4. Quit\n";
		cin >> choice;

		//check input: choice
		while (choice < 1 || choice>4 || fmod(choice, 1) != 0)
		{
			cout << "Invalid input, please input integer from 1 to 4.\n";
			cin >> choice;
		}
		if (choice == 4)
			cout << "You quited\n";
		else
		{
			//show next input information, input month
			cout << "Please input the month you want to purchase: ";
			cin >> month;

			//check input: month
			while (month <= 0 || fmod(month, 1) != 0)
			{
				cout << "The input is invalid. Number of month should be integer greater than zero. Please input again.\n";
				cin >> month;
			}

			//calculate charge
			switch (static_cast<int>(choice))
			{
			case 1: charge = month*ADULT_RATE; break;
			case 2: charge = month*SENIOR_RATE; break;
			case 3: charge = month*CHILD_RATE; break;
			}

			//output
			cout << "The charge is: $" << charge << endl;
		}
		

	} while (choice != 4);

	return 0;
}