//23. Pattern Display
#include <iostream>
#include <fstream>
#include <iomanip>
int main()
{
	//create a file stream object
	std::ofstream cout;
	cout.open("D:\\22.txt");

	//print the table head
	cout << "---------------------------------------\n";
	cout << "Pattern A" << std::setw(23) << "Pattern B" << std::endl;
	cout << "---------------------------------------\n";


	//print the table with pattern A and pattern B
	for (int i = 1; i <= 10; i++)
	{
		cout << std::left;
		for(int j=1;j<i;j++)
			cout << "+";
		cout << std::setw(25-i) << "+";
		//cout << std::right;
		for (int k = 1; k <= 11 - i; k++)
			cout << "+";
		cout << std::endl;
	}

	//print the table tail
	cout << "---------------------------------------\n";
	std::cout << "Printing is complete. Please check the file.\n";

	cout.close();
	return 0;
}