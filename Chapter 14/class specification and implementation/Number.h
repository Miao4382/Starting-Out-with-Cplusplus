#ifndef NUMBER_H
#define NUMBER_H

class Number
{
private:
	double *num;
	int size;
	
public:
	/* Constructor */
	Number(int size_input); //allocate memory space of size to the pointer 
	
	/* Mutator */
	void set_value(int index, double value); //store value in num[index]
	
	/* Accessor */
	double get_value(int index) const; //return value stored in num[index]
	int get_highest() const; //return highest value stored in num[index]
	int get_lowest() const; //return lowest value stored in num[index]
	double get_average() const; //return average of all the numbers stored in num[]
	
	/* Destructor */
	~Number(); //free memory allocated by constructor
};

#endif
