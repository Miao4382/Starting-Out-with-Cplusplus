//7.2 Use loop to access array elements

#include <iostream>

int main()
{
	const int size_of_hour = 5;
	int hour[size_of_hour];

	//array input
	for (int i = 0; i < size_of_hour; i++)
	{
		std::cout << "What is the value in element " << i + 1 << ": ";
		std::cin >> hour[i];
	}

	//array out put
	for (int i = 0; i < size_of_hour; i++)
	{
		std::cout << "Element " << i + 1 << " in the array is: " << hour[i] << std::endl;
	}

	return 0;
}