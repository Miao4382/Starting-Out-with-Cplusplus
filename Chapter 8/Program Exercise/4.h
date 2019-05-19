#include <iostream>
#include <fstream>
#include <vector>

//function prototype
void read_data(std::vector<int> &account_number);
void selection_sort(std::vector<int> &account_number);
int linear_search(std::vector<int> account_number, int number);
int binary_search(std::vector<int> account_number, int number);

int main()
{
	//define a container, call read_data function to read data from file, then sort it
	std::vector<int> account_number;
	read_data(account_number);
	selection_sort(account_number);
	
	//ask user to enter a number to check
	std::cout << "Please input a number to check: ";
	int number;
	std::cin >> number;
	
	//call linear search function to check if the number is in the array
	int result;
	result = binary_search(account_number, number);
	
	//check result
	if(result)
		std::cout << "The number is valid.\n";
	else
		std::cout << "The number is invalid.\n";
	
	return 0;
}

//read_data function
void read_data(std::vector<int> &account_number)
{
	std::ifstream cin;
	cin.open("D:\\8-1 data.txt");
	
	int transfer;
	while(cin >> transfer)
		account_number.push_back(transfer);
	
	cin.close();
}

//sorting function. Sort the vector so the binary searching algorithm can be used
void selection_sort(std::vector<int> &account_number)
{
	int start_scan = 0;
	int min, min_index;
	
	do
	{
		//re-set min and min_index
		min = account_number[start_scan];
		min_index = start_scan;
		
		//go over to find out the minimum
		for(int i=start_scan;i<account_number.size();i++)
		{
			if(min > account_number[i])
			{
				min = account_number[i];
				min_index = i;
			}
		}
		
		//exchange
		account_number[min_index] = account_number[start_scan];
		account_number[start_scan] = min;
		
		//update start_scan indicator
		start_scan++;
		
	} while (start_scan < account_number.size());
		
}

//linear search function
int linear_search(std::vector<int> account_number, int number)
{
	for (int i=0; i<account_number.size(); i++)
	{
		if (account_number[i] == number)
			return 1;
	}
	
	return 0;
}

//binary search function
int binary_search(std::vector<int> account_number, int number)
{
	int first = 0, last = account_number.size()-1;
	
	do
	{
		int middle = (first+last)/2;
		
		if (account_number[middle] == number)
			return middle;
		else if (account_number[middle] > number)
		{
			last = middle - 1;
			continue;
		}
		else
		{
			first = middle + 1;
			continue;
		}
	} while (first <= last);
	
	return 0;
}
