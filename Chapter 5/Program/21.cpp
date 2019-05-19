//program 5-21: record sales data
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	//define variable day to hold the total number of days
	int day;

	//define file stream object, and link to "Sales Data.txt" file
	ofstream output;
	output.open("C:\\users\\my\\desktop\\Sales Data.txt");

	//ask for the number of days
	cout << "How many days of data you're going to input?";
	cin >> day;

	//Wrtie table titel in the file
	output << "The sales data for " << day << " days are as follows:\n\n";
	output << "Day\t\tSales\n";
	output << "--------------------\n";

	//define a variable to hold sales, and use a for loop to input data
	double sales;
	for (int i = 1; i <= day; i++)
	{
		cout << "What is the sales for day " << i << ": ";
		cin >> sales;
		output << i << "\t\t" << sales << endl;
	}

	//finish the table
	output << "--------------------\n";
	output.close();
	cout << "Input complete\n";

	return 0;


}