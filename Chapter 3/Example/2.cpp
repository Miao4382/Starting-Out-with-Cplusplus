/* Program 3.2
This program asks the user toenter the length and width of a rectangle.
It calculates the rectangle's area and displays the value on the screen.
This program is slightly different from program 3.1, because the cin will
read data of length and width at the same time */

#include <iostream>
using namespace std;

int main()
{
	double length, width, area;

	cout << "What is the length and width of the rectangle? Please input the value of "
		<< "length first, press [Enter], and then input the value of width, then "
		<< "press [Enter] again.\n";
	cin >> length >> width;
	
	area = length*width;

	cout << "According to your input, the area of the rectangle is: " << area << endl;
	return 0;
}