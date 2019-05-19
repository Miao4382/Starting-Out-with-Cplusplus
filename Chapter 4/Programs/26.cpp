//Program 4-26: Use fall through feature to catch both upper and lower case letter
#include <iostream>
using namespace std;

int main()
{
	//variable definition
	char grade_A, grade_B, grade_C, choice;

	//input information
	cout << "This is a price checking program. Please input the code for the level";
	cout << "\n of your pet food and see the price.\n";
	cin >> choice;

	//Display price
	switch (choice)
	{
	case 'A':
		;
	case 'a':
		cout << "The price of grade A pet food is: $50\n";
		break;
	case 'B':
		;
	case 'b':
		cout << "The price of grade B pet food is: $30\n";
		break;
	case 'C':
		;
	case 'c':
		cout << "The price of grade C pet food is: $10\n";
		break;
	default:
		cout << "Your input is invalid, please check again!\n";
	}

	return 0;
}