//7.3 Read data from a file into an array, and create a new file (copy)
#include <iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib>

int main()
{
	std::string data[500];
	int line_counter = 0;

	//create a file stream object: read
	std::ifstream cin;
	cin.open("D:\\Travel Expense Report.txt");

	//read each line in the report and store in every element of data array, until no new line is read
	while (getline(cin, data[line_counter]))
		line_counter++;
	cin.close();

	//create a new file stream object to write data into
	std::ofstream cout;
	cout.open("D:\\Travel Expense Report-2.txt");

	//create a set of random numbers
	int seed;
	seed = time(0);
	srand(seed);

	//write the content in each element in data array to a new file
	for (int i = 0; i <= line_counter; i++)
		cout << data[(rand()%(line_counter+1))] << std::endl;
	cout.close();

	//user notice
	std::cout << "Duplication complete!\n";

	return 0;

}
