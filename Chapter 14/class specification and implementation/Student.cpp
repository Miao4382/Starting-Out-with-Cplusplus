
//This is the implementation file of the class Student, it contains the definition of member functions
#include "Student.h"
#include <iostream>
#include <cstring>

//other function declaration
void strcpy2(char *destination, const char *source);

//set score function 
void Student::set_score(double s1, double s2, double s3)
{
	score1 = s1;
	score2 = s2;
	score3 = s3;
}
//constructor-0 (default)
Student::Student()
{
	strcpy2(name, "Not Specified");
}
//constructor-1
Student::Student(char *input)
{
	//copy the input argument to the name[] in the class
	strcpy2(name, input);
}

//display name
void Student::display_name() const
{
	std::cout << name << " ";
}

//for C-string copy function
void strcpy2(char *destination, const char *source)
{
	int i = 0;
	while (source[i] != '\0')
		destination[i] = source[i++];
	destination[i] = '\0';
}
