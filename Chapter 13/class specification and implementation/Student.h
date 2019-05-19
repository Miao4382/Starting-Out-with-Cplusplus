
//This is the specification of class Student

//this ifndef section is served as include guard, it can ensure that the declaration of class Student will only occur once
//if a certain constant has been found defined, it means the class has already been defined before, just skip that 

#ifndef Student_h
#define Student_h

#include <iostream>

//class declaration
class Student
{
private:
	char name[100]; //used to hold the name of a student, will be set when the object is created
	double score1;
	double score2;
	double score3;
public:
	Student(char *input);
	Student();
	void set_score(double s1, double s2, double s3);
	double get_average() const
	{
		return (score1 + score2 + score3) / 3;
	}
	void display_name() const;
	void display_score() const
	{
		std::cout << "Score_1: " << score1 << "\n";
		std::cout << "Score_2: " << score2 << "\n";
		std::cout << "Score_3: " << score3 << "\n";
	}
};

#endif