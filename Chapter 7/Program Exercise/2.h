//2. Rainfall Statistics
#include<iostream>

void total_average(double rain_fall[], int size);
void find_high_low(double rain_fall[], int size);
void get_data(double rain_fall[], int size);

int main()
{
	const int MONTH = 12;
	double rain_fall[MONTH];

	//get data
	get_data(rain_fall, MONTH);

	//calculate total rainfall and average
	total_average(rain_fall, MONTH);

	//find highest and lowest rainfall
	find_high_low(rain_fall, MONTH);

	return 0;
}

//calculate total and average of the data
void total_average(double rain_fall[], int size)
{
	double total = 0;
	for (int i = 0; i < size; i++)
	{
		total += rain_fall[i];
	}

	//display total and average
	std::cout << "The total rainfall is: " << total << "\n";
	std::cout << "The average rainfall is: " << total / size << "\n";

}

//find highest and lowest
void find_high_low(double rain_fall[], int size)
{
	double high, low;
	int high_month, low_month;
	high = rain_fall[0];
	high_month = 1;
	low = rain_fall[0];
	low_month = 1;

	for (int i = 1; i < size; i++)
	{
		if (high < rain_fall[i])
		{
			high = rain_fall[i];
			high_month = i + 1;
		}

		if (low > rain_fall[i])
		{
			low = rain_fall[i];
			low_month = i + 1;
		}

	}
	
	//display result
	std::cout << "The highest rainfall is in month " << high_month << ", with a rainfall of " << high << "\n";
	std::cout << "The lowest rainfall is in month " << low_month << ", with a rainfall of " << low << "\n";

}

//data input program
void get_data(double rain_fall[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "What is the rainfall for month " << i + 1 << ": ";
		std::cin >> rain_fall[i];
		while (rain_fall[i] < 0)
		{
			std::cout << "Please input rainfall data greater than zero: ";
			std::cin >> rain_fall[i];
		}
	}
}