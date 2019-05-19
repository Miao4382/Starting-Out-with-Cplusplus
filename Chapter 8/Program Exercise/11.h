#include <iostream>
#include <string>
#include <fstream>

void get_data(std::string names[]);
void selection_sort(std::string names[]);
void write_data(std::string names[]);

int main()
{
	//define a container
	std::string names[20];
	
	//call function to fill names[20] with data
	get_data(names);
	
	//call function to sort the data, in alphabetical order
	selection_sort(names);
	
	//call function to write data to a new txt file
	write_data(names);
	
	return 0;
}

void get_data(std::string names[])
{
	std::ifstream cin;
	cin.open("D:\\names.txt");
	
	for(int i=0;i<20;i++)
	{
		getline(cin, names[i]);
	}
	
	cin.close();
}

void selection_sort(std::string names[])
{
	int start_scan = 0;
	do
	{
		std::string min = names[start_scan];
		int min_index = start_scan;
		for(int i=start_scan;i<20;i++)
			if(min > names[i])
			{
				min = names[i];
				min_index = i;
			}
		names[min_index] = names[start_scan];
		names[start_scan] = min;
		
		start_scan++;
	} while (start_scan < 19);
	
}

void write_data(std::string names[])
{
	std::ofstream cout;
	cout.open("D:\\names-sorted.txt");
	
	for(int i=0;i<20;i++)
		cout << names[i] << std::endl;
	cout.close();
	
	//notify the user
	std::cout << "The sorted data has already been written to names-sorted.txt\n";
}