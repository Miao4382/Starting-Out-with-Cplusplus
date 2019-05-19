#include "Number.h"
#include <iostream>

/* Constructor */
Number::Number(int size_input) //allocate memory space of size to the pointer 
{
	num = new double[size_input];
	size = size_input;

	//initialize with zero
	for (int i = 0; i<size; i++)
		num[i] = 0;

}

/* Mutator */
void Number::set_value(int index, double value) //store value in num[index]
{
	num[index] = value;
}

/* Accessor */
double Number::get_value(int index) const //return value stored in num[index]
{
	return num[index];
}

int Number::get_highest() const //return index of highest value stored in num
{
	double high = num[0];
	int high_index = 0;

	for (int i = 1; i<size; i++)
		if (high < num[i])
		{
			high = num[i];
			high_index = i;
		}

	return high_index;
}

int Number::get_lowest() const //return index of lowest value stored in num
{
	double low = num[0];
	int low_index = 0;

	for (int i = 1; i<size; i++)
		if (low > num[i])
		{
			low = num[i];
			low_index = i;
		}

	return low_index;
}

double Number::get_average() const //return average of all the numbers stored in num[]
{
	double total = 0;

	for (int i = 0; i<size; i++)
		total += num[i];

	return total / size;
}

/* Destructor */
Number::~Number() //free memory allocated by constructor
{
	delete[] num;
}

