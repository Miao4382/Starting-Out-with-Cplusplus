#include <iostream>
#include <fstream>
#include <vector>

//function prototype
void read_data(std::vector<int> &account_number);
int linear_search(std::vector<int> account_number, int number);

int main()
{
	//define a container, call read_data function to read data from file
	std::vector<int> account_number;
	read_data(account_number);
	
	//ask user to enter a number to check
	std::cout << "Please input a number to check: ";
	int number;
	std::cin >> number;
	
	//call linear search function to check if the number is in the array
	int result;
	result = linear_search(account_number, number);
	
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

//search function
int linear_search(std::vector<int> account_number, int number)
{
	for (int i=0; i<account_number.size(); i++)
	{
		if (account_number[i] == number)
			return 1;
	}
	
	return 0;
}
