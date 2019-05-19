//5. Body Mass Index
#include <iostream>
using namespace std;
int main()
{
	double weight, height, BMI;
	cout << "Please input your weight and height:";
	cin >> weight >> height;

	BMI = weight * 703 / (height*height);

	if (BMI < 18.5&&BMI>0)
		cout << "You're under weight!\n";
	else if (BMI >= 18.5&&BMI <= 25)
		cout << "You're OK\n";
	else if (BMI > 25)
		cout << "You're overweight!\n";
	else
		cout << "Invalid input!\n";
	return 0;
}