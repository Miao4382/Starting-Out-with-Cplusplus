//13. The Greatest and Least of These
#include <iostream>
#include <fstream>
int main()
{
	//variable definition
	int N_max=0, N_min=0, num=0;

	//create a file stream object
	std::ofstream cout;
	cout.open("D:\\13.txt");

	//print out information in txt file
	cout << "The numbers user inputed are:\n";

	//a loop to compare numbers
	std::cout << "Please input your number. Input -99 to terminate.\n";
	while (num != -99)
	{
		std::cin >> num;
		if (num > N_max)
			N_max = num;
		if (num < N_min)
			N_min = num;
		cout << num << "\n";
	}
	std::cout << "Input ended. The data has been successfully transferred to the txt file.\n";
	cout << "------\n";
	cout << "The highest number is: " << N_max << "\n";
	cout << "The lowest number is: " << N_min << "\n";
	cout.close();

	return 0;
}