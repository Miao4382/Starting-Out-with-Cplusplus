//Program 5-20: Number reading
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	//define a reading file stream object, and link to the number.txt
	ifstream read_file;
	read_file.open("C:\\Users\\My\\Desktop\\number.txt");

	//variable definition
	int num;

	for (int i = 1; i <= 3; i++)
	{
		read_file >> num;
		cout << "Number " << i << " is: " << num << endl;
	}
	read_file.close();
	return 0;
}