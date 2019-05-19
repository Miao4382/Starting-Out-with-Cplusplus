//7-9 Partially initialize array
#include<iostream>
#include<string>
#include<fstream>
int main()
{
	std::string part[3] = { "the first line", "the second line" };
	int num[3] = { 1, 2 };
	char charac[3] = { 'A', 'b' };

	std::cout << "The arrays are partially initialized, the un-initialized element is written to file\n";
	
	std::ofstream cout("D:\\7-9.txt");

	cout << "String array:\t" << part[2] <<part[2] << std::endl;
	cout << "Integer array:\t" << num[2] << std::endl;
	cout << "Character array:\t" << charac[2] << std::endl;
	cout.close();

	return 0;
}