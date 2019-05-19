//25. Show reference variable
#include <iostream>
void double_number(int &);
int main()
{
	int num = 2;
	double_number(num);
	std::cout << "The number becomes " << num << std::endl;
	//std::cout << num1 << "\n";
	return 0;
}

void double_number(int &num1)
{
	num1 *= 2;
}