//26. Continue working reference variable
#include <iostream>
void get_num(double &);
void double_num(double &);
int main()
{
	double value;
	get_num(value);
	double_num(value);
	std::cout << "The doubled value is: " << value << std::endl;
	return 0;
}

void get_num(double &num)
{
	std::cout << "Please input a number: ";
	std::cin >> num;
}

void double_num(double &num)
{
	num *= 2;
}