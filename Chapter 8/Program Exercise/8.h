#include <iostream>
#include <ctime>
#include <cstdlib>

const int NUM=100000, N_MIN=1, N_MAX=10000;

void random_creater(int num[]);
int linear_search(int num[], int value);
void selection_sort(int num[]);
int binary_search(int num[], int value);

int main()
{
	//create a random integer array
	int num[NUM];
	random_creater(num);
	
	//input search value
	std::cout << "Input a value to search: ";
	int value;
	std::cin >> value;
	
	//before sorting, use linear search function to search, and record number of comparisons
	int linear_benchmark;
	linear_benchmark = linear_search(num, value);
	
	//sort the array so a binary search can be used. Use a selection sorting technique
	selection_sort(num);
	
	//call binary search function to search, record number of comparisons
	int binary_benchmark;
	binary_benchmark = binary_search(num, value);
	
	//print out the benchmark, if the value is found
	if(linear_benchmark)
	{
		std::cout << "Linear search benchmark: " << linear_benchmark << std::endl
			  << "Binary search benchmark: " << binary_benchmark << std::endl;
	}
	else
		std::cout << "The value is not in the list.\n";
	
	return 0;
}

void random_creater(int num[])
{
	int seed;
	seed = time(0);
	srand(seed);

	for (int i = 0; i<NUM; i++)
		num[i] = rand() % (N_MAX - N_MIN + 1) + N_MIN;
}

//linear search function
int linear_search(int num[], int value)
{
	int counter = 0;
	for(int i=0;i<NUM;i++)
	{
		if(num[i] == value)
		{
			counter++;
			return counter;
		}
		counter++;
	}
	
	//return 0 if no match found
	return 0;
}

//selection sort
void selection_sort(int num[])
{
	int start_scan = 0;
	do
	{
		int min = num[start_scan];
		int min_index = start_scan;
		for(int i=start_scan;i<NUM;i++)
			if(min > num[i])
			{
				min = num[i];
				min_index = i;
			}
		//exchange
		num[min_index] = num[start_scan];
		num[start_scan] = min;
		
		//update start_scan index
		start_scan++;
		
	} while (start_scan < NUM-1);
	
}

//binary search function
int binary_search(int num[], int value)
{
	int counter = 0;
	int first = 0, last = NUM-1;
	do
	{
		int middle = (first+last)/2;
		if(num[middle] == value)
		{
			counter++;
			return counter;
		}
		else if (num[middle] > value)
		{
			counter++;
			last = middle - 1;
			continue;
		}
		else
		{
			counter++;
			first = middle + 1;
			continue;
		}
	} while (first <= last);
	
	return 0;
}
