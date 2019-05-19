#include <iostream>

const int SIZE = 12;
int binary_search(int num[], int size, int number);

int main()
{
	//define
	int num[SIZE] = { 54, 75, 120, 155, 169, 185, 200, 225, 260, 310, 445, 560 }; //array to hold the number
	int number; //the search number
	int result;

	//ask user to input the number
	std::cout << "Input a number to check if the number is in the array: ";
	std::cin >> number;

	//call binary_search() to check if the number is in the array
	result = binary_search(num, SIZE, number);

	//print out result
	if (result == -1)
		std::cout << "The number is not in the array.\n";
	else
		std::cout << "The number is in the array, it's the number " << result + 1 << std::endl;

	return 0;
}

int binary_search(int num[], int size, int number)
{
	int first = 0, last = size-1;
	int middle = (last + first) / 2;

	do
	{
		if (num[middle] == number)
			return middle;
		else if (num[middle] > number)
		{
			last = middle-1;
			middle = (last + first) / 2;
		}
		else
		{
			first = middle+1;
			middle = (last + first) / 2;
		}
	} while (first <= last);

	return -1;

}