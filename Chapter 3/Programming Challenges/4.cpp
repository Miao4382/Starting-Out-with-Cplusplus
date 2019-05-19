//4. Average Rainfall
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	string month1, month2, month3;
	double rain1, rain2, rain3, rain_average;
	cout << setprecision(2) << fixed;
	cout << "Please input the name of first month and its rainfall, separate by a space: \n";
	cin >> month1 >> rain1;
	cout << "Please input the name of second month and its rainfall, separate by a space: \n";
	cin >> month2 >> rain2;
	cout << "Please input the name of third month and its rainfall, separate by a space: \n";
	cin >> month3 >> rain3;
	rain_average = (rain1 + rain2 + rain3) / 3;
	cout << "The average rainfall for " << month1 << ", " << month2 << " and " << month3
		<< " is: " << rain_average << " inches.\n";
	return 0;
}