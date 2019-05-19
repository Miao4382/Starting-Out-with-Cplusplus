// Checkpoint 3-12
#include <iostream>
using namespace std;

int main()
{
	char letter;

	cout << "This program will tell you the ASCII code for the character you enter.\n";
	cout << "Please enter a character: ";
	cin >> letter;
	cout << "The ASCII code for \"" << letter << "\" is: " << static_cast<int>(letter);
	cout << endl;
	return 0;
}