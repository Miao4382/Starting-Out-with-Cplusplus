//18. Population Bar Chart
#include<fstream>
#include<iostream>
int main()
{
	//variable definition
	int num, year, num_asterisk;

	//create file stream objects: reading and writting
	std::ifstream cin;
	cin.open("D:\\People.txt");
	std::ofstream cout;
	cout.open("D:\\18.txt");

	//write a titel for the bar chart
	cout << "PRAIRIEVILLE POPULATION GROWTH\n";
	cout << "(each * represents 1,000 people)\n";

	//use a while loop to read values in the file, and write a bar chart in the output file. The while loop can also detect the end of the file.
	while (cin >> year)
	{
		cout << year << " ";
		cin.ignore();
		cin >> num;
		num_asterisk = num / 1000;
		//draw the asterisk
		for (int i = 1; i <= num_asterisk; i++)
			cout << "*";
		cout << std::endl;
	}

	//print out complete information
	std::cout << "Drawing complete, please check the txt file for result.\n";

	//disconnect from files
	cin.close();
	cout.close();
	return 0;
}