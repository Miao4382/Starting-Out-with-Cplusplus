//6. Rain or Shine
#include <iostream>
#include<fstream>
#include<iomanip>

void get_data(char weather[][30], int rows);
void calc_weather_num(int weather_num[][3], char weather[][30], int rows);
int highest_rainy(int weather_num[][3], int rows);

int main()
{
	char weather[3][30];
	get_data(weather, 3);

	//define a matrix to store weather number data for each month and each weather type. row-0~2: month, column 0~2: different weather(R C S)
	int weather_num[3][3];
	calc_weather_num(weather_num, weather, 3);

	//find out the month with most rainy days
	int highest_rainy_month;
	highest_rainy_month = highest_rainy(weather_num, 3);

	//writing report//
		//file object
	std::ofstream cout;
	cout.open("D:\\6-report.txt");

		//print original data table
	cout << "The data is:\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			cout << weather[i][j];
			cout << " ";
		}
		cout << std::endl<<std::endl;
	}

		//table head
	cout << "Weather data analysis:\n\n";
	cout << std::setw(8) << "Weather" << std::setw(15) << "June" << std::setw(15) << "July" << std::setw(15) << "August" << std::setw(15) << "Total\n";
	cout << "---------------------------------------------------------------------------\n";
		//table
	for (int column_counter = 0; column_counter < 3; column_counter++)
	{
		int total = 0;
		//write the weather condition
		switch (column_counter)
		{
		case 0: cout << std::setw(8) << "Rainy"; break;
		case 1: cout << std::setw(8) << "Cloudy"; break;
		case 2: cout << std::setw(8) << "Sunny"; break;
		}

		//write the weather days in each month
		for (int row_counter = 0; row_counter < 3; row_counter++)
		{
			cout << std::setw(15) << weather_num[row_counter][column_counter];
			total += weather_num[row_counter][column_counter];
		}

		//write down the total number of days for weather (specified by column number)
		cout << std::setw(15) << total << std::endl;
	}

	//print table tail
	cout << "---------------------------------------------------------------------------\n\n";

	//print out month with highest rainy day
	switch (highest_rainy_month)
	{
	case 0: cout << "June has the highest rainy day.\n"; break;
	case 1: cout << "July has the highest rainy day.\n"; break;
	case 2: cout << "August has the highest rainy day.\n"; break;
	}

	std::cout << "Processing complete, check the reports.\n";

	return 0;
}

//file reading program
void get_data(char weather[][30], int rows)
{
	std::ifstream cin;
	cin.open("D:\\rain or shine.txt");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			cin >> weather[i][j];
			//cin.ignore();
		}
	}

}

//weather number counting program
void calc_weather_num(int weather_num[][3], char weather[][30], int rows)
{
	for (int rows_counter = 0; rows_counter < rows; rows_counter++)
	{
		int rainy_day = 0, cloudy_day = 0, sunny_day = 0;
		//add up number for different weather
		for (int days_counter = 0; days_counter < 30; days_counter++)
		{
			switch (weather[rows_counter][days_counter])
			{
			case 'R': rainy_day++; break;
			case 'C': cloudy_day++; break;
			case 'S': sunny_day++; break;
			}
		}
		//record the weather number into weather number file
		for (int weather_counter = 0; weather_counter < 3; weather_counter++)
		{
			int weather;
			switch (weather_counter)
			{
			case 0: weather = rainy_day; break;
			case 1: weather = cloudy_day; break;
			case 2: weather = sunny_day; break;
			}
			weather_num[rows_counter][weather_counter] = weather;
		}
	}
}

//find month with highest number of rainy days
int highest_rainy(int weather_num[][3], int rows)
{
	int high_month = 0, highest_rain=weather_num[0][0];
	for (int i = 1; i < rows; i++)
	{
		if (highest_rain < weather_num[i][0])
		{
			highest_rain = weather_num[i][0];
			high_month = i;
		}
	}

	return high_month;
}