//Program 4-27: Menu
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//variable definition
	const int ADULT_PLAN = 40, SENIOR_PLAN = 30, CHILD_PLAN = 20;
	const int ADULT = 1, SENIOR = 2, CHILD = 3, QUIT = 4;
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
	switch (choice)
	{
	case ADULT:
		cout << "How many month you wish to purchase?\n";
		cin >> month;
		total = month*ADULT_PLAN;
		cout << "Your purchase information is as follows:\n";
		cout << left << setw(20) << "Plan Type:" << "Adult\n";
		cout << left << setw(20) << "Rate:" << "$" << ADULT_PLAN << endl;
		cout << left << setw(20) << "Month:" << month << (month > 1 ? " months" : " month") << endl;
		cout << left << setw(20) << "Total:" << "$" << total << endl;
		break;

	case SENIOR:
		cout << "How many month you wish to purchase?\n";
		cin >> month;
		total = month*SENIOR_PLAN;
		cout << "Your purchase information is as follows:\n";
		cout << left << setw(20) << "Plan Type:" << "Senior citizen\n";
		cout << left << setw(20) << "Rate:" << "$" << SENIOR_PLAN << endl;
		cout << left << setw(20) << "Month:" << month << (month > 1 ? " months" : " month") << endl;
		cout << left << setw(20) << "Total:" << "$" << total << endl;
		break;
	case CHILD:
		cout << "How many month you wish to purchase?\n";
		cin >> month;
		total = month*CHILD_PLAN;
		cout << "Your purchase information is as follows:\n";
		cout << left << setw(20) << "Plan Type:" << "Child\n";
		cout << left << setw(20) << "Rate:" << "$" << CHILD_PLAN << endl;
		cout << left << setw(20) << "Month:" << month << (month > 1 ? " months\n" : " month\n");
		cout << left << setw(20) << "Total:" << "$" << total << endl;
		break;
	case QUIT:
		cout << "You've quitted.\n";
		break;
	default:
		cout << "Invalid Input!!\n";
	}

	return 0;

}