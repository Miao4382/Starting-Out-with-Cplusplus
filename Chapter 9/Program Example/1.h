#include <iostream>

int main()
{
	int x;
	std::cout << "Before assigning value, the address of x is: " << &x << std::endl;
	x = 2;
	std::cout << "After assigning the value, the address of x is: " << &x << std::endl;

	return 0;
}