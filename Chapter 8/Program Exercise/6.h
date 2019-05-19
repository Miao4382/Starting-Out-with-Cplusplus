#include <iostream>
#include <string>

const int NUM_NAMES = 20;
//function prototype
void print(std::string names[]);
void selection_sort(std::string names[]);

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
	
	std::cout << "Before sorting:\n";
	print(names);
	
	//call sorting function to sort the string array
	selection_sort(names);
	
	//print the names again
	std::cout << "After sorting:\n";
	print(names);
	
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

