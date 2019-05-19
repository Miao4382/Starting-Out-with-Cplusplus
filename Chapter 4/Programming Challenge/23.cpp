//23. Geometry Calculator
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	//variable definition
	int selection;

	//selection
	cout << "Geometry Calculator\n";
	cout << "\t1. Calculate the Area of a Circle\n";
	cout << "\t2. Calculate the Area of a Rectangle\n";
	cout << "\t3. Cauclate the Area of a Triangle\n";
	cout << "\t4. Quit\n";
	cin >> selection;
	switch (selection)
	{
	case 1:
		{
			double radius, area;
			const double PI = 3.14159;
			cout << "What is the radius of the circle?\n";
			cin >> radius;
			if (radius >= 0)
			{
				area = PI*radius*radius;
				cout << "The area is: " << area << endl;
			}
			else
				cout << "Invalid radius input.\n";
			break;
		}
	case 2:
		{
			double length, width, area;
			cout << "What is the length and width of the rectangle?\n";
			cin >> length >> width;
			if (length >= 0 && width >= 0)
			{
				area = length*width;
				cout << "The area is " << area << endl;
			}
			else
				cout << "Invalid data input.\n";
			break;
		}

	case 3:
		{
			double base, height, area;
			cout << "What is the base and height of the triangle?\n";
			cin >> base >> height;
			if (base >= 0 && height >= 0)
			{
				area = base*height*0.5;
				cout << "The area is " << area << endl;
			}
			else
				cout << "Invalid data input.\n";
			break;
		}
	case 4:
		{
			cout << "You quited the program.\n";
			break;
		}
	default:
		{
			cout << "Invalid selection! You should select 1 through 4.\n";
			break;
		}
	}
	return 0;
}