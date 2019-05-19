//23. Initialize static variable
#include <iostream>
void show_static();
int main()
{
	for (int count = 0; count <= 5; count++)
		show_static();
	return 0;
}

void show_static()
{
	static int num=1;
	std::cout << "The number is: " << num++ << std::endl;
}