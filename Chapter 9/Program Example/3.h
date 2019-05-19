#include <iostream>

int main()
{
	double num = 250.09;
	double* ptr_double = nullptr; //define and initialize a pointer
	ptr_double = &num; //assign the memory address of variable num to pointer ptr_double
	*ptr_double += 1; //dereference the pointer, and operate on the dereferenced pointer
	std::cout << "After operation: " << num << " " << *ptr_double << ". The memory address is: ";
	std::cout << ptr_double << std::endl;
	
	return 0;
	
}
