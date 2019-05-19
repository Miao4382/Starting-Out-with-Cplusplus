//4. Calories Burned
#include<fstream>
#include<iostream>
#include<iomanip>
int main()
{
	//define the rate constant
	const double BURN_RATE = 3.6;

	//initialize the file stream object
	std::ofstream cout;
	cout.open("D:\\4.txt");

	//print out the table head
	cout << "Minutes" << std::setw(20) << "Calories Burned\n";
	cout << "---------------------------\n";
	cout.fill(' ');

	//use loop to write table into the file
	for (int i = 5; i <= 30; i += 5)
	{
		cout << std::right << std::setw(3) << i << std::setw(12) << " " << std::left << i*BURN_RATE << std::endl;
	}

	//write the table tail
	cout << "---------------------------\n";

	//notify completion
	std::cout << "Table was successfully written into the file.\n";
	cout.close();
	return 0;
}