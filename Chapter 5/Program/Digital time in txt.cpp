//This program writes all possible digit time on a text file
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int hour, min, second;
	ofstream output("Digital time.txt");
	output.fill('0');
	for (hour = 0; hour <= 23; hour++)
	{
		for (min = 0; min <= 59; min++)
		{
			for (second = 0; second <= 59; second++)
			{
				output << setw(2) << hour << ":" << setw(2) << min << ":" << setw(2) << second << endl;
			}
		}
	}
	output.close();
	//output.open("C:\\Users\\My\\Desktop\\hahaha.txt");
	output.open("C:\\hahaha.txt");
	output << "you can't input now\n";
	output.close();
	cout << "The printing is complete, please check out.\n";

	return 0;
}