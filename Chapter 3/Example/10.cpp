/*//Program 3-10: This program uses a type cast expression to print a character from a number
#include <iostream>
using namespace std;

int main()
{
	int a;
	cout << "You can use this program to look for ASCII table. Simply input the number, the program will tell you the character it represents!\n";
	cout << "Please input a number: ";
	cin >> a;
	cout << "The corresponding character in ASCII table is: " << static_cast<char>(a) << endl;
	return 0;
}*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a;
	a = 1225478;
	cout << static_cast<string>(a);
	return 0;

}

