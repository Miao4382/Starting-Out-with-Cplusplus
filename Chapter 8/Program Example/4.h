//8-4. Bubble Sorting
//Objective : use bubble sorting technique to sort an array in descending order

#include <iostream>

const int N = 13;

void bubble_sort(int num[], int size);

int main()
{
	/*
	This function calls other functions to finish the objective and display result
	*/

	//variable definition
	int num[N] = { 1,2,5,3,7,9,10,4,55,6,23,44,78 };

	//print the array before sorting
	std::cout << "Before sorting: ";
	for (int i = 0; i < N; i++)
		std::cout << num[i] << " ";
	std::cout << "\n";

	//call bubble_sort() function to sort the array
	bubble_sort(num, N);

	//print the array again
	std::cout << "Before sorting: ";
	for (int i = 0; i < N; i++)
		std::cout << num[i] << " ";
	std::cout << "\n";

	return 0;
}

//bubble sort function
void bubble_sort(int num[], int size)
{
	/*
	This function uses a bubble sorting algorithm to sort the array
	*/

	int transfer; //variable to store the value temporarily

	bool flag;

	do
	{
		flag = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (num[i] < num[i + 1])
			{
				transfer = num[i];
				num[i] = num[i+1];
				num[i + 1] = transfer;
				flag = true; //this means there is an exchange during the run through
			}
		}
	} while (flag);
}



