//17. Personal Best
#include <iostream>
#include <string>
using namespace std;
int main()
{
	//variable definition
	string name;
	double height1, height2, height3;
	string date1, date2, date3;

	//program input
	cout << "What is the name of the athlete: ";
	getline(cin, name);
	cout << "What is the height for the first record: ";
	cin >> height1;
	cin.ignore();
	cout << "What is the date for the first record: ";
	getline(cin, date1);
	cout << "What is the height for the second record: ";
	cin >> height2;
	cin.ignore();
	cout << "What is the date for the second record: ";
	getline(cin, date2);
	cout << "What is the height for the third record: ";
	cin >> height3;
	cin.ignore();
	cout << "What is the date for the third record: ";
	getline(cin, date3);


	//valid check
	if (height1 >= 2 && height1 <= 5 && height2 >= 2 && height2 <= 5 && height3 >= 2 && height3 <= 5)
	{
		double max, mid, min;
		string max_date, mid_date, min_date;
		
		//determine the maximum
		max = height1; max_date = date1;
		if (max > height2);
		else
		{
			max = height2; max_date = date2;
		}
		if (max > height3);
		else
		{
			max = height3; max_date = date3;
		}

		//determine the minimum
		min = height1; min_date = date1;
		if (min < height2);
		else
		{
			min = height2; min_date = date2;
		}
		if (min < height3);
		else
		{
			min = height3; min_date = date3;
		}

		//determine the medium
		mid = height1; mid_date = date1;
		if ((mid - max)*(mid - min) < 0);
		else
		{
			mid = height2; mid_date = date2;
		}
		if ((mid - max)*(mid - min) < 0);
		else
		{
			mid = height3; mid_date = date3;
		}

		//Output
		cout << "The record table is shown below:\n";
		cout << "Name:\t\t" << name << endl;
		cout << "Record\t\tDate\n";
		cout << "_________________________\n";
		cout << max << "\t\t" << max_date << endl;
		cout << mid << "\t\t" << mid_date << endl;
		cout << min << "\t\t" << min_date << endl;
		
	}
	else
	{
		cout << "The height range is 2.0 ~ 5.0 meters. Please check your input.\n";
	}
	return 0;
	
}