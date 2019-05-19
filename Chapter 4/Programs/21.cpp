//Program 4-21: This program uses relational operators to compare a string
//entered by user with valid stereo part number
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	//variable definition
	const string PART_BOX = "S-29A", PART_SHELF = "S-28B";
	const double PRICE_BOX = 129, PRICE_SHELF = 199;
	string part_num;

	//input choice
	cout << "Please input the part number, program will show the price\n";
	cin >> part_num;
	if (part_num == PART_BOX || part_num=="s-29a")
		cout << "The part is box, with a price of $" << PRICE_BOX << endl;
	else if (part_num == PART_SHELF || part_num=="s-28b")
		cout << "The part is shelf, with a price of $" << PRICE_SHELF << endl;
	else
		cout << "You inputed a invalid part number.\n";

	return 0;

}