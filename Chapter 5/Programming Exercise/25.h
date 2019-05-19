//25. Using files-Student Line Up
#include <iostream>
#include<fstream>
#include <string>
int main()
{
	//variable definition
	std::string name, front_line="zzzzz", end_line="AAAAA";
	int count = 0;

	//create a file stream object and connect it to the file containing students name
	std::ifstream cin;
	cin.open("D:\\LineUp.txt");

	//use a while loop to read all student names and decide who will be the front line and end line
	while (getline(cin, name))
	{
		if (name < front_line)
			front_line = name;
		if (name > end_line)
			end_line = name;
		count++;
	}

	std::cout << "There are " << count << " students. \n";
	std::cout << front_line << " will be the frontline. " << end_line << " will be the endline.\n";
	cin.close();

	return 0;

}