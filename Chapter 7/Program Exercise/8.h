//8. Lo Shu Magic Square
#include<iostream>

bool check_sum(int square[3][3]);
bool check_unique(int square[3][3]);

int main()
{
	//int square[3][3] = { {4,9,2}, {3,5,7},{8,1,6} };
	int square[3][3] = { {1,1,1}, {1,1,1},{1,1,1} };
	if (check_sum(square)&&check_unique(square))
		std::cout << "The square is Lo Shu Magic Square\n";
	else
		std::cout << "The square is not Lo Shu Magic Square\n";

	return 0;
}

//check if summation is equal
bool check_sum(int square[3][3])
{
	
	int value;

	//check diaganol sums are equal or not
	value = square[0][0] + square[2][2];
	if (value != square[0][2] + square[2][0])
		return false;
	value = value + square[1][1];

	//check column sum, from row 0 to row 2
	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int j = 0; j < 3; j++)
			sum += square[i][j];
		if (value != sum)
			return false;
	}

	//check row sum, from column 0 to 2
	for (int j = 0; j < 3; j++)
	{
		int sum = 0;
		for (int i = 0; i < 3; i++)
			sum += square[i][j];
		if (value != sum)
			return false;
	}

	//if come this far, the square is Lo Shu Magic Square
	return true;
}

//check if all elements are unique
bool check_unique(int square[3][3])
{
	int unique_counter;
	
	//use an iteration to compare uniqueness from 1 ~ 9, compare each element with the number
	for (int num = 1; num <= 9; num++)
	{
		unique_counter = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				if (square[i][j] == num)
					unique_counter++;
		}
		if (unique_counter != 1)
			return false;
	}

	//if 1 ~ 9 all satisfies occuring time is one, then all number in the square is unique and they are from 1 to 9
	return true;
}

