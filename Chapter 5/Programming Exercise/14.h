//14. Student Line Up
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
int main()
{
	//variable definition
	int num;
	std::string front_name="Zzzz", end_name="Aaaa", name;

	//create file stream object and link to txt file
	std::ofstream cout;
	cout.open("D:\\14.txt");

	//input student number and check
	std::cout << "How many students: ";
	std::cin >> num;
	while (num > 25 || num < 1)
	{
		std::cout << "Number of students should be in 1~25. Please input again.\n";
		std::cin >> num;
	}
	std::cin.ignore(); //to ignore the new line character.

	//print table head
	cout << std::setw(19) << "Student Number" << std::setw(14) << "Name\n";
	cout << "-----------------------------------------\n";
	
	//Use loop to input student name
	for (int i = 1; i <= num; i++)
	{
		std::cout << "Please input the name of student " << i << ": ";
		getline(std::cin, name);
		if (name < front_name)
			front_name = name;
		if (name > end_name)
			end_name = name;
		cout << std::setw(13) <<std::right << i <<std::setw(9) << " " << std::setw(25) <<std::left << name << std::endl;
	}

	//print table tail and additional information
	cout << "-----------------------------------------\n";
	cout << "The front line student should be: " << front_name << std::endl;
	cout << "The end line student should be: " << end_name << std::endl;
	cout.close();

	return 0;

}