//2. Characters for the ASCII Codes
#include<fstream>
#include<iostream>
int main()
{
	std::ofstream cout;
	cout.open("D:\\2.txt");

	for (int i = 1; i <= 127; i++)
	{
		cout << static_cast<char>(i) << " ";
		if (i % 16 == 0)
			cout << std::endl;
	}
	std::cout << "Printing completed. Please check file.\n";
	cout.close();
	return 0;
}