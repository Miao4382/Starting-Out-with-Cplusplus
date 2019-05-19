//7-22. Passing two dimensional arrays
#include<iostream>
#include<iomanip>

const int COLUMN = 3;
void show_array(int num[][COLUMN], int row);
int main()
{
	int hour[4][COLUMN] = { {1,2,3},{2,4,5},{3,6,7},{4,8,9} };
	show_array(hour, 4);

	return 0;

}

void show_array(int num[][COLUMN], int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < COLUMN; j++)
			std::cout << num[i][j] << "  ";
		std::cout << std::endl;
		
	}
}