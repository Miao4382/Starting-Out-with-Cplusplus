//15. Bool function: isEven
#include<iostream>
bool isEven(int);
int main()
{
	int num;
	std::cout << "Please input a number: ";
	std::cin >> num;
	if (num == 0)
		std::cout << "You can't input zero.\n";
	else if (isEven(num))
		std::cout << "This number is even number.\n";
	else
		std::cout << "This number is not even number.\n";
	return 0;
}

bool isEven(int num)
{
	if (num % 2 != 0)
		return false;
	else
		return true;
}