//Program 15: First time using logical operator
#include <iostream>
using namespace std;

int main()
{
	//variable definition
	char recent_grad, empoly;

	//input information
	cout << "Are you employed? Please input Y for yes, N for no: ";
	cin >> empoly;
	cout << "Are you graduated in last two years? Please input Y for yes\n";
	cout << "N for no: ";
	cin >> recent_grad;

	//condition check
	if (recent_grad == 'Y' && empoly == 'Y')
		cout << "Congratulations! You are qualified for the loan.\n";
	else if (recent_grad == 'Y' && empoly == 'N')
		cout << "You are not qualified because you are not employed.\n";
	else if (recent_grad == 'N' && empoly == 'Y')
		cout << "You are not qualified because you are not graduated in\n"
		<< "last two years.\n";
	else if (recent_grad == 'N' && empoly == 'N')
		cout << "You are not qualified because you are not empolyed, and\n"
		<< "You are not graduated in past two years.\n";

	return 0;
}