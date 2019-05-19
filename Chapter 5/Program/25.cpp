//Program 5-25: use break statement to stop a loop
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	//variable definition
	double num;
	char choice;

	do
	{
		//program input
		cout << "Enter a number to do the calculation: ";
		cin >> num;
		//while (typeid(num) != typeid(double))
		//{
		//	cout << "invalid input, please input again.\n";
		//	cin >> num;
		//}

		//display power term
		for (int i = 0; i <= 10; i++)
		{
			cout << num << " raised to the power of " << i << " is " << pow(num, i) << endl;
			//cin.ignore(); //to ignore the newline character
			cout << "Enter Q to quit, enter any other key to continue. ";
			cin >> choice;
			if (choice == 'Q' || choice == 'q')
				break;
		}
		if (choice != 'Q'&&choice != 'q')
			cout << "\nThe calculation is complete\n";
		else
			cout << "You quited the program.\n";
	} while (choice != 'Q'&&choice != 'q');

	return 0;

}