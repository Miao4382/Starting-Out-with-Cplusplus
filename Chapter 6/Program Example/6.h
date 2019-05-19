//6. Make function with parameters
#include <iostream>
double time2(double,int);
int main()
{
	double a;
	int exponential;
	std::cout << "Input a number: ";
	std::cin >> a;
	std::cout << "Input the power you want rise the numerber to: ";
	std::cin >> exponential;
	std::cout << "The result is: " << time2(a, exponential) << std::endl;
	return 0;
}

double time2(double num, int power)
{
	double result = 1;
	if (power > 0)
	{
		for (int i = 1; i <= power; i++)
			result *= num;
	}
	else if (power < 0)
	{
		for (int i = 1; i <= -power; i++)
			result *= num;
		result = 1 / result;
	}
	else;

	return result;

}