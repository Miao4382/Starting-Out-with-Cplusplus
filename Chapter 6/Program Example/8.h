//8. Multiple parameters (so multiple arguments can be sent to the function
#include <iostream>
double average(double num1, double num2, double num3); //function prototype
int main()
{
	double num1, num2, num3;
	std::cout << "Please input three numbers and I'll average them for you.\n";
	std::cin >> num1 >> num2 >> num3;
	std::cout << "The average is: " << average(num1, num2, num3) << std::endl;
}

double average(double num1, double num2, double num3)
{
	double average;
	average = (num1 + num2 + num3) / 3;
	return average;
}