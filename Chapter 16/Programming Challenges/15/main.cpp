#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

//function prototype
void read_data(std::vector<int> &account_number);

int main()
{
	//define a container, call read_data function to read data from file
	std::vector<int> account_number;
	read_data(account_number);
  
  // sort the vector 
  std::sort(account_number.begin(), account_number.end());
  
	
	//ask user to enter a number to check
	std::cout << "Please input a number to check: ";
	int number;
	std::cin >> number;
	
	//call linear search function to check if the number is in the array
	bool result;
	result = std::binary_search(account_number.begin(), account_number.end(), number);
	
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
	cin.open("C:\\Users\\cheng yingying\\Desktop\\8-1 data.txt");
	
	int transfer;
	while(cin >> transfer)
		account_number.push_back(transfer);
	
	cin.close();
}
