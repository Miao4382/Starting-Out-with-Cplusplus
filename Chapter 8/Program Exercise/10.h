#include <iostream>

//function prototype
void selection_sort(int num[]);
void bubble_sort(int num[]);

int main()
{
	//create the array
	int num1[8] = { 2,9,4,5,6,7,1,3 };
	int num2[8] = { 2,9,4,5,6,7,1,3 };
	
	//sort by bubble algorithm
	bubble_sort(num1);
	
	//separate
	std::cout << "\n\n\n\n\n";
	
	//sort by selection algorithm
	selection_sort(num2);
	
	return 0;
}

void selection_sort(int num[])
{
	int start_scan = 0;
	do
	{
		int min = num[start_scan];
		int min_index = start_scan;
		
		for(int i=start_scan; i<8; i++)
		{
			if(min > num[i])
			{
				min = num[i];
				min_index = i;
			}
		}
		
		//exchange
		num[min_index] = num[start_scan];
		num[start_scan] = min;
		
		//print the array after one run
		for(int i=0;i<8;i++)
			std::cout << num[i] << " ";
		std::cout << "\n";
		
		//update start_scan
		start_scan++;
		
	} while (start_scan < 7);
}

void bubble_sort(int num[])
{
	bool exchanged;
	do
	{
		exchanged = false;
		for(int i=0;i<7;i++)
		{
			if(num[i] > num[i+1])
			{
				int transfer;
				transfer = num[i];
				num[i] = num[i+1];
				num[i+1] = transfer;
				exchanged = true; //set exchange flag if exchange is occured
			}
		}
		//print the array after one iteration
		for(int i=0;i<8;i++)
			std::cout << num[i] << " ";
		std::cout << "\n";
		
	} while (exchanged);
}