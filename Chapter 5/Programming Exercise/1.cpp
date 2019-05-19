//1. Sum of Numbers
#include<iostream>
#include<fstream>
int main()
{
	//variable definition
	int num, total = 0;
	int i;
	std::ofstream output;
	output.open("D:\\summation.txt");

	//input information
	std::cout << "Please input a positive number to do calculation:\n";
	std::cin >> num;

	//input validity 
	while (num <= 0)
	{
		std::cout << "Invalid input, please input again.\n";
		std::cin >> num;
	}
	
	//use for loop to calculate the summation
	for (i = 1; i < num; i++)
	{
		output << i << " + ";
		total += i;
	}
	total += i;
	output << i << " = " << total << std::endl;
	std::cout << "Summation completed.\n";
	output.close();
	return 0;

}