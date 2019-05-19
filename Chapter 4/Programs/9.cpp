//Program 4-9: Division by zero
#include <iostream>
using namespace std;

int main()
{
	//variable definition
	double num1, num2;

	//input
	cout << "This program will do division for you, please input dividend: ";
	cin >> num1;
	cout << "Please input dividor: ";
	cin >> num2;

	if (num2)
	{
		cout << "The result is: " << num1 / num2 << endl;
	}
	else
		cout << "Error! The divisor is not supposed to be zero!\n";

	return 0;
}