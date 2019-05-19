//Minimum/Maximum
#include <iostream>
using namespace std;

int main()
{
	double num1, num2;
	cout << "Please input two numbers, I will compare them to tell which is bigger.\n";
	cin >> num1 >> num2;
	cout << (num1 > num2 ? num1 : num2) << " is bigger.\n";
	return 0;

}