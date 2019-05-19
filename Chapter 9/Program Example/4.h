#include <iostream>

int main()
{
	int num1 = 10, num2 = 25;
	int* ptr = nullptr;
	
	std::cout << "Before operating: " << num1 << " " << num2 << std::endl;
	ptr = &num1; //link pointer to num1
	*ptr += 5; //operate the value stored in the memory address pointer points to
	ptr = &num2; //disconnect pointer with num1, re-link to num2
	*ptr -= 5;
	std::cout << "After operating: " << num1 << " " << num2 << std::endl;
	
	return 0;
}
