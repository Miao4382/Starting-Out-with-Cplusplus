//9. Demonstrate the change of parameter's value doesn't affect the argument
//inside the function call
#include <iostream>
double increment(double);
int main()
{
	double i = 1,result;
	result=increment(i);
	std::cout << "i = " << i << "\n";
	std::cout << "increment(i) = " << result << std::endl;
	return 0;
}

double increment(double num)
{
	num++;
	//return num;
	return num++;
}