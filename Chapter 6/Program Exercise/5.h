//5. Falling Distance
#include <iostream>
#include <fstream>
#include <iomanip>

//function prototype
double falling_distance(double);
void input(double &, double &, double&);
void calculation(double time_min, double time_max, double time_step);

//global constant
const double g = 9.8;

int main()
{
	double time_min, time_max, time_step;
	input(time_min, time_max, time_step);
	std::cout << "Processing...please wait.\n";
	calculation(time_min, time_max, time_step);
	std::cout << "The calculation is finished. Please check the file.\n";
	return 0;
}

//distance calculation function
double falling_distance(double time)
{
	return 1.0/ 2 * g*time*time;
}

//input function
void input(double &time_min, double &time_max, double &time_step)
{
	std::cout << "Please input the minimum time, maximum time and step time of result: ";
	std::cin >> time_min >> time_max >> time_step;
	while (time_min < 0 || time_max < 0 || time_step < 0||time_min>=time_max)
	{
		std::cout << "Invalid input. Time should not be less than zero. Please input again: \n";
		std::cin >> time_min >> time_max >> time_step;
	}
}

//calculation and output function
void calculation(double time_min, double time_max, double time_step)
{
	//create a file streaming object and format it
	std::ofstream cout;
	cout.open("D:\\5.txt");
	cout << std::setprecision(2) << std::fixed;

	//print table head
	cout << "Calculation result\n\n";
	cout << std::setw(14) << "time (s)" << std::setw(22) << "Distance (m)\n"
		<< "--------------------------------------------\n";

	//use a loop to print the calculation result
	for (double i = time_min; i <= time_max; i += time_step)
	{
		cout << std::setw(11) << i << std::setw(22) << falling_distance(i) << std::endl;
	}

	//print table tail
	cout << "--------------------------------------------\n";
}
