//22. Square Display
#include <iostream>
#include <fstream>
int main()
{
	//create the file stream object and link to the file
	std::ofstream cout;
	cout.open("D:\\22.txt");

	//variable definition
	int length;

	//intput the length
	std::cout << "Please input the length of the square: (do not accept numbers smaller than 0 and larger than 15\n";
	std::cin >> length;
	while (length > 15 || length <= 0)
	{
		std::cout << "The length should be in the range of (0,15]. Please input again:";
		std::cin >> length;
	}

	//print out the square
	for (int i = 1; i <= length; i++)
	{
		for (int j = 1; j <= length; j++)
		{
			cout << "X";
		}
		cout << std::endl;
	}

	//show complete information
	std::cout << "The processing is complete. Please check the txt file.\n";

	cout.close();
	return 0;
}