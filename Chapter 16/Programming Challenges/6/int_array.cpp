#include "Int_array.h"
#include <iostream>
#include <cstdlib>

/* Constructor */
//constructor
Int_array::Int_array(int s) //allocate a memory space of size, initialize with zero
{
	size = s;
	num = new int[s];

	for (int i = 0; i<size; i++)
		num[i] = 0;
}

Int_array::Int_array(const Int_array &obj) //copy constructor, allocate new memory space and copy everything
{
	size = obj.size;

	num = new int[size];

	for (int i = 0; i<size; i++)
		num[i] = obj.num[i];
}

/* Destructor */
Int_array::~Int_array() //delete the allocated memory 
{
	if (size > 0) //make sure there is element stored in the object, avoid assertion error
		delete[] num;
}

/* Accessor */
int Int_array::array_size() const //returns the size of the array
{
	return size;
}

/* Operator */
int & Int_array::operator[] (const int &index) //overloaded [] operator, add a boundary check function
{
	if (index >= size || index < 0) //over the boundary, throw the empty exception class
	{
    throw OutBoundary();
	}
	else
		return num[index];
}

const Int_array Int_array::operator= (const Int_array &right)
{
	size = right.size;
	num = new int[size];

	for (int i = 0; i < size; i++)
		num[i] = right.num[i];

	return *this;
}

std::ostream& operator<< (std::ostream &out, const Int_array &obj)
{
	for (int i = 0; i < obj.size; i++)
		out << obj.num[i] << " ";

	return out;
}
