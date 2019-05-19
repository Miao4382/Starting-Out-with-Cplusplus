//7-10 Creating an ASCII table using ranged for loop
#include <iostream>

int main()
{
	int index[127];
	for (int i = 0; i < 127; i++)
		index[i] = i;

	//print out table head
	std::cout << "ASCII Table\n"
		<< "----------------------\n";

	//use a ranged for loop to create the table
	for (char symbol : index)
		std::cout << "    " << static_cast<int>(symbol) << "           " << symbol << std::endl;

	//print table tail
	std::cout << "----------------------\n";

	//play sound
	for (int i = 0; i <= 5; i++)
	{
		std::cout << static_cast<char>(index[7]) << std::endl;
		std::cin.get();
	}


	return 0;
}