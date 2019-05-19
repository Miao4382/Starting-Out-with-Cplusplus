//7-29. Demonstrate the effect of pop_back function
#include<iostream>
#include<vector>

int main()
{
	std::vector<int> num;

	//initialize a vector
	for (int i = 0; i < 10; i++)
		num.push_back(i * 3);

	//print out the vector before pop back
	for (int i = 0; i < num.size(); i++)
		std::cout << num[i] << std::endl;

	//delete three elements from num
	for (int i = 0; i < 3; i++)
		num.pop_back();

	//print again
	std::cout << "After pop_back three times:\n";
	for (int i = 0; i < num.size(); i++)
		std::cout << num[i] << std::endl;

	return 0;

}