//19. 2D Array Operations
#include<iostream>
const int N_row = 3, N_column = 3;

int get_total(int num[N_row][N_column]);
double get_average(int num[N_row][N_column]);
int get_row_total(int num[N_row][N_column], int row_number);
int get_column_total(int num[N_row][N_column], int column_number);
int get_highest_in_row(int num[N_row][N_column], int row_number);
int get_lowest_in_row(int num[N_row][N_column], int row_number);

int main() //this main function serves as a driver to test the above equation
{
	//build up a matrix
	int num[N_row][N_column] = { {4,9,2},{3,5,7},{8,1,6} };

	//define variables to hold return value
	int total, row_total, column_total, high_row, low_row;
	double average;

	//test function
	total = get_total(num);
	average = get_average(num);
	row_total = get_row_total(num, 0);
	column_total = get_column_total(num, 1);
	high_row = get_highest_in_row(num, 1);
	low_row = get_lowest_in_row(num, 2);

	//print out result
	std::cout << "Total: " << total << std::endl;
	std::cout << "Average: " << average << std::endl;
	std::cout << "Total in row 1: " << row_total << std::endl;
	std::cout << "Total in column 2: " << column_total << std::endl;
	std::cout << "Highest in row 2: " << high_row << std::endl;
	std::cout << "Lowest in row 3: " << low_row << std::endl;

	//end
	return 0;

}

int get_total(int num[N_row][N_column])
{
	int total=0;
	for (int i = 0; i < N_row; i++)
	{
		for (int j = 0; j < N_row; j++)
			total += num[i][j];
	}

	return total;
}

double get_average(int num[N_row][N_column])
{
	int total = 0;
	double counter=0;

	for (int i = 0; i < N_row; i++)
	{
		for (int j = 0; j < N_row; j++)
		{
			total += num[i][j];
			counter++;
		}
	}

	return total / counter;
}

int get_row_total(int num[N_row][N_column], int row_number)
{
	int total = 0;

	for (int i = 0; i < N_column; i++)
		total += num[row_number][i];

	return total;
}

int get_column_total(int num[N_row][N_column], int column_number)
{
	int total = 0;

	for (int i = 0; i < N_row; i++)
		total += num[i][column_number];

	return total;
}

int get_highest_in_row(int num[N_row][N_column], int row_number)
{
	int high = num[row_number][0];

	for (int i = 1; i < N_column; i++)
	{
		if (high < num[row_number][i])
			high = num[row_number][i];
	}

	return high;
}

int get_lowest_in_row(int num[N_row][N_column], int row_number)
{
	int low = num[row_number][0];

	for (int i = 1; i < N_column; i++)
		if (low > num[row_number][i])
			low = num[row_number][i];

	return low;
}