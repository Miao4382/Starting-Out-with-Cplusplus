//Program 3-18: Problems exist when using cin to input character data
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string name, city;
	cout << "Please input your city: ";
	getline(cin, city);
	cout << "Excellent! Please input your name: ";
	getline(cin, name);
	cout << "According to your input, your city is: " << city << " , and your name is: " << name << endl;
	return 0;
}