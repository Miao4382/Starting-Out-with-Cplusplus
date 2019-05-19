//12. Celsius to Fahrenheit Table
#include <iostream>
#include <fstream>
#include <iomanip>
int main()
{
	/*
	F:	Fahrenheit temperature
	C_min:	Lower range of Celsius temperature
	C_max:	Upper range of Celsius temperature
	C_max_int:	to store the integer value of Celsius temperature
	*/
	double F, C_min, C_max;
	int C_max_int;

	//create a file stream object
	std::ofstream cout;
	cout.open("D:\\12.txt");
	
	//data input: the temperature range
	std::cout << "Input the lowese Celsius temperature in your table: ";
	std::cin >> C_min;
	std::cout << "Input the highest Celsius temperature in your table: ";
	std::cin >> C_max;
	C_max_int = C_max;

	//show processing information
	std::cout << "Processing...please wait.\n";

	//print table head
	cout << std::left << std::setw(25) << "Celsius Temperature" << "Fahrenheit Temperature\n";
	cout << "------------------------------------------------\n";

	//use loop to calculate the table
	for (double i = C_min; i <= C_max_int; i += 0.5)
	{
		F = 1.8*i + 32;
		cout << std::right << std::setw(11) << i;
		cout << std::setw(28) << F << "\n";
	}

	//print out the C_max, if C_max_int != C_max
	if (C_max_int != C_max)
		cout << std::setw(11) << C_max << std::setw(28) << 1.8*C_max + 32 << "\n";

	//print table tail
	cout << "------------------------------------------------\n";

	//show complete information
	std::cout << "Processing complete, please check the file.\n";

	cout.close();
	return 0;

}