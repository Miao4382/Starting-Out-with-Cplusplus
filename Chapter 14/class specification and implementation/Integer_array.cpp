
#include "Integer_array.h"
#include <iostream>

bool Integer_array::is_valid(int index) const //check if the index is valid for this object
{
	if (index < 0 || index >= num_element)
		return false;
	else
		return true;
}

//constructor & destructor
Integer_array::Integer_array(int size) //constructor, allocate memory space to hold array, initialize every element with zero (number of element = size)
{
	//allocate memory 
	array = new int[size];
	//update number of element 
	num_element = size;
	//initialize with zero 
	for (int i = 0; i<size; i++)
		array[i] = 0;
}

Integer_array::~Integer_array() //destructor, delete dynamically allocated space 
{
	delete[] array;
}

//accessor
int Integer_array::get_element(int index) const //show the element stored in position index
{
	if (!is_valid(index))
		std::cout << "Invalid index.\n";
	else
		return array[index];
}

//mutator
void Integer_array::set_element(int index, int value) //set the element in position index to value provided
{
	if (!is_valid(index))
		std::cout << "Invalid index.\n";
	else
		array[index] = value;
}