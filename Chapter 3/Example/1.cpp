/* Program 3.1
This program asks the user toenter the length and width of a rectangle.
It calculates the rectangle's area and displays the value on the screen. */

#include <iostream>
using namespace std;

int main()
{
	double length, width, area;
	cout << "This program calculates the area of a rectangle.\n\n";
	cout << "What is the length of the rectangle?\n";
	cin >> length;
	cout << "What is the width of the rectangle?\n";
	cin >> width;

	area = length*width;

	cout << "The area of the rectangle is: " << area << endl;
	return 0;

}