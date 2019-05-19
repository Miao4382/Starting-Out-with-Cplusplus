#include <iostream>
#include <ctime>
#include <cstdlib>

const int NUM=1000, N_MIN=1, N_MAX=10000;

//function prototype
void random_creater(int num[]);
int selection_sort(int num[]);
int bubble_sort(int num[]);

int main()
{
	//create a random integer array, and duplicate. So selection and bubble can use same array
	int num[NUM], num1[NUM];
	random_creater(num);
	for(int i=0;i<NUM;i++)
		num1[i] = num[i];	
	
	//sort the array using a selection sorting technique
	int selection_benchmark;
	selection_benchmark = selection_sort(num);
	
	//sort the array using a bubble sorting technique
	int bubble_benchmark;
	bubble_benchmark = bubble_sort(num1);
	
	//print and compare
	std::cout << "The selection sorting benchmark: " << selection_benchmark << "\n";
	std::cout << "The bubble sorting benchmark: " << bubble_benchmark << "\n";
	
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


//selection sort
int selection_sort(int num[])
{
	int start_scan = 0;
	int counter = 0;
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
		counter++;
		
		//update start_scan index
		start_scan++;
		
	} while (start_scan < NUM-1);
	
	return counter;
	
}

//bubble sort
int bubble_sort(int num[])
{
	int counter = 0;
	bool exchanged;
	do
	{
		exchanged = false; //don't forget to set exchange flag to false at the beginning of each iteration
		for(int i=0;i<NUM-1;i++)
		{
			if(num[i] > num[i+1])
			{
				int transfer;
				transfer = num[i];
				num[i] = num[i+1];
				num[i+1] = transfer;
				counter++; //update the counter
				exchanged = true; //set status of exchange to true
			}
		}
	} while (exchanged);
	
	return counter;
}