#include <iostream>
#include <string>

const int NUM_NAMES = 20;
//function prototype
void print(std::string names[]);
void selection_sort(std::string names[]);
void input_name(std::string &name);
int binary_search(std::string names[], std::string name);

//driver
int main()
{

	std::string names[NUM_NAMES] = { "Collins, Bill", "Smith, Bart", "Allen, Jim",
		"Griffin, Jim", "Stamey, Marty", "Rose, Geri",
		"Taylor, Terri", "Johnson, Jill",
		"Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
		"James, Jean", "Weaver, Jim", "Pore, Bob",
		"Rutherford, Greg", "Javens, Renee",
		"Harrison, Rose", "Setzer, Cathy",
		"Pike, Gordon", "Holland, Beth" };	
	
	//call sorting function to sort the string array
	selection_sort(names);
	
	//ask the user to input a name to search
	std::string name;
	input_name(name);
	
	//call binary search function to search for the array, and return result
	int result;
	result = binary_search(names, name);
	
	//print out result
	if(result)
		std::cout << "Your inputted name is in the list.\n";
	else
		std::cout << "You inputted name is not in the list.\n";
	
	return 0;
}

void print(std::string names[])
{
	for(int i=0; i<NUM_NAMES;i++)
		std::cout << names[i] <<std::endl;
	std::cout << "\n";
}

//sorting function
void selection_sort(std::string names[])
{
	std::string min;
	int start_scan = 0, min_index;
	
	do
	{
		min = names[start_scan];
		min_index = start_scan;
		
		//go over the array to find out the lowest
		for(int i=start_scan;i<NUM_NAMES;i++)
		{
			if(min > names[i])
			{
				min = names[i];
				min_index = i;
			}
		}
		
		//exchange
		names[min_index] = names[start_scan];
		names[start_scan] = min;
		
		//update start_scan index
		start_scan++;
	} while (start_scan < NUM_NAMES - 1);
}

//ask user to input a name
void input_name(std::string &name)
{
	std::cout << "Please input a name to search: ";
	getline(std::cin, name);
}

//binary search
int binary_search(std::string names[], std::string name)
{
	int first = 0, last = NUM_NAMES-1;
	do
	{
		int middle = (first+last)/2;
		if(names[middle] == name)
			return 1;
		else if (names[middle] > name)
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
