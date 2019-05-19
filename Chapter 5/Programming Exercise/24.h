//24. Using Files-Numeric Processing
#include <iostream>
#include <fstream>
int main()
{
	unsigned long long total=0, num, count=0;
	double average;

	//create a file stream object
	std::ifstream cin;
	cin.open("D:\\random.txt");

	//use a loop to read all the number in the file. Calculate the total count of the number and the total
	while (cin >> num)
	{
		total += num;
		count++;
	}

	//calculate the average
	average = static_cast<double>(total) / count;

	//display on screen
	std::cout << "There are " << count << " numbers in the file.\n";
	std::cout << "The sum of all numbers are: " << total << std::endl;
	std::cout << "The average of all numbers are " << average << std::endl;

	cin.close();
	return 0;
}