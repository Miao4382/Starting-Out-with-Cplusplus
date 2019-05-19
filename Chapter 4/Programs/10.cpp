//Program 4-10: First meet nested if statement
#include <iostream>
using namespace std;

int main()
{
	//variable definition
	char employ_status, recent_grad;

	//input the customer's status
	cout << "Are you employed? If yes, please input Y, if no, please \n"
	 	 << "input N.\n";
	cin >> employ_status;

	//fisrt check if the customer is employed
	if (employ_status == 'Y')
	{
		cout << "Good! Second question, are you graduated in last two \n"
			<< "years? If yes, please input Y, if no, please input N.\n";
		cin >> recent_grad;
		if (recent_grad == 'Y')
			cout << "Congratulations! You're qualified!\n";
		else
			cout << "Sorry, you're not qualified because you were not \n"
			<< "graduated in last two years.\n";
	}
	else
		cout << "Sorry, you're not qualified because you are not employed.\n";

	return 0;
	
}