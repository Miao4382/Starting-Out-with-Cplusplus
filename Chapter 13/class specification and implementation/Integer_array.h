
#ifndef INTEGER_ARRAY_H
#define INTEGER_ARRAY_H

class Integer_array
{
private:
	int *array;
	int num_element;
	bool is_valid(int index) const; //check if the index is valid for this object
public:
	//constructor & destructor
	Integer_array(int size); //constructor, allocate memory space to hold array, initialize every element with zero (number of element = size)
	~Integer_array(); //destructor, delete dynamically allocated space 

	//accessor
	int get_element(int index) const; //show the element stored in position index

	//mutator
	void set_element(int index, int value); //set the element in position index to value provided
};

#endif
