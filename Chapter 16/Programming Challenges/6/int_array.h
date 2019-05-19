#ifndef INTARRAY_H
#define INTARRAY_H
#include <iostream>

class Int_array
{
private:
	int *num; //pointer to array
	int size; //hold the array size
public:
	/* Constructor */
	//constructor
	Int_array(int s); //allocate a memory space of size, initialize with zero
	Int_array(const Int_array &obj); //copy constructor, allocate new memory space and copy everything
	
	/* Destructor */
	~Int_array(); //delete the allocated memory 
	
	/* Accessor */
	int array_size() const; //returns the size of the array
	
	/* Operator */
	//overloaded [], add a boundary check
	int &operator[] (const int &index);
	//overload =
	const Int_array operator= (const Int_array &right);
	//overload <<
	friend std::ostream& operator<< (std::ostream &out, const Int_array &obj);
  
  /* Exception class */
  class OutBoundary
  {};
  
};

#endif