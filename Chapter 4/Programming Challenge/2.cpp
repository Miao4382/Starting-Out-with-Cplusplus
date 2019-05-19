//Roman Numeral Converter
#include <iostream>
using namespace std;

int main()
{
	int num;
	cout << "Please input a number within the range of 1 to 10, \n";
	cout << "This program will help you to convert it to Roman number.\n";
	cin >> num;

	switch (num)
	{
	case 1:
		cout << "The corresponding Roman number is I\n";
		break;
	case 2:
		cout << "The corresponding Roman number is II\n";
		break;
	case 3:
		cout << "The corresponding Roman number is III\n";
		break;
	case 4:
		cout << "The corresponding Roman number is IV\n";
		break;
	case 5:
		cout << "The corresponding Roman number is V\n";
		break;
	case 6:
		cout << "The corresponding Roman number is VI\n";
		break;
	case 7:
		cout << "The corresponding Roman number is VII\n";
		break;
	case 8:
		cout << "The corresponding Roman number is VIII\n";
		break;
	case 9:
		cout << "The corresponding Roman number is IX\n";
		break;
	case 10:
		cout << "The corresponding Roman number is X\n";
		break;
	default:
		cout << "Do not accept character other than number from 1 to 10.\n";

	}
	return 0;
}