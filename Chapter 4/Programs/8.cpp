//Program 8: First meet if/else
#include <iostream>
using namespace std;

int main()
{
	//variable definition
	int num;

	//input
	cout << "Please input a number, this program will tell you if this\n"
		<< " is odd number or even number: \n";
	cin >> num;

	//output
	cout << "You inputed: " << num << endl;
	if (num % 2)
		cout << "This is an odd number.\n";
	else
		cout << "This is an even number.\n";

	return 0;
}