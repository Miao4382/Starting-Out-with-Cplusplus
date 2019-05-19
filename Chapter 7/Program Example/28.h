//7-28. Vector can show its size
#include<iostream>
#include<vector>

void show_value(std::vector<int>);

int main()
{
	std::vector<int> num;

	for (int i = 0; i < 10; i++)
		num.push_back(i * 2);

	show_value(num);

	return 0;
}

//function definition: show_value
void show_value(std::vector<int> set)
{
	for (int i = 0; i < set.size(); i++)
		std::cout << set[i] << std::endl;
}