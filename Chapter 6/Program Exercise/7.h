//7. Celsius Temperature Table
#include <iostream>
#include <iomanip>
#include <fstream>

double celsius(double temperature_F);

int main()
{
	//welcome information
	std::cout << "This program will produce a Fahrenheit-Celcius temperature look up table. Please enter to continue.\n";
	std::cin.get();
	
	//create a file streaming object
	std::ofstream cout("D:\\7.txt");
	cout << std::setprecision(2) << std::fixed;

	//print the table head
	cout << "**Temperature Lookup Table**\n\n"
		<< "  Temperature in            Temperature in\n"
		<< "     Fahrenheit                 Celsius\n"
		<< "-----------------------------------------------\n";

	//use a loop to produce the table
	for (double temperature_F = 0; temperature_F <= 20; temperature_F++)
	{
		cout << std::setw(14) << temperature_F << std::setw(25) << celsius(temperature_F) << std::endl;
	}

	//print the table tail
	cout << "-----------------------------------------------\n";
	cout.close();
	std::cout << "Process complete, please check the file.\n";

	return 0;
}

//converting function
double celsius(double temperature_F)
{
	return 5.0 / 9 * (temperature_F - 32);
}