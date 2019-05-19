//Checkpoint 4-31: Re-write program
#include <iostream>
using namespace std;

int main()
{
	int selection;
	cout << "Which formula do you want to see?\n\n";
	cout << "1. Area of a circle\n";
	cout << "2. Area of a rectangle\n";
	cout << "3. Area of a cylinder\n";
	cout << "4. None of them!\n";
	cin >> selection;

	switch (selection)
	{
	case 1:
		cout << "Pi*r^2, where r is the radius.\n";
		break;
	case 2:
		cout << "a*b, where a and b is the length and width of the rectangle.\n";
		break;
	case 3:
		cout << "2*Pi*r^2+h*4*Pi*r, where:\n";
		cout << "r is the radius of the circle of the cylinder.\n";
		cout << "h is the height of the cylinder.\n";
		break;
	case 4:
		cout << "Well okay then, good bye!\n";
		break;
	default:
		cout << "not good with numbers, eh?\n";
	}

	return 0;
}