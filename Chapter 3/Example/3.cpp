/*This program shows how cin can read multiple values of different data types*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int whole;
	double fractional;
	char character;
	string words, sentence="sdasd asdw awd asd";

	cout << "Please input a integer, fractional number, a character and several words:\n";
	cin >> whole >> fractional >> character >> words;
	cout << "Whole number: " << whole << endl
		<< "Fractional number: " << fractional << endl
		<< "Character: " << character << endl
		<< "A string of words: " << words << endl;
	cout << "\nPlease input a sentence, including blanks!\n";
	cin >> sentence;
	cout << "The sentence you just input is: " << sentence << endl;
	cout << "If you see only one word was recorded, it means by this way cin object can't record string!\n";
	return 0;
}