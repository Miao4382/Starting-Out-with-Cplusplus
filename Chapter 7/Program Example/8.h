//7.8, ASCII code and letter
#include<string>
#include<iostream>
#include<iomanip>
int main()
{
	int chara[5] = { 'A', 'B', 'C', 'D', 'E' };

	//print out table head
	std::cout << "Character             ASCII Code\n"
		<< "----------            ------------\n";

	for (int i = 0; i < 5; i++)
	{
		std::cout << std::setw(5) << static_cast<char>(chara[i]) << std::setw(23) << chara[i] << std::endl;
	}

	std::cout << "----------            ------------\n\n";

	return 0;
}