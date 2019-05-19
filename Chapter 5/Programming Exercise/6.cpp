//6. Distance Traveled
#include<fstream>
#include<iostream>
#include<iomanip>
int main()
{
	//variable definition
	double time, distance, speed;
	int time_int;

	//enable file stream object
	std::ofstream cout;
	cout.open("D:\\6.txt");

	//Data input: speed & validity check
	std::cout << "What is the speed of the vehicle in mph: ";
	std::cin >> speed;
	while (speed <= 0)
	{
		std::cout << "The speed of the vehicle should be greater than zero, please input again: ";
		std::cin >> speed;
	}

	//Data input: time & validity check
	std::cout << "How many hours has it traveled? ";
	std::cin >> time;
	while (time < 1)
	{
		std::cout << "You should enter a value greater than 1 hour, please input again: ";
		std::cin >> time;
	}

	//Show processing information
	std::cout << "The program is processing, please wait...\n";

	//write the table head
	cout << "  Hour" << std::setw(20) << "Distance Traveled\n";
	cout << "--------------------------------\n";
	cout.fill(0);
	//Pass the integer section of time to time_int, and print out the integer part
	time_int = time;
	for (int i = 1; i <= time_int; i++)
		cout << std::setw(4) << i << std::setw(13) << i*speed << std::endl;

	//Calculate the total time if the time is not integer, write to the last row
	if(time!=time_int)
		cout << std::setw(4) << time << std::setw(13) << time*speed << std::endl;

	//finish table and notification of completion
	cout << "--------------------------------\n";
	std::cout << "The calculation is done. Please check the file.\n";

	return 0;

}