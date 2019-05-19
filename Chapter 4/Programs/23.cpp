//Program 4-23: First using switch
#include <iostream>
using namespace std;

int main()
{
	char choice;

	cout << "Please enter A or B or C: \n";
	cin >> choice;

	switch (choice)
	{
	case 'A':
		cout << "You entered A\n";
		//break;
	case 'B':
		cout << "You entered B\n";
		//break;
	case 'C': 
		cout << "You entered C\n";
		//break;
	default: 
		cout << "You didn't input A or B or C.\n";
	}
	return 0;
}