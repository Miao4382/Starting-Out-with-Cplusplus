//Program 4-20: Show characters can be compared with the relational operators
#include <iostream>
using namespace std;

int main()
{
	char ch;

	//input a letter
	cout << "Please input a letter, I'll determine what type of data you input\n";
	ch = cin.get();

	if (ch >= '0'&&ch <= '9')
		cout << "You inputed a digit\n";
	else if (ch >= 'A'&&ch <= 'Z')
		cout << "You inputed a upper case letter\n";
	else if (ch >= 'a'&&ch <= 'z')
		cout << "You inputed a lower case letter\n";
	else
		cout << "You didn't input any digit or letter, maybe symbols?\n";

	return 0;
}