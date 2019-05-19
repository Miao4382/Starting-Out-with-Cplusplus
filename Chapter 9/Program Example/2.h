#include <iostream>

int main()
{
	int* ptr;
	int num = 10;
	ptr = &num;
	
	std::cout << "The address of variable num is: " << ptr << std::endl;
	
	return 0;
}

