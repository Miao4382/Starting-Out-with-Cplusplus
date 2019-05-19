//Program 4-18: Menu
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//variable definition
	const int ADULT_PLAN = 40, SENIOR_PLAN = 30, CHILD_PLAN = 20;
	const int ADULT = 1, SENIOR = 2, CHILD = 3, QUIT=5;
	int choice;
	double month, total;

	//Input information and first check
	cout << "***********Welcome to membership perchase system***********\n";
	cout << "*Please input corresponding number to make your selection:*\n";
	cout << "*1. Purchase adult plan ($40 per month).                  *\n";
	cout << "*2. Purchase senior citizen plan ($30 per month).         *\n";
	cout << "*3. Purchase children plan ($20 per month).               *\n";
	cout << "*4. Quit.                                                 *\n";
	cout << "***********************************************************\n";
	cin >> choice;

	//different approaches for different selections
	if (choice == QUIT)
		cout << "You quited.\n";

	else if (choice == 1 || choice == 2 || choice == 3)
	{
		cout << "What is the period of membership you want to purchase?\n";
		cin >> month;
		cout << "Your purchase information is as follows: \n\n";

		if (choice == ADULT)
		{
			cout << left << setw(20) << "Plan type: " << "Adult\n";
			cout << setw(20) << "Rate: " << "$40/month\n";
			cout << setw(20) << "Period: " << month << " months.\n";
			cout << setw(20) << "Total: " << "$" << month*ADULT_PLAN << endl;

		}

		else if (choice == SENIOR)
		{
			cout << left << setw(20) << "Plan type: " << "Senior citizen\n";
			cout << setw(20) << "Rate: " << "$30/month\n";
			cout << setw(20) << "Period: " << month << " months.\n";
			cout << setw(20) << "Total: " << "$" << month*SENIOR_PLAN << endl;

		}
		else
		{
			cout << left << setw(20) << "Plan type: " << "Children\n";
			cout << setw(20) << "Rate: " << "$20/month\n";
			cout << setw(20) << "Period: " << month << " months.\n";
			cout << setw(20) << "Total: " << "$" << month*CHILD_PLAN << endl;

		}
	}

	else
		cout << "Invalid input!\n";

	
	return 0;


}