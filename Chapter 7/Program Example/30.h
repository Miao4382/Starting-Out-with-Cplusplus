//7-30. Use Clear Function
#include<iostream>
#include<vector>

int main()
{
	std::vector<int> num(100);

	std::cout << "Before clearing, the size of the vector is: " << num.size() << std::endl;

	num.clear();

	std::cout << "After clearing, the size of the vector is: " << num.size() << std::endl;

	return 0;
}