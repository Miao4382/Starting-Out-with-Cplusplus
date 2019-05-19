#include<iostream>
#include<vector>

void total_average(double rain_fall[], int size);
void find_high_low(double rain_fall[], int size);
void get_data(double rain_fall[], int size);
void get_rank(std::vector<int> &rank, double rain_fall_sort[], double rain_fall[]);

//global constant
const int MONTH = 12;
	
int main()
{
	double rain_fall[MONTH];

	//get data
	get_data(rain_fall, MONTH);

	//calculate total rainfall and average
	total_average(rain_fall, MONTH);

	//find highest and lowest rainfall
	find_high_low(rain_fall, MONTH);
	
	//generate a copy of rain_fall array
	double rain_fall_sort[MONTH];
	for(int i=0;i<MONTH;i++)
		rain_fall_sort[i] = rain_fall[i];
	
	//define a ranking container, and use get_rank function to get the ranking info
	std::vector<int> rank;
	get_rank(rank, rain_fall_sort, rain_fall);
	
	//print out the months, in the order of highest rainfall to lowest rainfall
	for(int i=0;i<MONTH;i++)
	{
		std::cout << "Month " << rank[i]+1 << "  Rainfall: " <<rain_fall[rank[i]] << std::endl;
	}
	std::cout << "\n";
	

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

//generate the rank
void get_rank(std::vector<int> &rank, double rain_fall_sort[], double rain_fall[])
{
	int start_scan = 0;
	do
	{
		double max = rain_fall_sort[start_scan];
		int max_index = start_scan;
		
		//find out the maximum
		for(int i=start_scan;i<MONTH;i++)
		{
			if(max < rain_fall_sort[i])
			{
				max = rain_fall_sort[i];
				max_index = i;
			}
		}
		
		//store max_index in rank
		for(int i=0;i<MONTH;i++)
			if(rain_fall[i] == max)
				rank.push_back(i);
		
		//exchange
		rain_fall_sort[max_index] = rain_fall_sort[start_scan];
		rain_fall_sort[start_scan] = max;
		
		//update start_scan
		start_scan++;
		
	} while (start_scan < MONTH); //rank[] needs to record till the last element, 
								   //so, you can't use start_scan < MONTH-1;
}