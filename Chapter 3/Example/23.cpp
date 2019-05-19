//Program 3-23: use cin.ignore to ignore the \n space
#include <iostream>
using namespace std;

int main()
{
	char ch;
	int num;
	cout << "Please input the number: ";
	cin >> num;
	cin.ignore(200, '\n');
	cout << "Please input the character: ";
	ch = cin.get();
	cout << "Thank you. According to your input, the number you input is: " << num << ". And the character you input is: " << ch << endl;
	return 0;
}

//Program 3-33: mixing cin and cin.get
#include <iostream>
using namespace std;

int main()
{
	double num;
	char ch;
	cout << "Please input a number: ";
	cin >> num;
	cin.ignore(100, '\n');
	cout << "Please input a character: ";
	ch = cin.get();
	cout << "The number you input is: " << num;
	cout << "\nThe character you input is: " << ch << endl;
	return 0;
}




//Test the length of string function
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string sent, sent2;
	cout << "This program will calculate how many characters you input! Please input a sentence: \n";
	getline(cin, sent);
	int num = sent.length();
	cout << "\nYour input contains: " << num << " characters! \n";
	cout << "Now, please type in another sentence, I'll combine them for you!\n";
	getline(cin, sent2);
	sent += sent2;
	cout << "The combination is as follows: " << sent << endl;
	return 0;
}




