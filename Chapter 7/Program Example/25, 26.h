//7-25, 26. Use Range-Based for Loop both reference variable and un-referenced variable
#include <vector>
#include<iostream>

int main()
{
	std::vector<int> num{ 1,2,3,4,5,6,7 };

	for (auto &number : num)
	{
		number *= 2;
	}

	for(int number:num)
		std::cout << number << std::endl;

	return 0;
}