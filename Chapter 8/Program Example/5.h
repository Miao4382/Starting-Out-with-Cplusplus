//8-5. Selection Algorithm
#include <iostream>

const int N = 10;
void print(int num[], int size);
void selection_sort(int num[], int size);

int main()
{
	/*
	This program uses a function runs a function based on selection algorithm to sort the array
	*/

	//variable definition
	int num[N] = { 1,16,24,39,54,6,4,66,53,100 };

	//print out the array
	std::cout << "Before the sorting:\n";
	print(num, N);

	//sort
	selection_sort(num, N);

	//print again
	std::cout << "After the sorting:\n";
	print(num, N);

	return 0;
}

//printing function
void print(int num[], int size)
{
	for (int i = 0; i < N; i++)
		std::cout << num[i] << " ";
	std::cout << "\n";
}

//selection sort
void selection_sort(int num[], int size)
{
	int min;
	int first = 0; //define the variable that can be used as a dynamic range
	int min_sb;
	int transfer; //transfer variable
	do
	{
		//initialize
		min = num[first];
		min_sb = first;

		//scan the entire sorting region, find out the smallest and highest
		for (int i = first; i < size; i++)
		{
			if (min > num[i])
			{
				min = num[i];
				min_sb = i;
			}
		}

		//exchange the smallest value with num[first] and the highest value with num[last]
			//exchange min value
		transfer = num[first];
		num[first] = num[min_sb];
		num[min_sb] = transfer;


		//update the sorting region
		first++;
	} while (first < size);

}

