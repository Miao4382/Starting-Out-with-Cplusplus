/* Chapter 14. More about Classes */

/*********************/
/***Program Example***/
/*********************/


1. Demonstrate a static member variable I: object counter
{

#include <iostream>

class Tree
{
private:
	static int tree_count; //static member variable
public:
	Tree()
	{
		tree_count++;
	}

	//access tree_count
	static int GetTreeCount()
	{
		return tree_count;
	}
};

//definition of static member variable is written outside of the class
int Tree::tree_count = 0;

int main()
{
	std::cout << "Now, tree defined: " << Tree::GetTreeCount() << "\n";

	Tree t1, t2, t3;

	std::cout << "After defining 3 tree object, tree defined: " << Tree::GetTreeCount() << "\n";

	return 0;

}

}

2. Demonstrate a static member variable II: Total budget
{

1) class specification
{

#ifndef BUDGET_H
#define BUDGET_H

class Budget
{
private:
	static int total_budget; //hold the total budget of the object
	int budget; //hold budget
public:
	Budget(int bdgt) //constructor: initialize the budget, also add to total_budget
	{
		budget = bdgt;
		total_budget += bdgt;
	}

	int GetBudget() const //get budget 
	{
		return budget;
	}

	int GetTotalBudget() //get total budget
	{
		return total_budget;
	}

	void SetBudget(int bdgt) //set budget, will also update total_budget (subtract old value first, then add up new value)
	{
		total_budget -= budget;
		budget = bdgt;
		total_budget += budget;
	}
};

int Budget::total_budget = 0; //define the static variable

#endif

}

2) main function
{

#include "Budget.h"
#include <iostream>

int main()
{
	Budget b1(10), b2(20), b3(30), b4(40);

	std::cout << "The total budget is: $" << b1.GetTotalBudget() << "\n";
	return 0;
}

}

}

3. Demonstrate a static member function 
{

1) class specification 
{

#ifndef BUDGET_H
#define BUDGET_H

class Budget
{
private:
	static int total_budget; //hold total budget
	int division_budget; //hold individual division budget 
public:
	Budget(int b) //constructor: initialize with division_budget
	{
		division_budget = b;
		//total_budget += b;
	}
	int GetDivisionBudget() const //return division_budget stored in this class
	{
		return division_budget;
	}
	int GetTotalBudget() const //return total_budget (a static member variable)
	{
		return total_budget;
	}

	static void MainOffice(int b); //static member function, add b to total budget 
};


#endif

}

2) class implementation
{

#include "Budget.h"

int Budget::total_budget = 0; //initialize static member variable

void Budget::MainOffice(int b) //static member function, add b to total budget
{
	total_budget += b;
}

}

3) main program
{


#include "Budget.h"
#include <iostream>

int main()
{
	//call the static member function first to add the budget for main office
	Budget::MainOffice(200);

	//define three object of Budget class
	Budget b1(10), b2(20), b3(30);

	//display total budget
	std::cout << "Total budget is: $" << b1.GetTotalBudget() << "\n";

	return 0;

}

}

}

4. Declaring friend of a class
{

1) Asuxiliary_office class 
{
> specification 
{

//Auxiliary_office class, containing AddBudget() function, which is a friend of Budget class
#ifndef AUXILI_H
#define AUXILI_H

//#include "Budget.h"
class Budget;

class Auxiliary_office
{
public:
	void AddBudget(int b, Budget &B); //a friend of Budget
};

#endif



}

> implementation 
{

#include "Budget.h"
#include "Auxiliary_office.h"

void Auxiliary_office::AddBudget(int b, Budget &B)
{
	B.total_budget += b;
}

}

}

2) Budget class 
{

1) specification 
{

//Budget class 
#ifndef BUDGET_H
#define BUDGET_H

#include "Auxiliary_office.h"

class Budget
{
private:
	static int total_budget; //hold total budget
	int division_budget; //hold individual division budget 
public:
	Budget(int b);
	int GetDivisionBudget() const;
	int GetTotalBudget() const;
	static void MainOffice(int b); //static member function, add b to total budget 
	friend void Auxiliary_office::AddBudget(int b, Budget &B);
	friend void DirectModify(int b, Budget &B);
};


#endif

}

2) implementation 
{

#include "Budget.h"

int Budget::total_budget = 0; //initialize static member variable

Budget::Budget(int b) //constructor: initialize with division_budget
{
	division_budget = b;
	total_budget += b;
}
int Budget::GetDivisionBudget() const //return division_budget stored in this class
{
	return division_budget;
}
int Budget::GetTotalBudget() const //return total_budget (a static member variable)
{
	return total_budget;
}
void Budget::MainOffice(int b) //static member function, add b to total budget
{
	total_budget += b;
}


}

}

3) main program
{

#include "Auxiliary_office.h"
#include "Budget.h"
#include <iostream>

void DirectModify(int b, Budget &B);

int main()
{
	//call the static member function first to add the budget for main office
	Budget::MainOffice(200);

	//define three object of Budget class
	Budget b1(10), b2(20), b3(30);

	//display total budget
	std::cout << "Total budget is: $" << b1.GetTotalBudget() << "\n";

	//now, create an Auxiliary_office object, and then call AddBudget() function
	Auxiliary_office a1;
	a1.AddBudget(1000, b1);
	std::cout << "After adding auxiliary office budget, total budget is: $" << b1.GetTotalBudget() << "\n";

	DirectModify(10, b1);
	std::cout << "After direct modify, total budget is: $" << b1.GetTotalBudget() << "\n";

	return 0;

}

void DirectModify(int b, Budget &B)
{
	B.total_budget = b;
}


}

}

5. Demonstrate memberwise assignment
{
//use Rectangle.h class in Chapter 13 (source code, version 4)
#include "Rectangle.h"
#include <iostream>

int main()
{
	Rectangle r1(1, 2);
	std::cout << "r1 width: " << r1.getWidth() << "\n"
		<< "r1 length: " << r1.getLength() << "\n"
		<< "r1 area: " << r1.getArea() << "\n";

	Rectangle r2(4,5);
	r2 = r1;
	std::cout << "r2 width: " << r2.getWidth() << "\n"
		<< "r2 length: " << r2.getLength() << "\n"
		<< "r2 area: " << r2.getArea() << "\n";

	return 0;
}

}

Work_flow_1: test if copy constructor is called when passing object to function by value
{

1) Student class specification
{

#ifndef STUDENT
#define STUDENT

#include <string>



class Student
{
private:
	static int student_num; //hold number of Student class defined
	std::string name; //hold student name
	double *score; //points to a double array to store the score of the student 
	int score_num; //hold total number of scores
	double *CreateArray(int size); //called by constructor, to allocate a new memory space for storing score
public:
	Student(std::string n, int num); //constructor, will allocate memory for score
	Student(Student &obj); //copy constructor, when object is copied, allocate new memory space for the score pointer 
	~Student(); //destructor, de-allocate the dynamically allocated memory 

	void SetName(std::string n); //modify student's name
	void SetScore(double s, int index); //set student's score, index is used to locate the score 

	double GetScore(int index) const; //return score stored in array
	std::string GetName() const; //return student's name 
	double GetAverageScore() const; //return average score
	double GetHighestScore() const; //return highest score 
	double GetLowestScore() const; //return lowest score 	
};

#endif

}

2) Student class implementation
{

#include "Student.h"
#include <string>

const double DEFAULT_SCORE = 0.0;

int Student::student_num = 0; //define static member variable

double *Student::CreateArray(int size) //called by constructor, to allocate a new memory space for storing score
{
	double *ptr = new double[size];
	return ptr;
}

Student::Student(std::string n, int num) //constructor, will allocate memory for score
{
	student_num++; 
	name = n;
	score_num = num;
	score = CreateArray(num);
	
	//initialize array with default score 
	for (int i=0; i<num; i++)
	{
		score[i] = DEFAULT_SCORE;
	}
}

Student::Student(Student &obj) //copy constructor, when object is copied, allocate new memory space for the score pointer
{
	student_num++;
	name = obj.name;
	score_num = obj.score_num;
	score = CreateArray(score_num);
	
	for (int i=0; i<score_num; i++)
		score[i] = DEFAULT_SCORE;
}

Student::~Student() //destructor, de-allocate the dynamically allocated memory 
{
	delete[] score;
}

void Student::SetName(std::string n) //modify student's name
{
	name = n;
}
void Student::SetScore(double s, int index) //set student's score, index is used to locate the score 
{
	score[index] = s;
}

double Student::GetScore(int index) const //return score stored in array
{
	return score[index];
}

std::string Student::GetName() const //return student's name 
{
	return name;
}

double Student::GetAverageScore() const //return average score
{
	double total = 0.0;
	
	for (int i=0; i<score_num; i++)
		total += score[i];
	
	return total/score_num;
}

double Student::GetHighestScore() const //return highest score 
{
	double high = score[0];
	
	for (int i=1; i<score_num; i++)
		if (high < score[i])
			high = score[i];
	
	return high;
}

double Student::GetLowestScore() const //return lowest score 
{
	double low = score[0];
	
	for (int i=1; i<score_num; i++)
		if (low > score[i])
			low = score[i];
	
	return low;	
}



}

3) main program
{

#include "Student.h"
#include <iostream>

void DisplayScore(Student s);

int main()
{
	Student s1("Yu Miao", 3);
	s1.SetScore(99.9, 0);
	s1.SetScore(98.2, 1);
	s1.SetScore(99.9, 2);

	std::cout << "Average score of Yu Miao: " << s1.GetAverageScore() << "\n";

	Student s2 = s1;
	std::cout << "Copied average score: " << s2.GetAverageScore() << "\n";

	std::cout << "Copied by passing value: ";
	DisplayScore(s1);
	return 0;
}

void DisplayScore(Student s)
{
	std::cout << "Average score is: " << s.GetAverageScore() << "\n";
}

}

}

6. Overloading = operator 
{

1) Student class specification
{

#ifndef STUDENT
#define STUDENT

#include <string>


class Student
{
private:
	static int student_num; 
	std::string name; 
	double *score; 
	int score_num;

public:
	Student(std::string n, int num); 
	Student(Student &obj); 
	//~Student();

	void SetName(std::string n); 
	void SetScore(double s, int index); 

	double GetScore(int index) const; 
	std::string GetName() const; 
	void operator= (const Student &obj);
};

#endif


}

2) Student class implementation 
{

#include "Student.h"
#include <string>
#include <iostream>

const double DEFAULT_SCORE = 0.0;

int Student::student_num = 0; //define static member variable


Student::Student(std::string n, int num) //constructor, will allocate memory for score
{
	student_num++; 
	name = n;
	score_num = num;
	score = new double[num];
	
	//initialize array with default score 
	for (int i=0; i<num; i++)
	{
		score[i] = DEFAULT_SCORE;
	}
}

Student::Student(Student &obj) //copy constructor, when object is copied, allocate new memory space for the score pointer
{
	std::cout << "Copy constructor is called.\n";
	student_num++;
	name = obj.name;
	score_num = obj.score_num;
	score = obj.score;
}

//Student::~Student() //destructor, de-allocate the dynamically allocated memory 
//{
//	delete[] score;
//}

void Student::SetName(std::string n) //modify student's name
{
	name = n;
}
void Student::SetScore(double s, int index) //set student's score, index is used to locate the score 
{
	score[index] = s;
}

double Student::GetScore(int index) const //return score stored in array
{
	return score[index];
}

std::string Student::GetName() const //return student's name 
{
	return name;
}

void Student::operator=(const Student &obj)
{
	student_num++;
	name = obj.name;
	delete[] score; //to delete array previously stored
	score = new double[obj.score_num]; //request new space
	for (int i = 0; i < obj.score_num; i++)
		score[i] = DEFAULT_SCORE;
}



}

3) main program
{

#include "Student.h"
#include <iostream>


int main()
{

	Student s1("Yu Miao", 2);
	s1.SetScore(100, 0);
	s1.SetScore(98, 1);

	Student s2("Yingying", 10);
		s2 = s1;

	std::cout << "s2 score_1: " << s2.GetScore(0) << "\n";
	return 0;
}




}

}

7. Return value of overloading = operator 
{

1) class specification 
{


#ifndef STUDENT
#define STUDENT

#include <string>


class Student
{
private:
	static int student_num;
	std::string name;
	double *score;
	int score_num;

public:
	Student(std::string n, int num);
	Student(Student &obj);
	//~Student();

	void SetName(std::string n);
	void SetScore(double s, int index);

	double GetScore(int index) const;
	std::string GetName() const;
	const Student operator= (const Student &obj);

};

#endif


}

2) class implementation
{


#include "Student.h"
#include <string>
#include <iostream>

const double DEFAULT_SCORE = 0.0;

int Student::student_num = 0; //define static member variable


Student::Student(std::string n, int num) //constructor, will allocate memory for score
{
	student_num++;
	name = n;
	score_num = num;
	score = new double[num];

	//initialize array with default score 
	for (int i = 0; i<num; i++)
	{
		score[i] = DEFAULT_SCORE;
	}
}

Student::Student(Student &obj) //copy constructor, when object is copied, allocate new memory space for the score pointer
{
	std::cout << "Copy constructor is called.\n";
	student_num++;
	name = obj.name;
	score_num = obj.score_num;
	score = obj.score;
}

//Student::~Student() //destructor, de-allocate the dynamically allocated memory 
//{
//	delete[] score;
//}

void Student::SetName(std::string n) //modify student's name
{
	name = n;
}
void Student::SetScore(double s, int index) //set student's score, index is used to locate the score 
{
	score[index] = s;
}

double Student::GetScore(int index) const //return score stored in array
{
	return score[index];
}

std::string Student::GetName() const //return student's name 
{
	return name;
}

const Student Student::operator=(const Student &obj)
{
	student_num++;
	name = obj.name;
	delete[] score; //to delete array previously stored
	score = new double[obj.score_num]; //request new space
	for (int i = 0; i < obj.score_num; i++)
		score[i] = DEFAULT_SCORE;

	return *this;
}



}

3) main program 
{


#include "Student.h"
#include <iostream>


int main()
{

	Student s1("Yu Miao", 2);
	s1.SetScore(100, 0);
	s1.SetScore(98, 1);

	Student s2("Yingying", 10);

	Student s3("Maqiang", 20);

	s1 = s2 = s3;

	std::cout << "s1 score_1: " << s1.GetScore(0) << "\n";
	return 0;
}



}

}

8.9. Overloading math operators: +, -, ++, -- (use Feet_inch class)
{

1) class specification 
{

#ifndef FEETINCHE_H
#define FEETINCHE_H

class Feet_inch
{
private:
	int feet; //hold value of feet 
	int inch; //hold value of inch 
	void Simplify(); //to simplify feet and inch value. It will check if inch >= 12 or < 0. If inch >= 12, transfer to corresponding value of feet; if inch < 0, subtract from feet and get the final value 
public:
	//constructor 
	Feet_inch(int f = 0, int i = 0) //constructor, initialize values for feet and inch 
	{
		feet = f; inch = i; Simplify();
	}

	/* Mutator */
	void SetFeet(int f)
	{
		feet = f;
	}
	void SetInch(int i)
	{
		inch = i; Simplify(); //after each setting, has to be simplified
	}

	/* Accessor */
	int GetFeet() const
	{
		return feet;
	}
	int GetInch() const
	{
		return inch;
	}

	/* Operator function */
	//+, - operator, add or subtract an int value to inches, then call simplify function to simplify. Return the simplified 
	Feet_inch operator+ (int i);
	Feet_inch operator+ (const Feet_inch &d);
	Feet_inch operator- (int i);
	Feet_inch operator- (const Feet_inch &d);
	//++ operator
	Feet_inch operator++ ();
	Feet_inch operator++ (int);
	Feet_inch operator-- ();
	Feet_inch operator-- (int);
};

#endif

}

2) class implementation 
{

#include "Feet_inch.h"

void Feet_inch::Simplify()
{
	if (inch < 0) //when inch is less than zero, subtract from feet or inch
	{
		feet -= (-inch) / 12 + 1;
		inch += ((-inch) / 12 + 1) * 12;
	}

	else if (inch >= 12) //when inch is greater than 12, add to feet
	{
		feet += inch / 12;
		inch = inch % 12;
	}
}

Feet_inch Feet_inch::operator+ (int i)
{
	Feet_inch temp;
	temp.feet = feet;
	temp.inch = inch + i;
	if (temp.inch < 0 || temp.inch >= 12)
		temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator+ (const Feet_inch &d)
{
	Feet_inch temp;
	temp.feet = feet + d.feet;
	temp.inch = inch + d.inch;
	temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator- (int i)
{
	Feet_inch temp;
	temp.feet = feet;
	temp.inch = inch - i;
	if (temp.inch < 0 || temp.inch >= 12)
		temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator- (const Feet_inch &d)
{
	Feet_inch temp;
	temp.feet = feet - d.feet;
	temp.inch = inch - d.inch;
	temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator++ ()
{
	inch++;
	if (inch < 0 || inch >= 12)
		Simplify();
	return *this;
}

Feet_inch Feet_inch::operator++ (int)
{
	Feet_inch temp = *this; //temp object to hold current value
	inch++;
	if (inch < 0 || inch >= 12)
		Simplify();
	return temp;
}

Feet_inch Feet_inch::operator-- ()
{
	inch--;
	if (inch < 0 || inch >= 12)
		Simplify();
	return *this;
}

Feet_inch Feet_inch::operator-- (int)
{
	Feet_inch temp = *this;
	inch--;
	if (inch < 0 || inch >= 12)
		Simplify();
	return temp;
}

}

3) main program 
{

#include <iostream>
#include "Feet_inch.h"

int main()
{
	Feet_inch d1(2, 4);

	std::cout << "Before addition, distance is " << d1.GetFeet() << " feet " << d1.GetInch() << " inch.\n";

	d1 = d1 + 8;

	std::cout << "After addition, distance is " << d1.GetFeet() << " feet " << d1.GetInch() << " inch.\n";

	d1--;
	std::cout << "After decrement operator, distance is: " << d1.GetFeet() << " feet " << d1.GetInch() << " inch.\n";

	d1 = d1 - 1;

	std::cout << "After subtraction, distance is " << d1.GetFeet() << " feet " << d1.GetInch() << " inch.\n";

	Feet_inch d2(1, 5);
	std::cout << "\ndistance 2 is: " << d2.GetFeet() << " feet " << d2.GetInch() << " inch. Add to distance 1:\n";
	d1 = d1 + d2;
	std::cout << "\ndistance 1 now becomes: " << d1.GetFeet() << " feet " << d1.GetInch() << " inch.\n";
	return 0;
}

}

}

10. Overloading relational operator (use Feet_inch class)
{

1) class specification
{

#ifndef FEETINCHE_H
#define FEETINCHE_H

class Feet_inch
{
private:
	int feet; //hold value of feet 
	int inch; //hold value of inch 
	void Simplify(); //to simplify feet and inch value. It will check if inch >= 12 or < 0. If inch >= 12, transfer to corresponding value of feet; if inch < 0, subtract from feet and get the final value 
public:
	//constructor 
	Feet_inch(int f = 0, int i = 0) //constructor, initialize values for feet and inch 
	{
		feet = f; inch = i; Simplify();
	}

	/* Mutator */
	void SetFeet(int f)
	{
		feet = f;
	}
	void SetInch(int i)
	{
		inch = i; Simplify(); //after each setting, has to be simplified
	}

	/* Accessor */
	int GetFeet() const
	{
		return feet;
	}
	int GetInch() const
	{
		return inch;
	}

	/* Operator function */
	//+, - operator, add or subtract an int value to inches, then call simplify function to simplify. Return the simplified 
	Feet_inch operator+ (int i);
	Feet_inch operator+ (const Feet_inch &d);
	Feet_inch operator- (int i);
	Feet_inch operator- (const Feet_inch &d);
	//++ operator
	Feet_inch operator++ ();
	Feet_inch operator++ (int);
	Feet_inch operator-- ();
	Feet_inch operator-- (int);
	// relational operator
	bool operator> (const Feet_inch &right);
	bool operator< (const Feet_inch &right);
	bool operator== (const Feet_inch &right);
	
};

#endif


}

2) class implementation
{

#include "Feet_inch.h"

void Feet_inch::Simplify()
{
	if (inch < 0) //when inch is less than zero, subtract from feet or inch
	{
		feet -= (-inch) / 12 + 1;
		inch += ((-inch) / 12 + 1) * 12;
	}

	else if (inch >= 12) //when inch is greater than 12, add to feet
	{
		feet += inch / 12;
		inch = inch % 12;
	}
}

Feet_inch Feet_inch::operator+ (int i)
{
	Feet_inch temp;
	temp.feet = feet;
	temp.inch = inch + i;
	if (temp.inch < 0 || temp.inch >= 12)
		temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator+ (const Feet_inch &d)
{
	Feet_inch temp;
	temp.feet = feet + d.feet;
	temp.inch = inch + d.inch;
	temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator- (int i)
{
	Feet_inch temp;
	temp.feet = feet;
	temp.inch = inch - i;
	if (temp.inch < 0 || temp.inch >= 12)
		temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator- (const Feet_inch &d)
{
	Feet_inch temp;
	temp.feet = feet - d.feet;
	temp.inch = inch - d.inch;
	temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator++ ()
{
	inch++;
	if (inch < 0 || inch >= 12)
		Simplify();
	return *this;
}

Feet_inch Feet_inch::operator++ (int)
{
	Feet_inch temp = *this; //temp object to hold current value
	inch++;
	if (inch < 0 || inch >= 12)
		Simplify();
	return temp;
}

Feet_inch Feet_inch::operator-- ()
{
	inch--;
	if (inch < 0 || inch >= 12)
		Simplify();
	return *this;
}

Feet_inch Feet_inch::operator-- (int)
{
	Feet_inch temp = *this;
	inch--;
	if (inch < 0 || inch >= 12)
		Simplify();
	return temp;
}

bool Feet_inch::operator> (const Feet_inch &right)
{
	if (feet > right.feet)
		return true;
	else if (feet == right.feet)
	{
		if (inch > right.inch)
			return true;
		else
			return false;
	}
	else
		return false;
}


bool Feet_inch::operator< (const Feet_inch &right)
{
	if (feet < right.feet)
		return true;
	else if (feet == right.feet)
	{
		if (inch < right.inch)
			return true;
		else
			return false;
	}
	else
		return false;	
}
bool Feet_inch::operator== (const Feet_inch &right)
{
	if (feet == right.feet && inch == right.inch)
		return true;
	else
		return false;
}

}

3) main program 
{

#include <iostream>
#include "Feet_inch.h"

int main()
{
	Feet_inch d1;
	Feet_inch d2;
	Feet_inch d3;
	
	d2 = d1++;
	d2 = d1 + 4;
	d3 = d3 + 5;

	std::cout << "d2: " << d2.GetFeet() << " feet " << d2.GetInch() << " inch\n";
	std::cout << "d3: " << d3.GetFeet() << " feet " << d3.GetInch() << " inch\n";

	std::cout << "Comparing d2 and d3...";
	if (d2 > d3)
		std::cout << "d2 > d3.\n";
	else if (d2 < d3)
		std::cout << "d2 < d3.\n";
	else if (d2 == d3)
		std::cout << "d2 == d3.\n";
	else
		std::cout << "Result not applicable.\n";

	return 0;
}

}

}

11. Overloading stream insertion (<<) and stream extraction (>>) operator (use Feet_inch class)
{

1) class specification
{

#ifndef FEETINCHE_H
#define FEETINCHE_H
#include <iostream>

class Feet_inch
{
private:
	int feet; //hold value of feet 
	int inch; //hold value of inch 
	void Simplify(); //to simplify feet and inch value. It will check if inch >= 12 or < 0. If inch >= 12, transfer to corresponding value of feet; if inch < 0, subtract from feet and get the final value 
public:
	//constructor 
	Feet_inch(int f = 0, int i = 0) //constructor, initialize values for feet and inch 
	{
		feet = f; inch = i; Simplify();
	}

	/* Mutator */
	void SetFeet(int f)
	{
		feet = f;
	}
	void SetInch(int i)
	{
		inch = i; Simplify(); //after each setting, has to be simplified
	}

	/* Accessor */
	int GetFeet() const
	{
		return feet;
	}
	int GetInch() const
	{
		return inch;
	}

	/* Operator function */
	//+, - operator, add or subtract an int value to inches, then call simplify function to simplify. Return the simplified 
	Feet_inch operator+ (int i);
	Feet_inch operator+ (const Feet_inch &d);
	Feet_inch operator- (int i);
	Feet_inch operator- (const Feet_inch &d);
	//++ operator
	Feet_inch operator++ ();
	Feet_inch operator++ (int);
	Feet_inch operator-- ();
	Feet_inch operator-- (int);
	//relational operator
	bool operator> (const Feet_inch &right);
	bool operator< (const Feet_inch &right);
	bool operator== (const Feet_inch &right);
	//stream insertion operator
	friend std::ostream& operator<< (std::ostream &strm, const Feet_inch &obj)
	{
		strm << obj.feet << " feet, " << obj.inch << " inches";
		return strm;
	}
	//stream extraction operator
	friend std::istream& operator>> (std::istream &strm, Feet_inch &obj)
	{
		std::cout << "Please input the feet: ";
		strm >> obj.feet;
		std::cout << "Please input the inch: ";
		strm >> obj.inch;
		obj.Simplify(); //to simplify
		return strm;
	}
	
};

#endif


}

2) class implementation
{

#include "Feet_inch.h"

void Feet_inch::Simplify()
{
	if (inch < 0) //when inch is less than zero, subtract from feet or inch
	{
		feet -= (-inch) / 12 + 1;
		inch += ((-inch) / 12 + 1) * 12;
	}

	else if (inch >= 12) //when inch is greater than 12, add to feet
	{
		feet += inch / 12;
		inch = inch % 12;
	}
}

Feet_inch Feet_inch::operator+ (int i)
{
	Feet_inch temp;
	temp.feet = feet;
	temp.inch = inch + i;
	if (temp.inch < 0 || temp.inch >= 12)
		temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator+ (const Feet_inch &d)
{
	Feet_inch temp;
	temp.feet = feet + d.feet;
	temp.inch = inch + d.inch;
	temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator- (int i)
{
	Feet_inch temp;
	temp.feet = feet;
	temp.inch = inch - i;
	if (temp.inch < 0 || temp.inch >= 12)
		temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator- (const Feet_inch &d)
{
	Feet_inch temp;
	temp.feet = feet - d.feet;
	temp.inch = inch - d.inch;
	temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator++ ()
{
	inch++;
	if (inch < 0 || inch >= 12)
		Simplify();
	return *this;
}

Feet_inch Feet_inch::operator++ (int)
{
	Feet_inch temp = *this; //temp object to hold current value
	inch++;
	if (inch < 0 || inch >= 12)
		Simplify();
	return temp;
}

Feet_inch Feet_inch::operator-- ()
{
	inch--;
	if (inch < 0 || inch >= 12)
		Simplify();
	return *this;
}

Feet_inch Feet_inch::operator-- (int)
{
	Feet_inch temp = *this;
	inch--;
	if (inch < 0 || inch >= 12)
		Simplify();
	return temp;
}

bool Feet_inch::operator> (const Feet_inch &right)
{
	if (feet > right.feet)
		return true;
	else if (feet == right.feet)
	{
		if (inch > right.inch)
			return true;
		else
			return false;
	}
	else
		return false;
}


bool Feet_inch::operator< (const Feet_inch &right)
{
	if (feet < right.feet)
		return true;
	else if (feet == right.feet)
	{
		if (inch < right.inch)
			return true;
		else
			return false;
	}
	else
		return false;
}
bool Feet_inch::operator== (const Feet_inch &right)
{
	if (feet == right.feet && inch == right.inch)
		return true;
	else
		return false;
}

}

3) main program 
{

#include <iostream>
#include "Feet_inch.h"

int main()
{
	Feet_inch d1;
	std::cout << d1 << "\n";
	std::cin >> d1;
	std::cout << "After changing, d1: " << d1 << "\n";

	return 0;
}


}

}

12.13 Overloading [] operator (use Int_array class)
{

1) class specification
{

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
};

#endif

}

2) class implementation
{

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
	if (index >= size || index < 0) //over the boundary 
	{
		std::cout << "Error: subscript out of range!\n";
		exit(0);
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



}

3) main program
{

#include <iostream>
#include "Int_array.h"

int main()
{
	Int_array num(5);
	
	for (int i = 0; i < 5; i++)
		num[i] = i;

	Int_array num2(3);

	num2 = num;

	std::cout << num2 << "\n";
	std::cout << num2[6] << "\n";

	return 0;
}


}

}

14. Object conversion (convert Feet_inch object to Student object)
{

1) class specification 
{

> Feet_inch
{

#ifndef FEETINCHE_H
#define FEETINCHE_H
#include <iostream>
#include "Student.h"

class Feet_inch
{
private:
	int feet; //hold value of feet 
	int inch; //hold value of inch 
	void Simplify(); //to simplify feet and inch value. It will check if inch >= 12 or < 0. If inch >= 12, transfer to corresponding value of feet; if inch < 0, subtract from feet and get the final value 
public:
	//constructor 
	Feet_inch(int f = 0, int i = 0) //constructor, initialize values for feet and inch 
	{
		feet = f; inch = i; Simplify();
	}

	/* Mutator */
	void SetFeet(int f)
	{
		feet = f;
	}
	void SetInch(int i)
	{
		inch = i; Simplify(); //after each setting, has to be simplified
	}

	/* Accessor */
	int GetFeet() const
	{
		return feet;
	}
	int GetInch() const
	{
		return inch;
	}

	/* Operator function */
	//+, - operator, add or subtract an int value to inches, then call simplify function to simplify. Return the simplified 
	Feet_inch operator+ (int i);
	Feet_inch operator+ (const Feet_inch &d);
	Feet_inch operator- (int i);
	Feet_inch operator- (const Feet_inch &d);
	//++ operator
	Feet_inch operator++ ();
	Feet_inch operator++ (int);
	Feet_inch operator-- ();
	Feet_inch operator-- (int);
	//relational operator
	bool operator> (const Feet_inch &right);
	bool operator< (const Feet_inch &right);
	bool operator== (const Feet_inch &right);
	//stream insertion operator
	friend std::ostream& operator<< (std::ostream &strm, const Feet_inch &obj)
	{
		strm << obj.feet << " feet, " << obj.inch << " inches";
		return strm;
	}
	//stream extraction operator
	friend std::istream& operator>> (std::istream &strm, Feet_inch &obj)
	{
		std::cout << "Please input the feet: ";
		strm >> obj.feet;
		std::cout << "Please input the inch: ";
		strm >> obj.inch;
		obj.Simplify(); //to simplify
		return strm;
	}
	
	/* Conversion function */
	operator Student();
};

#endif






}

> Student 
{


#ifndef STUDENT
#define STUDENT

#include <string>
#include <iostream>


class Student
{
private:
	static int student_num;
	std::string name;
	double *score;
	int score_num;

public:
	Student(std::string n, int num);
	Student(Student &obj);
	~Student()
	{
		std::cout << "Destructor called.\n";
		delete[] score;
	}

	void SetName(std::string n);
	void SetScore(double s, int index);

	double GetScore(int index) const;
	std::string GetName() const;
	const Student operator= (const Student &obj);
	Student operator++ ();
	Student operator++(int);
	double &operator[] (const int &index);
};

#endif


}

}

2) class implementation
{

> Feet_inch
{

#include "Feet_inch.h"
#include <iostream>

void Feet_inch::Simplify()
{
	if (inch < 0) //when inch is less than zero, subtract from feet or inch
	{
		feet -= (-inch) / 12 + 1;
		inch += ((-inch) / 12 + 1) * 12;
	}

	else if (inch >= 12) //when inch is greater than 12, add to feet
	{
		feet += inch / 12;
		inch = inch % 12;
	}
}

Feet_inch Feet_inch::operator+ (int i)
{
	Feet_inch temp;
	temp.feet = feet;
	temp.inch = inch + i;
	if (temp.inch < 0 || temp.inch >= 12)
		temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator+ (const Feet_inch &d)
{
	Feet_inch temp;
	temp.feet = feet + d.feet;
	temp.inch = inch + d.inch;
	temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator- (int i)
{
	Feet_inch temp;
	temp.feet = feet;
	temp.inch = inch - i;
	if (temp.inch < 0 || temp.inch >= 12)
		temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator- (const Feet_inch &d)
{
	Feet_inch temp;
	temp.feet = feet - d.feet;
	temp.inch = inch - d.inch;
	temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator++ ()
{
	inch++;
	if (inch < 0 || inch >= 12)
		Simplify();
	return *this;
}

Feet_inch Feet_inch::operator++ (int)
{
	Feet_inch temp = *this; //temp object to hold current value
	inch++;
	if (inch < 0 || inch >= 12)
		Simplify();
	return temp;
}

Feet_inch Feet_inch::operator-- ()
{
	inch--;
	if (inch < 0 || inch >= 12)
		Simplify();
	return *this;
}

Feet_inch Feet_inch::operator-- (int)
{
	Feet_inch temp = *this;
	inch--;
	if (inch < 0 || inch >= 12)
		Simplify();
	return temp;
}

bool Feet_inch::operator> (const Feet_inch &right)
{
	if (feet > right.feet)
		return true;
	else if (feet == right.feet)
	{
		if (inch > right.inch)
			return true;
		else
			return false;
	}
	else
		return false;
}


bool Feet_inch::operator< (const Feet_inch &right)
{
	if (feet < right.feet)
		return true;
	else if (feet == right.feet)
	{
		if (inch < right.inch)
			return true;
		else
			return false;
	}
	else
		return false;
}
bool Feet_inch::operator== (const Feet_inch &right)
{
	if (feet == right.feet && inch == right.inch)
		return true;
	else
		return false;
}

Feet_inch::operator Student()
{
	Student s0("FromFeet", feet);
	for (int i = 0; i < feet; i++)
		s0[i] = inch;
	std::cout << "node_1 reached.\n" << "\n";
	return s0;
}

}

> Student
{


#include "Student.h"
#include <string>
#include <iostream>
#include <cstdlib>

const double DEFAULT_SCORE = 0.0;

int Student::student_num = 0; //define static member variable


Student::Student(std::string n, int num) //constructor, will allocate memory for score
{
	std::cout << "Creating constructor is called.\n";
	student_num++;
	name = n;
	score_num = num;
	score = new double[num];

	//initialize array with default score 
	for (int i = 0; i<num; i++)
	{
		score[i] = DEFAULT_SCORE;
	}
}

Student::Student(Student &obj) //copy constructor, when object is copied, allocate new memory space for the score pointer
{
	std::cout << "Copy constructor is called.\n";
	student_num++;
	name = obj.name;
	score_num = obj.score_num;
	score = new double[score_num];
	for (int i = 0; i < score_num; i++)
		score[i] = obj.score[i];
}

Student::~Student() //destructor, de-allocate the dynamically allocated memory 
{
	student_num--;
	//delete[] score;
}

void Student::SetName(std::string n) //modify student's name
{
	name = n;
}
void Student::SetScore(double s, int index) //set student's score, index is used to locate the score 
{
	score[index] = s;
}

double Student::GetScore(int index) const //return score stored in array
{
	return score[index];
}

std::string Student::GetName() const //return student's name 
{
	return name;
}

const Student Student::operator=(const Student &obj)
{
	std::cout << "node_2 reached\n";
	student_num++;
	std::cout << "node_3 reached\n";
	name = obj.name;
	std::cout << "node_4 reached\n";
	delete[] score; //to delete array previously stored
	std::cout << "node_5 reached\n";
	score = new double[obj.score_num]; //request new space
	std::cout << "node_6 reached\n";
	for (int i = 0; i < obj.score_num; i++)
		score[i] = DEFAULT_SCORE;
	std::cout << "node_7 reached\n";
	return *this;
}

Student Student::operator++ ()
{
	//add 1 to all the scores
	for (int i = 0; i < score_num; i++)
		score[i] += 1;
	return *this;
}

Student Student::operator++(int)
{
	for (int i = 0; i < score_num; i++)
		score[i]++;

	return *this;
}

double &Student::operator[] (const int &index)
{
	if (index < 0 || index >= score_num)
	{
		std::cout << "Invalid subscript, quiting...";
		exit(0);
	}
	return score[index];
}

}

}

3) main program 
{

#include <iostream>
#include "Int_array.h"
#include "Student.h"
#include "Feet_inch.h"

int main()
{
	Student s1("1", 5);
	Student s2("2", 5);
	Feet_inch d1(5, 14);

	s2 = d1;

	std::cout << "Feet_inch to student conversion complete, student name: " << s2.GetName() << "\n";

	return 0;
}



}

}

Case Study: Creating a String Class 
{

1) Mystring.h
{

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class Mystring
{
private:
	/* Member variables */
	char *str; //hold the memory space dynamically allocated to store the address of a string
	int array_capacity; //hold the capacity of the object, capacity is the memory space allocated to str
	
	/* Working functions for C-string */
	int StrSize(const char *str) const; //accepts a pointer to C-string, returns an int, showing the size of the C-string, number of characters not including the null terminator
	void StrCat(char *string1, const char *string2); //string concatenate function, attach str2 to str1, str1 should be worked so it has enough room for the appending
	void StrCpy(char *destination, const char *source); //copy source to destination, content in destination will be cleared
	int StrCmp(const char *string1, const char *string2); //string compare. Return value: 1: string1 is after string2; -1: string1 is before string2; 0: string 1 == string 2
	int StrStr(char *array, char *keyword, int x=0); //string search, return the subscript of where the keyword begins. If no match found, return -1, underflow to the largest unsigned. Search start from x=0.
	char *to_c_str(int num); //integer to C_string function
	
	/* Memory allocation */
	void AllocateMemory(int num); //will allocate memory big enough to hold num characters, increase stepsize = 2^4
	
public:
	/* Constructor */
	Mystring(); //default constructor, create a string that hold 15 characters, allocate 15+1 space, the extra one is for the null terminator
	Mystring(const char *initial); //define and initialize with a "str" (string literal)
	Mystring(const char *initial, int num, int start=0); //initialize with first num characters in initial, start from position indicated by start, if initial is not that long, copy to the end, default start index is zero
	Mystring(char letter, int num=1); //initialize with multiple letter, amount: num
	Mystring(const Mystring &obj); //copy constructor
	Mystring(const Mystring &obj, int num, int start=0); //initialize with num characters in another Mystring object, start at start. If obj.str is not long enough, copy to the end
	Mystring(int num); //initialize with integer
	
	/* Destructor */
	~Mystring();
	
	
	/* Accessor */
	int size() const; //return size of the object, number of characters, not including end-null
	int capacity() const; //return capacity of the object, memory size allocated to the str 
	char GetChar(int index); //return index-th element
	
	
	/* String Member Functions */
	// Mystring.append()
	Mystring append(int num, char ch); //appends num copies of ch to str 
	Mystring append(const Mystring &obj, int x=0); //appends Mystring object to str, also accepts "C-string", start from the x-th character, default x = 0.
	Mystring append(const Mystring &obj, int x, int n); //appends Mystring object to str, also accepts "C-string", start from the x-th character, total length is n, if obj is not long enough, append to the end
	
	// Mystring.assign()
	Mystring& assign(int n, const char ch); //assigns n copies of ch to *this string
	Mystring& assign(const Mystring &obj); //assigns Mystring to *this string 
	Mystring& assign(const Mystring &obj, int n); //assigns first n characters to *this string
	Mystring& assign(const Mystring &obj, int x, int n); //assign n chs to *this string, start from x in obj
	
	// Mystring.back()
	char back(); //return the last character in Mystring
	
	// Mystring.c_str()
	char *c_str(); //convert str into a C-string, return the pointer to the C-string
	
	// Mystring.clear()
	void clear(); //clear content in str, not influencing memory space allocated
	
	// Mystring.compare()
	int compare(const Mystring &str2);
	int compare(int x, int n, const Mystring &str2); //start from x, continue for n character
	
	// Mystring.copy()
	Mystring copy(const Mystring &str2, int x, int n); //copy substring of str2 to *this, start from x, for n characters
	
	// Mystring.empty()
	bool empty(); //returns true if *this str is empty
	
	// Mystring.erase()
	Mystring& erase(int x, int n); //erase n characters start from x
	
	// Mystring.find()
	unsigned find(const Mystring &obj, int x=0); //search if *this string contains a substring obj, starts at x in *this
	
	// Mystring.front()
	char front(); //returns the first character in the str 
	
	// Mystring.insert()
	Mystring insert(int x, char ch, int n=1); //insert several ch in position x, default number is 1
	Mystring insert(const Mystring &obj, int x = 0); //insert a Mystring object in position x, default position is x=0
	
	// Mystring.replace()
	Mystring& replace(int x, int n, const Mystring &obj); //insert obj into x in *this str, and n characters in *this str will be replaced by characters in obj
	
	// Mystring.resize()
	void resize(int n, char ch = '\0'); //resize *this, if n is greater than current size, fill with ch (default '\0'); if n is smaller than current size, truncate to n
	
	// Mystring.substr(int x, int n)
	Mystring substr(int x, int n) const; //return a substring of *this 
	Mystring substr(int x) const; //return a substring of *this 
	
	// Mystring.swap()
	void swap(Mystring &right); //swap *this and right 
	
	/* Operator */
	// =
	const Mystring operator= (const Mystring &right);
	const Mystring operator= (const char* initial);
	// []
	char& operator[] (unsigned int index);
	const char operator[] (unsigned int index) const; 
	// += and +
	Mystring operator+= (const Mystring &right); //Mystring += Mystring
	Mystring operator+= (const char ch); //Mystring += char
	Mystring operator+ (const Mystring &right); //Mystring + Mystring
	Mystring operator+ (const char *right); //Mystring + C-string
	Mystring operator+ (const char ch); //Mystring + char
	
	/* Friend */
	// <<
	friend std::ostream& operator<< (std::ostream &out, const Mystring &obj);
	// +
	friend Mystring operator+ (const char* lhs, const Mystring &rhs); //C-string + Mystring
	friend Mystring operator+ (const char ch, const Mystring &obj); //char + Mystring
	// -
	friend Mystring operator- (Mystring &lhs, const Mystring &right); //Mystring - Mystring
	// >>
	friend std::istream& operator>> (std::istream &in, Mystring &obj);
	// getline() function 
	friend std::istream& getline(std::istream &in, Mystring &obj, char delim = '\n');
	// relational operator
	friend bool operator> (const Mystring &lhs, const Mystring &rhs);
	friend bool operator== (const Mystring &lhs, const Mystring &rhs);
	friend bool operator>= (const Mystring &lhs, const Mystring &rhs);
	friend bool operator< (const Mystring &lhs, const Mystring &rhs);
	friend bool operator<= (const Mystring &lhs, const Mystring &rhs);
	friend bool operator!= (const Mystring &lhs, const Mystring &rhs);
	
};



#endif


}

2) Mystring.cpp
{

#include "Mystring.h"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <vector>

/* Working functions for C-string */
//string size 
int Mystring::StrSize(const char *str) const
{
	int counter = 0;
	while (str[counter] != '\0')
		counter++;
	return counter;
}

//string concatnate, make sure str1 has enough room for str2
void Mystring::StrCat(char *string1, const char *string2)
{
	int counter = 0;
	while (string1[counter] != '\0')
		counter++;
	//at this point, string1[counter] = '\0'

	int i = 0; //another counter to copy string2 to string 1
	while (string2[i] != '\0')
		string1[counter + i] = string2[i++];

	string1[counter + i] = '\0'; //add a null character at the end of the array	
}

//string copy function, destination will be cleared, make sure destination has enough room
void Mystring::StrCpy(char *destination, const char *source)
{
	int i = 0;
	while (source[i] != '\0')
		destination[i] = source[i++];
	destination[i] = '\0';	
}

//string compare function, 1: string1 is after string2; -1: string1 is before string2; 0: string1 == string2
int Mystring::StrCmp(const char *string1, const char *string2)
{
	int i = 0;
	while (string1[i] != '\0' && string2[i] != '\0')
	{
		if (string1[i] > string2[i])
			return 1;
		else if (string1[i] < string2[i])
			return -1;
		else
			i++;
	}

	//after the while loop, one of the string come to end,check the final result
	if (string1[i] == string2[i])
		return 0;
	else if (string1[i] > string2[i])
		return 1;
	else
		return -1;
}

//string search, return the subscript of where the keyword begins. If no match found, return -1, underflow to the largest unsigned
int Mystring::StrStr(char *array, char *keyword, int x)
{
	int size_array = StrSize(array);
	int size_keyword = StrSize(keyword);
	
	for (int i = x; i<(size_array - size_keyword); i++)
	{
		int j;
		for (j = 0; j<size_keyword; j++)
			if (!(array[i + j] == keyword[j]))
				break;
		if (j == size_keyword)
			return i;
	}
	//if program proceeds here, it means no match can be found, return nullptr
	return -1;	
}

//integer to C_string function
char* Mystring::to_c_str(int num)
{
	//when num == 0
	if (num == 0)
	{
		char *string = new char[2];
		string[0] = '0';
		string[1] = '\0';
		return string;
	}

	//if the number is not zero
	//figure out how long is the number
	int num_copy;
	if (num < 0)
		num_copy = -num; //if number is negative, first calculate the absolute value.
	else
		num_copy = num;

	int size = 0;
	while (num_copy % 10 != 0)
	{
		num_copy /= 10;
		size++;
	}
	size -= 1;

	//now, size represents the number of digit, which means the magnitude of the number being transformed. For example, if number is 123, then size = 2 (10^2)
	//now, you need to request a memory space to store the string. The size should be size+2.
	int additional_lot;
	if (num < 0)
		additional_lot = 3;
	else
		additional_lot = 2;

	char *string = new char[size + additional_lot];

	//to get the divide digit
	int digit = 1;
	for (int i = 0; i<size; i++)
		digit *= 10;

	//to transform the number to string
	int i;
	num_copy = num;
	if (num < 0)
	{
		for (i = 1; i <= size + 1; i++)
		{
			string[i] = -num_copy / digit + 48;
			num_copy %= digit;
			digit /= 10;
		}
		string[0] = '-'; //place the negative sign in front of the string 
		string[i] = '\0';
		//return address of the string
		return string;
	}
	else
	{
		for (i = 0; i <= size; i++)
		{
			string[i] = num_copy / digit + 48;
			num_copy %= digit;
			digit /= 10;
		}
		string[i] = '\0';
		//return address of the string
		return string;
	}
	
}


/* Memory allocation */
void Mystring::AllocateMemory(int num) //will allocate memory big enough to hold num characters, increase stepsize = 2^4
{
	if (array_capacity != 0) //if there is pre-allocated memory
	{
		delete[] str; //delete pre-allocated memory
		array_capacity = 0; //reset capacity
	}
	
	while (array_capacity - 1 < num)
		array_capacity += 16;
	array_capacity--; //exclude '\0'
	
	/* Allocate memory space */
	str = new char [array_capacity+1];

	/* Initialize with null */
	for (int i=0; i<array_capacity+1; i++)
		str[i] = '\0';
}


/* Constructor */
//default constructor
Mystring::Mystring()
{
	array_capacity = 15; //default capacity of str
	str = new char [array_capacity+1]; //create a memory space, extra 1 is for the '\0'
	for (int i=0; i<array_capacity+1; i++) //initialize each element with '\0'
		str[i] = '\0';
}

//initialize with a string literal
Mystring::Mystring(const char *initial)
{
	int initial_size = StrSize(initial); //hold the size of input
	array_capacity = 0;
	
	//Allocate enough memory 
	AllocateMemory(initial_size);
	
	//copy initial content into str
	StrCpy(str, initial);	
	
}

//initialize with first num characters in initial, start from position indicated by start
//if initial is not that long, copy to the end 
//default start index is zero
Mystring::Mystring(const char *initial, int num, int start)
{
	/* Check input */
	if (start < 0 || num < 0)
	{
		std::cout << "Invalid start_position or length input, program shutting down...\n";
		exit(0);
	}
	
	/* Variable definition */
	array_capacity = 0;
	int char_num; //number of characters to be stored
	bool exceed; //flag, true: initial is not that long; false = initial is long enough
	
	/* Determine whether initial is long enough or nor */
	if (StrSize(initial) >= start+num)
		exceed = false;
	else 
		exceed = true;
	
	/* Determine number of characters to be stored in str */
	if (exceed)
	{
		char_num = StrSize(initial) - start;
	}
	else
		char_num = num;
	
	/* Determine memory space needed */
	array_capacity = 0;
	AllocateMemory(char_num);
	
	/* Copy content */
	int i = 0;
	for (i; i<char_num; i++)
		str[i] = initial[i+start];
	str[i] = '\0';
	
}

//initialize with multiple letter, amount: num 
Mystring::Mystring(char letter, int num)
{
	/* find out enough space */
	array_capacity = 0;
	while (array_capacity - 1 < num)
		array_capacity += 16;
	array_capacity--; //exclude '\0'
	
	/* Allocate memory space */
	str = new char [array_capacity+1];

	/* Copy letter to str */
	int i=0;
	for (i; i<num; i++)
		str[i] = letter;
	
	/* add a '\0' at the end */
	str[i] = '\0';
}

//copy constructor, initialize with a Mystring object
Mystring::Mystring(const Mystring &obj)
{
	array_capacity = obj.array_capacity;
	str = new char [array_capacity];
	//copy content
	StrCpy(str, obj.str);
}

//initialize with  num characters in another Mystring object, beginning at start (default = 0)
Mystring::Mystring(const Mystring &obj, int num, int start)
{
	/* Check input */
	if (start < 0 || num < 0)
	{
		std::cout << "Invalid start_position or length input, program shutting down...\n";
		exit(0);
	}

	/* Variable definition */
	array_capacity = 0;
	int char_num; //number of characters to be stored
	bool exceed; //flag, true: obj.str is not that long; false = obj.str is long enough
	
	/* Determine whether obj.str is long enough or nor */
	if (StrSize(obj.str) >= start+num)
		exceed = false;
	else 
		exceed = true;
	
	/* Determine number of characters to be stored in str */
	if (exceed)
	{
		char_num = StrSize(obj.str) - start;
	}
	else
		char_num = num;
	
	/* Determine memory space needed */
	array_capacity = 0;
	AllocateMemory(char_num);
	
	/* Copy content */
	int i = 0;
	for (i; i<char_num; i++)
		str[i] = obj.str[i+start];
	str[i] = '\0';	
}

//initialize with integer
Mystring::Mystring(int num)
{
	//define a pointer to hold the address storing the C_string version of the integer
	char *initial = to_c_str(num);
	
	int size = StrSize(initial);
	AllocateMemory(size);
	
	//copy initial to str 
	StrCpy(str, initial);
	
	//release initial, which is dynamically allocated in to_c_str() function 
	delete[] initial;
}

/* Destructor */
//release memory 
Mystring::~Mystring()
{
	delete[] str;
}


/* Accessor */
int Mystring::size() const 
{
	int counter = 0;
	while (str[counter] != '\0')
		counter++;
	
	return counter;
}

int Mystring::capacity() const 
{
	return array_capacity;
}

char Mystring::GetChar(int index) //return index-th element
{
	if (index >= StrSize(str))
	{
		std::cout << "Mystring subscript out of range! Program shutting down...\n";
		exit(0);
	}
	return str[index];
}


/* String Member Functions */
	// Mystring.append()
//appends num copies of ch to str 
Mystring Mystring::append(int num, char ch) 
{
	//create a temporary C-string containing num number of ch 
	char *temp_ch = new char [num+1];
	for (int i=0; i<num; i++)
		temp_ch[i] = ch;
	temp_ch[num] = '\0';
	
	//create a new C-string object to hold current content stored in this Mystring 
	char *temp_str = new char [array_capacity];
	StrCpy(temp_str, str);
	
	//calculate total size and allocate memory
	int total_size = StrSize(str) + num;
	AllocateMemory(total_size);
	//copy content in temp_str back in str
	StrCpy(str, temp_str);
	//append content in temp_ch back in str
	StrCat(str, temp_ch);
	
	//release temp_str space
	delete[] temp_str;
	delete[] temp_ch;
	
	return *this;
}

//appends Mystring object to *this str
Mystring Mystring::append(const Mystring &obj, int x)
{
	if (x > StrSize(obj.str))
	{
		std::cout << "Out of range error occurs, program exiting...\n";
		exit(0);
	}
	
	//calculate length of the transferred string
	int str_len = StrSize(obj.str)-x+1;
	//allocate a new C-string, store the content of transferred string into this C-string
	char *temp_str = new char [str_len];
	int i=0;
	for (i; i<str_len; i++)
		temp_str[i] = obj.str[i+x];
	
	//append to *this str
	if (StrSize(temp_str) == 0)
		return *this; //do nothing if the string size in temp_str is zero
	*this += temp_str;
	
	//release the space
	delete[] temp_str;
	
	return *this;
}

//appends Mystring object to *this str, including third parameter, which is the length of the appended sub-string 
Mystring Mystring::append(const Mystring &obj, int x, int n)
{
	//check boundary
	if (x > StrSize(obj.str))
	{
		std::cout << "Out of range error occurs, program exiting...\n";
		exit(0);
	}
	
	//calculate the length from x to end in obj.str
	int str_len = StrSize(obj.str)-x;
	bool exceed;
	if (n > str_len || n < 0)
		exceed = true;
	else 
		exceed = false;
	
	if (exceed)
	{
		append(obj, x);
	}
	else 
	{
		//allocate a new C-string, store the content of transferred string into this C-string
		char *temp_str = new char [n+1]; //+1 is for the '\0'
		int i=0;
		for (i; i<n; i++)
			temp_str[i] = obj.str[i+x];
		temp_str[i] = '\0';
		
		//append to *this str
		if (StrSize(temp_str) == 0)
			return *this; //do nothing if the string size in temp_str is zero
		*this += temp_str;
		
		//release the space
		delete[] temp_str;				
	}
	
	return *this;
	
}


	// Mystring.assign()
//assigns n copies of ch to *this string 
Mystring& Mystring::assign(int n, const char ch)
{
	Mystring temp;
	temp.append(n, ch);
	*this = temp;
	
	return *this;
}

// assign a Mystring to *this string
Mystring& Mystring::assign(const Mystring &obj)
{
	*this = obj;
	return *this;
}

//assigns first n characters to *this string
Mystring& Mystring::assign(const Mystring &obj, int n)
{
	Mystring temp;
	temp.append(obj, 0, n);
	*this = temp;
	return *this;
}

//assign n chs to *this string, start from x in obj
Mystring& Mystring::assign(const Mystring &obj, int x, int n)
{
	if (x > StrSize(str))
	{
		std::cout << "Out of range error occurred. Program is exiting...\n";
		exit(0);
	}
	
	Mystring temp;
	temp.append(obj, x, n);
	*this = temp;
	
	return *this;
}

	// Mystring.back()
//return the last character in Mystring
char Mystring::back() 
{
	return str[StrSize(str)-1];
}

	// Mystring.c_str()
//convert str into a C-string, return the pointer to the C-string
char *Mystring::c_str()
{
	//allocate a memory space to hold the C-string
	char *temp = new char [StrSize(str)+1];
	//copy content in str to temp[]
	StrCpy(temp, str);
	//return pointer to this C-string 
	return temp;
}

	// Mystring.clear()
//clear content in str, not influencing memory space allocated 
void Mystring::clear()
{
	for (int i=0; i<StrSize(str); i++)
		str[i] = '\0';
}
	
	// Mystring.compare()
//normal compare 
int Mystring::compare(const Mystring &str2)
{
	if (*this > str2)
		return 1;
	else if (*this == str2)
		return 0;
	else 
		return -1;
}
	
//advanced compare, start from x, continue for n character
int Mystring::compare(int x, int n, const Mystring &str2)
{
	if (x > StrSize(str))
	{
		std::cout << "Out of range error occurred. Program is exiting...\n";
		exit(0);
	}
	
	Mystring temp;
	temp.append(str2, x, n);
	
	if (*this > temp)
		return 1;
	else if (*this == temp)
		return 0;
	else 
		return -1;
}

	// Mystring.copy()
//copy substring of str2 to *this, start from x, for n characters
Mystring Mystring::copy(const Mystring &str2, int x, int n)
{
	if (x > StrSize(str))
	{
		std::cout << "Out of range error occurred. Program is exiting...\n";
		exit(0);
	}
	
	Mystring temp;
	temp.append(str2, x, n);
	
	*this = temp;
	
	return *this;
}
	
	// Mystring.empty()
//returns true if *this str is empty	
bool Mystring::empty()
{
	if (StrSize(str) == 0)
		return true;
	else 
		return false;
}
	
	// Mystring.erase()
Mystring& Mystring::erase(int x, int n) //erase n characters start from x	
{
	if (x > StrSize(str))
	{
		std::cout << "Out of range error occurred. Program is exiting...\n";
		exit(0);
	}
	
	//copy substring before the erased section
	Mystring temp_before;
	temp_before.append(*this, 0, x);
	
	//copy substring after the erased section
	Mystring temp_after;
	temp_after.append(*this, x+n, StrSize(str)-1);
	
	//update *this
	*this = temp_before + temp_after;
	
	return *this;
}
	
	// Mystring.find()
unsigned Mystring::find(const Mystring &obj, int x) //search if *this string contains a substring obj, starts at x in *this
{
	if (x > StrSize(str))
	{
		std::cout << "Out of range error occurred. Program is exiting...\n";
		exit(0);
	}
	
	return StrStr(str, obj.str, x);
}

	// Mystring.front()
char Mystring::front() //returns the first character in the str 
{
	if (StrSize(str) == 0)
	{
		std::cout << "Out of range error occurred! Program exiting...\n";
		exit(0);
	}
	return str[0];
}

	// Mystring.insert()
//insert several ch in position x, default number is 1
Mystring Mystring::insert(int x, char ch, int n) 
{
	if (x > StrSize(str))
	{
		x = StrSize(str);
	}
	
	//create the inserted string
	char *temp_str = new char [n+1];
	for (int i=0; i<n; i++)
		temp_str[i] = ch;
	temp_str[n] = '\0';
	
	//create the temp_str before insert section 
	Mystring temp_before;
	temp_before.append(*this, 0, x);
	//create the temp_str after the insert section 
	Mystring temp_after;
	temp_after.append(*this, x);
	
	//update *this
	*this = temp_before + temp_str + temp_after;
	
	//release memory
	delete[] temp_str;
	
	return *this;
}

//insert a Mystring object or C-string in position x, default position is x=0
Mystring Mystring::insert(const Mystring &obj, int x)
{
	if (x > StrSize(str))
	{
		x = StrSize(str);
	}	

	//create the temp_str before insert section 
	Mystring temp_before;
	temp_before.append(*this, 0, x);
	//create the temp_str after the insert section 
	Mystring temp_after;
	temp_after.append(*this, x);
	
	//update *this
	*this = temp_before + obj + temp_after;	
	
	return *this;
}


	// Mystring.replace()
Mystring& Mystring::replace(int x, int n, const Mystring &obj) //insert obj into x in *this str, and n characters in *this str will be replaced by characters in obj
{
	if (x > StrSize(str))
	{
		std::cout << "Out of range error occurred. Program is exiting...\n";
		exit(0);
	}
	
	//erase n characters from x in *this
	erase(x, n);
	
	//insert obj to x 
	insert(obj, x);
	
	return *this;
}

	// Mystring.resize()
void Mystring::resize(int n, char ch) //resize *this, if n is greater than current size, fill with ch (default '\0'); if n is smaller than current size, truncate to n
{
	if (n < 0)
	{
		std::cout << "Out of range error occured. Program is exiting...\n";
		exit(0);
	}
	
	if (n > StrSize(str)) //should resize the memory space
	{
		//create a string that should be added to *this
		char *temp_str = new char [n-StrSize(str)+1];
		for (int i=0; i<(n-StrSize(str)); i++)
			temp_str[i] = ch;
		temp_str[n-StrSize(str)] = '\0';
		
		//add to *this 
		*this += temp_str;
		
		//release memory
		delete[] temp_str;
	}
	
	else //truncate
	{
		for (int i=n; i<StrSize(str); i++)
			str[i] = '\0';
	}
}

	// Mystring.substr
//two parameter version 
Mystring Mystring::substr(int x, int n) const //return a substring of *this 
{
	Mystring temp;
	temp.append(*this, x, n);
	return temp;
}
//one parameter version 
Mystring Mystring::substr(int x) const
{
	Mystring temp;
	temp.append(*this, x);
	return temp;	
}

	// Mystring.swap()
void Mystring::swap(Mystring &right) //swap *this and right 
{
	Mystring temp = *this;
	*this = right;
	right = temp;
}


/* Operator */
// = //
//(Mystring = Mystring)
const Mystring Mystring::operator= (const Mystring &right)
{
	array_capacity = right.array_capacity;
	AllocateMemory(array_capacity);
	
	/* Copy content */
	StrCpy(str, right.str);
	
	return *this;
}

//(Mystring = C-string)
const Mystring Mystring::operator= (const char* initial)
{	
	//allocate memory and update array_capacity
	AllocateMemory(StrSize(initial));
	
	//copy content in initial into the str
	StrCpy(str, initial);
	
	//return 
	return *this;
}

// []
char& Mystring::operator[] (unsigned int index)
{
	if (index < 0) //boundary check
	{
		std::cout << "Mystring subscript out of range! Programming shutting down...\n";
		exit(0);
	}
	
	if (index >= static_cast<unsigned>(StrSize(str))) //re-size, fill the new slot with space
	{
		resize(index+1, ' ');
		return str[index];
	}
	return str[index];	
}

const char Mystring::operator[] (unsigned int index) const
{
	if (index >= static_cast<unsigned>(StrSize(str))) //boundary check
	{
		return '\0';
	}
	return str[index];		
}

// +
//+=: Mystring += Mystring
Mystring Mystring::operator+= (const Mystring &right)
{
	Mystring temp; //define a temporary container 
	int total_size = StrSize(str) + StrSize(right.str); //calculate the total number of characters needed 
	temp.AllocateMemory(total_size); //allocate memory
	
	//copy the content in *this object into temp
	StrCpy(temp.str, str);
	//concatenate content in right into temp
	StrCat(temp.str, right.str);
	
	//update *this string
	*this = temp;
	
	//return result
	return temp;
}

//Mystring += char
Mystring Mystring::operator+= (const char ch) 
{
	char temp[2] = { ch, '\0'};
	
	*this = *this + temp;
	return *this;
}

//Mystring + Mystring
Mystring Mystring::operator+ (const Mystring &right)
{
	Mystring temp; //define a temporary container 
	int total_size = StrSize(str) + StrSize(right.str); //calculate the total number of characters needed 
	temp.AllocateMemory(total_size); //allocate memory
	
	//copy the content in *this object into temp
	StrCpy(temp.str, str);
	//concatenate content in right into temp
	StrCat(temp.str, right.str);
	
	//return result
	return temp;
}

//Mystring + C-string
Mystring Mystring::operator+ (const char *right)
{
	Mystring temp; //define a temporary container 
	int total_size = StrSize(str) + StrSize(right); //calculate the total number of characters needed 
	temp.AllocateMemory(total_size); //allocate memory
	
	//copy the content in *this object into temp
	StrCpy(temp.str, str);
	//concatenate content in right into temp
	StrCat(temp.str, right);
	
	//return result 
	return temp;
}

//Mystring + char
Mystring Mystring::operator+ (const char ch)
{
	char temp[2];
	temp[0] = ch;
	temp[1] ='\0';
	
	return *this + temp;
}


/* Friend */
// <<
std::ostream& operator<< (std::ostream &out, const Mystring &obj)
{
	out << obj.str;
	return out;
}

// + (C-string + Mystring)
Mystring operator+ (const char* lhs, const Mystring &rhs)
{
	Mystring temp(lhs);
	return temp+rhs;
}
// + (character + Mystring)
Mystring operator+ (const char ch, const Mystring &obj)
{
	char temp[2];
	temp[0] = ch;
	temp[1] = '\0';
	
	return temp + obj;
}

// -
Mystring operator- (Mystring &lhs, const Mystring &rhs)
{
	int keyword_len = lhs.StrSize(rhs.str); //hold the length of keyword, used in erase()
	int start_index = 0;
	int match_index;
	
	while (start_index < lhs.StrSize(lhs.str)-lhs.StrSize(rhs.str))
	{
		match_index = lhs.find(rhs, start_index);
		
		if (match_index == -1)
			break;
		else
		{
			lhs.erase(match_index, keyword_len); //delete the keyword in lhs object
			start_index = match_index; //update search start_index 
		}
	}
	
	return lhs;
}

// >>
std::istream& operator>> (std::istream &in, Mystring &obj)
{	
	std::vector<char> temp; //define a temporary container for inputing character
	char temp_ch; //to temporarily hold a character read from keyboard buffer
	
	/* Skip all leading white space */
	in >> temp_ch;

	
	/* Read from keyboard buffer until the next whitespace */
	temp.push_back(temp_ch); //store into temp vector
	in.get(temp_ch); //read next character in keyboard buffer
	while (!isspace(temp_ch))
	{
		temp.push_back(temp_ch);
		in.get(temp_ch);
	}
	
	/* Determine the size, and allocate memory */
	obj.AllocateMemory(temp.size());
	
	/* Copy content from temp vector to Mystring */
	for (unsigned i=0; i<temp.size(); i++)
		obj.str[i] = temp[i];
	obj.str[temp.size()] = '\0';
	
	return in;
}

// getline() function 
std::istream& getline(std::istream &in, Mystring &obj, char delim)
{
	std::vector<char> temp; //define a temporary container for inputing character
	char temp_ch; //to temporarily hold a character read from keyboard buffer

	in.get(temp_ch); //read from the keyboard buffer
	while (temp_ch != delim) //while delimiter is not met
	{
		temp.push_back(temp_ch); //add to temp vector 
		in.get(temp_ch); //read the next character
	}
	
	/* Determine the size, and allocate memory */
	obj.AllocateMemory(temp.size());
	
	/* Copy content from temp vector to Mystring */
	for (unsigned i=0; i<temp.size(); i++)
		obj.str[i] = temp[i];
	obj.str[temp.size()] = '\0';
	
	return in;	
}

// relational operator
bool operator> (const Mystring &lhs, const Mystring &rhs)
{
	Mystring temp; //used for calling StrCmp function 
	if (temp.StrCmp(lhs.str, rhs.str) == 1)
		return true;
	else
		return false;
}

bool operator== (const Mystring &lhs, const Mystring &rhs)
{
	Mystring temp;
	if (temp.StrCmp(lhs.str, rhs.str) == 0)
		return true;
	else 
		return false;
}

bool operator>= (const Mystring &lhs, const Mystring &rhs)
{
	if (lhs > rhs || lhs == rhs)
		return true;
	else 
		return false;
}

bool operator< (const Mystring &lhs, const Mystring &rhs)
{
	if (!(lhs >= rhs))
		return true;
	else 
		return false;
}

bool operator<= (const Mystring &lhs, const Mystring &rhs)
{
	if (lhs < rhs || lhs == rhs)
		return true;
	else 
		return false;
}

bool operator!= (const Mystring &lhs, const Mystring &rhs)
{
	if (lhs == rhs)
		return false;
	else
		return true;
}



}


}

15. Aggregate class demonstration
{

1) Book.h
{

#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>

class Book
{
private:
	std::string name;
public:
	Book(std::string n)
	{
		name = n;
	}
	Book()
	{
		name = "N/A";
	}

	void Set(std::string n)
	{
		name = n;
	}

	void Print() const
	{
		std::cout << "Textbook info:\n";
		std::cout << "Book title: " << name << "\n";
	}


};


#endif

}

2) Instructor.h
{

#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <string>
#include <iostream>

class Instructor
{
private:
	std::string name_last;
	std::string name_first;
	std::string office_num;
public:
	Instructor()
	{
		name_last = "N/A";
		name_first = "N/A";
		office_num = "N/A";
	}
	Instructor(std::string n_l, std::string n_f, std::string o_n)
	{
		name_last = n_l;
		name_first = n_f;
		office_num = o_n;
	}

	void Set(std::string n_l, std::string n_f, std::string o_n)
	{
		name_last = n_l;
		name_first = n_f;
		office_num = o_n;
	}

	void Print() const
	{
		std::cout << "Instructor info:\n";
		std::cout << "Last name: " << name_last << "\n";
		std::cout << "First name: " << name_first << "\n";
		std::cout << "Office number: " << office_num << "\n";
	}

};

#endif

}

3) Course.h
{

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include "Book.h"
#include "Instructor.h"
#include <string>

class Course
{
private:
	std::string course_name;
	Instructor instructor;
	Book textbook;
public:
	Course(std::string course_n, std::string instructor_first_name, std::string instructor_last_name, std::string instructor_office_num, std::string book_name)
	{
		course_name = course_n;
		instructor.Set(instructor_last_name, instructor_first_name, instructor_office_num);
		textbook.Set(book_name);
	}

	void Print() const
	{
		std::cout << "Course info:\n" << course_name << "\n";
		instructor.Print();
		textbook.Print();
	}
};


#endif

}

4) Main function 
{

#include <iostream>
#include "Mystring.h"
#include <string>
#include "Course.h"

int main()
{
	Course math("Math", "Ab", "Cd", "1220193", "Advanced math analysis");
	math.Print();
	
	return 0;
}


}

}

16. Collaboration between classes

17. Case Study: Cho-Han game (uses Mystring class as the string substitute)
{

1) .h file
{

> Dealer
{

#ifndef DEALER_H
#define DEALER_H

#include "Dice.h"

class Player;

struct Result
{
	int d1;
	int d2;
};

class Dealer
{
private:
	Dice dice1; //Dealer has two Dice instances.
	Dice dice2;
	Result roll_result; //hold the rolling result
public:
	Dealer(); //default constructor, two dices are six-sided (default dice)
	Dealer(int dc1, int dc2); //requires two int argument, will set the side number of the two dice
	Result RollDice(); //call Roll in two Dice instances
	Result ReportDice() const; //report side-up value for two dices, use a structured data 
	char ReportResult() const; //report final result: C for Cho, H for Han
	
	/* Friend of Player */
	void UpdatePoint(int pt, Player& player) const; 
};

#endif

}

> Dice
{

#ifndef DICE_H
#define DICE_H

class Dice
{
private:
	int upside; //hold the value of the up-side
	int side_num; //hold number of sides of this dice, initialized by constructor
public:
	Dice(); //default constructor, create a 6-sided dice and seed the random generator
	Dice(int num); //create a num-sided dice, seed the random generator 

	int Roll(); //roll the dice, generate a random result from 1 to side_num

	int ShowSide() const; //return side_num of this dice 
	operator int(); //int = Dice, convert upside to int

};

#endif

}

> Player
{

#ifndef PLAYER_H
#define PLAYER_H

#include "Mystring.h"
#include "Dealer.h"
#include <iostream>

class Player
{
private:
	Mystring name;
	int point;
	char guess;
public:
	Player(); //default constructor, set name to N/A, point to 0, guess to N
	Player(Mystring n); //set name to n, point to 0, guess to N
	
	/* Accessor */
	int ShowPoint() const
	{ return point; }
	
	char ShowGuess() const 
	{ return guess; }
	
	/* Mutator */
	void Guess(char g)
	{ guess = g; }	
	
	/* Friend */
	friend void Dealer::UpdatePoint(int pt, Player& player) const;
	
	/* Operator */
	// << (for displaying name of the player)
	friend std::ostream& operator<< (std::ostream& out, const Player& p);
	friend std::istream& operator>> (std::istream& in, Player& p);
};

#endif

}


}

2) .cpp file 
{

> Dealer 
{

#include "Dealer.h"
#include "Player.h"

Dealer::Dealer() //default constructor, two dices are six-sided (default dice)
{
	//record dice value
	roll_result.d1 = dice1;
	roll_result.d2 = dice2;
}
Dealer::Dealer(int dc1, int dc2) //requires two int argument, will set the side number of the two dice
{
	//create two temporary dices with specified side number 
	Dice d1(dc1);
	Dice d2(dc2);
	//assign this two temporary dice to private dice1 dice 2
	dice1 = d1;
	dice2 = d2;
	//update roll_result
	roll_result.d1 = dice1;
	roll_result.d2 = dice2;
}

Result Dealer::RollDice() //call Roll in two Dice instances
{
	roll_result.d1 = dice1.Roll();
	roll_result.d2 = dice2.Roll();
	return roll_result;
}

Result Dealer::ReportDice() const //report side-up value for two dices, use a structured data
{
	return roll_result;
}
char Dealer::ReportResult() const //report final result: C for Cho, H for Han
{
	int total = roll_result.d1 + roll_result.d2;
	if (total % 2 == 0)
		return 'C';
	else
		return 'H';
}

void Dealer::UpdatePoint(int pt, Player& player) const
{
	player.point += pt;
}



}

> Dice 
{

#include "Dice.h"
#include <cstdlib>
#include <ctime>


Dice::Dice() //default constructor, create a 6-sided dice and seed the random generator
{
	side_num = 6;
	upside = 1;

	srand(static_cast<unsigned>(time(0)));
}

Dice::Dice(int num) //create a num-sided dice, seed the random generator 
{
	side_num = num;
	upside = 1;

	srand(static_cast<unsigned>(time(0)));
}

int Dice::Roll() //roll the dice, generate a random result from 1 to side_num
{
	int N_min = 1, N_max = side_num;

	return rand() % (N_max - N_min + 1) + N_min;
}

int Dice::ShowSide() const //return the side_num 
{
	return side_num;
}


Dice::operator int()
{
	return upside;
}



}

> Player
{

#include "Player.h"
#include "Mystring.h"
#include <iostream>

Player::Player() //default constructor, set name to N/A, point to 0, guess to N
{
	name = "N/A";
	point = 0;
	guess = 'N';
}


Player::Player(Mystring n) //set name to n, point to 0, guess to N
{
	name = n;
	point = 0;
	guess = 'N';
}

std::ostream& operator<< (std::ostream& out, const Player& p)
{
	out << p.name;
	return out;
}

std::istream& operator>> (std::istream& in, Player& p)
{
	in >> p.guess;
	return in;
}

}

}

3) main program
{

#include <iostream>
#include "Player.h"
#include "Dealer.h"

void UpdatePlayer(const Dealer& dealer, Player& p1, Player& p2);
void CheckPoint(const Player& p1, const Player& p2);

int main()
{
	/* Define objects: 1 dealer, two players */
	Dealer dealer;
	Player p1("Yu Miao"), p2("Yingying");
	Result result; //hold result of one rolling
	
	/* Play the game five times */
	for (int i=0; i<5; i++)
	{
		/* Rolling the dice */
		std::cout << "Round " << i+1 << "\n";
		std::cout << "Rolling the dice...\n";
		result = dealer.RollDice();
		std::cout << "Dice rolling complete.\n\n";
		
		/* Ask player to input guess */
		std::cout << p1 << ": input a guess(C/H): ";
		std::cin >> p1;
		std::cout << p2 << ": input a guess(C/H): ";
		std::cin >> p2;

		/* Show result */
		std::cout << "\nResult:\ndice 1: " << result.d1 << "\ndice 2: " << result.d2 << "\n";
		std::cout << "Its " << dealer.ReportResult() << "\n";
		UpdatePlayer(dealer, p1, p2);
		
		/* Press enter for next round */
		if (i != 4)
		{
			std::cout << "Press enter for round " << i+2 << "...";
			std::cin.ignore();
			std::cin.get();			
		}
		else
		{
			std::cout << "Press enter to exit" << "...";
			std::cin.ignore();
			std::cin.get();			
		}
		
	}
	
	/* Check player's score and announce winner */
	std::cout << "Final result:\n";
	CheckPoint(p1, p2);
	
	return 0;
	
}

void UpdatePlayer(const Dealer& dealer, Player& p1, Player& p2)
{
	std::cout << p1 << "'s guess: " << p1.ShowGuess();
	if (p1.ShowGuess() == dealer.ReportResult())
	{
		std::cout << ". Point +1, current point: ";
		dealer.UpdatePoint(1, p1);
		std::cout << p1.ShowPoint() << "\n";
	}
	else 
	{
		std::cout << ". Point -1, current point: ";
		dealer.UpdatePoint(-1, p1);
		std::cout << p1.ShowPoint() << "\n\n";			
	}	

	std::cout << p2 << "'s guess: " << p2.ShowGuess();
	if (p2.ShowGuess() == dealer.ReportResult())
	{
		std::cout << ". Point +1, current point: ";
		dealer.UpdatePoint(1, p2);
		std::cout << p2.ShowPoint() << "\n";
	}
	else 
	{
		std::cout << ". Point -1, current point: ";
		dealer.UpdatePoint(-1, p2);
		std::cout << p2.ShowPoint() << "\n\n";			
	}
}

void CheckPoint(const Player& p1, const Player& p2)
{
	/* Display point */
	std::cout << p1 << "'s point: " << p1.ShowPoint() << "\n";
	std::cout << p2 << "'s point: " << p2.ShowPoint() << "\n";
	if (p1.ShowPoint() == p2.ShowPoint())
		std::cout << p1 << " and " << p2 << " are draw.\n";
	else if (p1.ShowPoint() > p2.ShowPoint())
		std::cout << p1 << " is winner!\n";
	else 
		std::cout << p2 << " is winner!\n";
}



}

}



/****************************/
/***Programming Challenges***/
/****************************/

1. Numbers Class (using Mystring and solved a very deeply-hidden bug)
{

1) .h 
{

#ifndef NUMBERS_H
#define NUMBERS_H

#include "Mystring.h"
#include <iostream>

class Numbers
{
private:
	int number;
	static Mystring less_than_20[20];
	static Mystring ten[8];
public:
	Numbers(); //default constructor
	Numbers(int num); //constructor
	int integer_value() const; //return number
	Mystring string_value() const; //return string value
	
	/* Friend */
	// <<
	friend std::ostream& operator<< (std::ostream& out, const Numbers& obj);
	// >>
	friend std::istream& operator>> (std::istream& in, Numbers& obj);
};

#endif

}

2) .cpp 
{

#include "Numbers.h"
#include "Mystring.h"
#include <iostream>

/* Definition of static member variable */
Mystring Numbers::less_than_20[20] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "ninteen" };
Mystring Numbers::ten[8] = { "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninty" };

Numbers::Numbers()
{
	number = 0;
}

Numbers::Numbers(int num) //constructor
{
	if (num < 0 || num > 9999)
	{
		std::cout << "Initialization failed, number should be in 0 ~ 9999. The value has been set to default value zero.\n";
		number = 0;
	}
	
	else
		number = num;
}

int Numbers::integer_value() const //return integer value of number
{
	return number;
}

Mystring Numbers::string_value() const //return string value
{
	Mystring value;
	
	if (number == 0)
	{
		value = "zero";
		return value;
	}
		
	int thousand_digit = number/1000;
	int hundred_digit = (number%1000)/100;
	int ten_digit = (number%100)/10;
	int single_digit = (number%10);
	
	if (thousand_digit != 0)
		value = value + less_than_20[thousand_digit] + " thousand ";
	if (hundred_digit != 0)
		value = value + less_than_20[hundred_digit] + " hundred ";
	if (ten_digit == 1)
	{
		value = value + less_than_20[ten_digit*10 + single_digit];
		return value;
	}
	else if (ten_digit == 0)
	{
		if (single_digit == 0)
			return value;
		
		value = value + less_than_20[single_digit];
		return value;
	}
	else
	{
		if (single_digit != 0)
			value = value + ten[ten_digit-2] + " " + less_than_20[single_digit];
		else
			value = value + ten[ten_digit-2];
		
		return value;
	}
		
	
}


/* Friend */
// <<
std::ostream& operator<< (std::ostream& out, const Numbers& obj)
{
	out << obj.string_value();
	return out;
}

// >>
std::istream& operator>> (std::istream& in, Numbers& obj)
{
	in >> obj.number;
	while (obj.number < 0 || obj.number > 9999)
	{
		std::cout << "Input value should be in 0 ~ 9999, please input again: ";
		in >> obj.number;
	}
	return in;
}





}

3) main program 
{

#include "Mystring.h"
#include <iostream>
#include <string>
#include "Numbers.h"

int main()
{
	Numbers num;

	std::cout << "Enter a number, and this program will convert it into letter notation:\n";
	std::cin >> num;
	std::cout << "You inputted:\n" << num << "\n";

	return 0;
}

}

}

2.3. Day of the year (using Mystring, solved a c_to_str bug. The old version cannot handle number with last digit as zero, for example: 120, 130, 1210. Algorithm error, already fixed)
{

1) .h 
{

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

#include "Mystring.h"

class Day_of_year
{
private:
	static Mystring month[13]; //to hold the month name from 1 to 12, 0 is for place holder
	int day_number; //hold the Julian date of a year
	
	int MonthDay(int m) const; //accept month index, returns the number of days in that month
	int MonthDay(Mystring m) const; //accept month name, returns the number of days in that month
public:
	/* Constructor */
	Day_of_year(int n=1); //constructor, hold the day number
	Day_of_year(Mystring m, int d); //initialize with month name and day number, and store corresponding day_number to day_number variable
	
	/* Accessor */
	Mystring GetLetterDate() const; //get letter date, call by << when print
	
	/* Operator */
	// >>
	friend std::istream& operator>> (std::istream& in, Day_of_year& obj);
	// <<
	friend std::ostream& operator<< (std::ostream& out, const Day_of_year& obj);
	// ++ and --
	Day_of_year operator++ ();
	Day_of_year operator++ (int);
	Day_of_year operator-- ();
	Day_of_year operator-- (int);	
};

#endif

}

2) .cpp 
{

#include "Day_of_year.h"
#include "Mystring.h"
#include <iostream>

//define static variable
Mystring Day_of_year::month[13] = { "Month zero", "Janurary", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

int Day_of_year::MonthDay(int m) const
{
	switch (m)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		return 28;
	}
}

int Day_of_year::MonthDay(Mystring m) const
{
	switch (m[0])
	{
	case 'J':
		if (m[2] == 'n')
			return 30;
		return 31;
	case 'F':
		return 28;
	case 'M':
	case 'O':
	case 'D':
		return 31;
	case 'A':
		if (m[1] == 'p')
			return 30;
		return 31;
	case 'N':
	case 'S':
		return 30;
	default:
		return -1; //for illegal month name 
	}
}

/* Constructor */
Day_of_year::Day_of_year(int n) //constructor, hold the day number
{
	day_number = n;
}

Day_of_year::Day_of_year(Mystring m, int d) //initialize with month name and day number, and store corresponding day_number to day_number variable
{
	/* Check validity */
	if (d < 0 || d > MonthDay(m))
	{
		std::cout << "Invalid date inputted, program will set date to May 5.\n";
		m = "May";
		d = 5;
	}

	/* Find out the month number */
	int month_index = 1;
	while (month[month_index] != m)
		month_index++;
	month_index--; //to calculate whole month_index: number of whole month before that date

	if (month_index == 0)
		day_number = d;
	else
	{
		int whole_month_day = 0;
		for (int i = 1; i <= month_index; i++)
			whole_month_day += MonthDay(i);
		day_number = whole_month_day + d;
	}


}


/* Accessor */
Mystring Day_of_year::GetLetterDate() const //get letter date, call by << when print
{
	Mystring date;
	int total_day = 0; //31 + 
	int total_month = 0;
	while (total_day < day_number)
	{
		total_month++;

		if (total_month > 12)
			total_month -= 12;

		total_day += MonthDay(total_month);
	}

	total_day -= MonthDay(total_month); //total_day number corresponds to the previous month
	int days = day_number - total_day;

	date = month[total_month] + " ";
	Mystring days_letter(days);
	date += days_letter;

	return date;


}

/* Operator */
// >>
std::istream& operator>> (std::istream& in, Day_of_year& obj)
{
	in >> obj.day_number;
	return in;
}

// <<
std::ostream& operator<< (std::ostream& out, const Day_of_year& obj)
{
	out << obj.GetLetterDate();
	return out;
}

// ++ and --
Day_of_year Day_of_year::operator++ ()
{
	day_number++;
	if (day_number > 365)
		day_number -= 365;
	return *this;
}

Day_of_year Day_of_year::operator++ (int)
{
	Day_of_year temp = *this;
	day_number++;
	if (day_number > 365)
		day_number -= 365;
	return temp;
}

Day_of_year Day_of_year::operator-- ()
{
	day_number--;

	if (day_number < 1)
		day_number += 365;
	return *this;
}

Day_of_year Day_of_year::operator-- (int)
{
	Day_of_year temp = *this;
	day_number--;

	if (day_number < 1)
		day_number += 365;
	return temp;
}




}

3) main program 
{

#include "Day_of_year.h"
#include <iostream>

int main()
{
	Day_of_year date("May", 10);
	
	std::cout << date-- << "\n";
	std::cout << date << "\n";



	return 0;
}

}

}

4. Num_days class 
{

1) .h 
{

#ifndef NUMDAYS_H
#define NUMDAYS_H

#include <iostream>

class Num_days
{
private:
	int hour; //hold working hour
	double day; //hold the corresponding working days. 8 hours = 1 day
public:
	/* Constructor */
	Num_days(int h); //accepts hour number, convert it to day number and store in day variable
	
	/* Mutator */
	void SetDay(double d); //set the number of days. hour will be re-calculated
	
	/* Accessor */
	double GetDay() const; //return the working day
	
	/* Operator */
	// >> (input to hour variable)
	friend std::istream& operator>> (std::istream& in, Num_days& obj);
	// << (display hour number)
	friend std::ostream& operator<< (std::ostream& out, const Num_days& obj);
	// + (add hour and return)
	int operator+ (const Num_days& rhs);
	// - (subtract hour and return)
	int operator- (const Num_days& rhs);
	// ++ (increment hour, recalculate day as well)
	Num_days operator++ ();
	Num_days operator++ (int);
	// -- (decrement hour, recalculate day as well)
	Num_days operator-- ();
	Num_days operator-- (int);
	
};

#endif

}

2) .cpp 
{

#include "Num_days.h"
#include <iostream>

/* Constructor */
Num_days::Num_days(int h) //accepts hour number, convert it to day number and store in day variable
{
	hour = h;
	day = h/8.0;
}

/* Mutator */
void Num_days::SetDay(double d) //set the number of days. hour will be re-calculated
{
	day = d;
	hour = d*24;
}

/* Accessor */
double Num_days::GetDay() const //return the working day
{
	return day;
}

/* Operator */
// >> (input to hour variable)
std::istream& operator>> (std::istream& in, Num_days& obj)
{
	in >> obj.hour;
	obj.day = obj.hour/8.0;
	return in;
}

// << (display hour number)
std::ostream& operator<< (std::ostream& out, const Num_days& obj)
{
	out << obj.hour << " hours (" << obj.day << " day) ";
	return out;
}

// + (add hour and return)
int Num_days::operator+ (const Num_days& rhs)
{
	return hour+rhs.hour;
}

// - (subtract hour and return)
int Num_days::operator- (const Num_days& rhs)
{
	return hour-rhs.hour;
}

// ++ (increment hour, recalculate day as well)
Num_days Num_days::operator++ ()
{
	hour++;
	day = hour/8.0;
	return *this;
}

Num_days Num_days::operator++ (int)
{
	Num_days temp = *this;
	++(*this);
	return temp;
}

// -- (decrement hour, recalculate day as well)
Num_days Num_days::operator-- ()
{
	hour--;
	day = hour/8.0;
	return *this;
}

Num_days Num_days::operator-- (int)
{
	Num_days temp = *this;
	--(*this);
	return temp;
}

}

3) main program 
{

#include "Num_day.h"
#include <iostream>

int main()
{
	Num_days worker1(24);
	Num_days worker2(12);

	std::cout << "worker1: " << worker1 << "\n";
	worker1++;
	std::cout << "After increment, worker1: " << worker1 << "\n";
	worker1--;
	std::cout << "After decrement, worker1: " << worker1 << "\n";

	std::cout << "worker1 - worker2 = " << worker1 - worker2 << "\n";

	return 0;
}

}


}

5. Time_off class 
{

1) .h 
{

#ifndef TIMEOFF_H
#define TIMEOFF_H
#include "Num_days.h" //enable using Num_days class 
#include "Mystring.h"

class Time_off
{
private:
	Num_days max_sick_days; //maximum number of days of sick leave
	Num_days sick_taken; //sick leave the employee already taken
	Num_days max_vacation; //maximum number of paid vacation 
	Num_days vac_taken; //vacation already taken
	Num_days max_unpaid; //maximum number of days of unpaid vacation 
	Num_days unpaid_taken; //unpaid vacation already taken
	
	Mystring name; //employee's name 
	Mystring empid; //employee's ID
public:
	Time_off(Mystring n, Mystring id); //constructor, initialize with name and id. All Num_days object will be set to zero
	
	/* Mutator */
	void SetMaxSick(double d); //set max sic day
	void SetSick(double d); //set sick day 
	void SetMaxVac(double d); //set maximum paid vacation 
	void SetVac(double d); //set vacation taken 
	void SetMaxUnpaidVac(double d); //set maximum unpaid vacation 
	void SetUnpaidVac(double d); //set paid vacation
	
	/* Accessor */
	Num_days GetMaxSick() const; 
	Num_days GetSick() const;
	Num_days GetMaxVac() const;
	Num_days GetVac() const;
	Num_days GetMaxUnpaidVac() const;
	Num_days GetUnpaidVac() const;
};

#endif

}

2) .cpp 
{

#include "Num_days.h"
#include "Mystring.h"
#include "Time_off.h"
#include <iostream>

Time_off::Time_off(Mystring n, Mystring id) //constructor, initialize with name and id. All Num_days object will be set to zero
{
	name = n;
	empid = id;
	
	max_sick_days.SetDay(0.0);
	sick_taken.SetDay(0.0);
	max_vacation.SetDay(0.0);
	vac_taken.SetDay(0.0);
	max_unpaid.SetDay(0.0);
	unpaid_taken.SetDay(0.0);
}

/* Mutator */
void Time_off::SetMaxSick(double d) //set max sick day
{ max_sick_days.SetDay(d); }

void Time_off::SetSick(double d) //set sick day 
{ sick_taken.SetDay(d); }

void Time_off::SetMaxVac(double d) //set maximum paid vacation 
{ max_vacation.SetDay(d); }

void Time_off::SetVac(double d) //set vacation taken 
{ vac_taken.SetDay(d); }

void Time_off::SetMaxUnpaidVac(double d) //set maximum unpaid vacation 
{
	if (d > 10)
	{
		std::cout << "an employee may not accumulate more than 240 hours of paid vacation.\n"
		<< "Thus the days of maximum unpaid vacation has been set to 10.\n";
		
		d = 10;
	}
	
	max_unpaid.SetDay(d);
}

void Time_off::SetUnpaidVac(double d) //set paid vacation
{ unpaid_taken.SetDay(d); }

/* Accessor */
Num_days Time_off::GetMaxSick() const
{ return max_sick_days; }

Num_days Time_off::GetSick() const
{ return sick_taken; };

Num_days Time_off::GetMaxVac() const
{ return max_vacation; }

Num_days Time_off::GetVac() const
{ return vac_taken; }

Num_days Time_off::GetMaxUnpaidVac() const
{ return max_unpaid; }

Num_days Time_off::GetUnpaidVac() const
{ return unpaid_taken; }

}


}

6. Personnel report 
{

main program 
{

#include "Time_off.h"

int main()
{
	int month_work;
	
	std::cout << "How many months you worked for the company: ";
	std::cin >> month_work;
	
	Time_off emp1("Yu Miao", 12203);
	
	emp1.SetMaxVac(month_work*12/24.0); //update maximum vacation leave
	emp1.SetMaxSick(month_work*8/24.0); //update maximum sick leave 
	
	std::cout << "Maximum vacation leave earned: " << emp1.GetMaxVac() << "\n"
	<< "Maximum sick leave earned: " << emp1.GetMaxSick() << "\n";
	
	return 0;
}

}

}

7. Month class 
{

1) .h 
{

#ifndef MONTH_H
#define MONTH_H
#include "Mystring.h"
#include <iostream>

class Month
{
private:
	Mystring name;
	int month_num;
	static Mystring month_name[13]; //hold month name for each month
	
public:
	/* Constructor */
	Month(); //default constructor, set to Janurary 1
	Month(Mystring n); //accepts month name, also sets the month num
	Month(int i); //accepts integer of month number, also sets the month name
	
	/* Accessor */
	int GetMonthNum() const; //return month number
	
	/* Mutator */
	void SetMonthNum(int i); //set month number, will also update the month name
	
	/* Operator */
	// << (print name)
	friend std::ostream& operator<< (std::ostream& out, const Month& m);
	// >> (perform input data type check)
	friend std::istream& operator>> (std::istream& in, Month& m);
	// ++ (if month_num > 12, month_num -= 12)
	Month operator++ ();
	Month operator++ (int);
	// -- (if month_name < 1, month_num += 12)
	Month operator-- ();
	Month operator-- (int);
	
};

#endif

}

2) .cpp 
{

#include "Month.h"
#include <iostream>

Mystring Month::month_name[13] = { "Month 0", "Janurary", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

/* Constructor */
Month::Month() //default constructor, set to Janurary 1
{
	month_num = 1;
	name = month_name[month_num];
}

Month::Month(Mystring n) //accepts month name, also sets the month num
{
	int month_index = 1;
	while (n != month_name[month_index] && month_index < 13)
		month_index++;
	
	if (month_index == 13)
	{
		std::cout << "Inputed month name is illegal, month has been set to Janurary.\n";
		name = "Janurary";
		month_num = 1;
	}
	
	else 
	{
		name = month_name[month_index];
		month_num = month_index;
	}
}

Month::Month(int i) //accepts integer of month number, also sets the month name
{
	if (i > 12 || i < 1)
	{
		std::cout << "Month number illegal, month has been set to Janurary.\n";
		name = month_name[1];
		month_num = 1;
	}
	
	else 
	{
		name = month_name[i];
		month_num = i;
	}
		
}

/* Accessor */
int Month::GetMonthNum() const //return month number
{ return month_num; }

/* Mutator */
void Month::SetMonthNum(int i) //set month number, will also update the month name
{
	if (i > 12 || i < 1)
	{
		std::cout << "Month number illegal, month modification failed.\n";
	}
	
	else 
	{
		name = month_name[i];
		month_num = i;
	}	
}

/* Operator */
// << (print name)
std::ostream& operator<< (std::ostream& out, const Month& m)
{
	out << m.name;
	return out;
}

// >> (perform input data type check)
std::istream& operator>> (std::istream& in, Month& m)
{
	in >> m.month_num;
	while (m.month_num < 1 || m.month_num > 12)
	{
		std::cout << "Invalid month number. Please input month number between 1 to 12: ";
		in >> m.month_num;
	}
	
	m.name = m.month_name[m.month_num];
	
	return in;
}

// ++ (if month_num > 12, month_num -= 12)
Month Month::operator++ ()
{
	month_num++;
	if (month_num > 12)
		month_num -= 12;
	name = month_name[month_num];
	
	return *this;
}

Month Month::operator++ (int)
{
	Month temp = *this;
	month_num++;
	if (month_num > 12)
		month_num -= 12;
	name = month_name[month_num];
	return temp;
}

// -- (if month_name < 1, month_num += 12)
Month Month::operator-- ()
{
	month_num--;
	if (month_num < 1)
		month_num += 12;
	name = month_name[month_num];
	
	return *this;
}

Month Month::operator-- (int)
{
	Month temp = *this;
	month_num--;
	if (month_num < 1)
		month_num += 12;
	name = month_name[month_num];
	
	return *this;
}




}

3) main program 
{

#include "Month.h"

int main()
{
	Month m(13);
	std::cout << --m << "\n";
	std::cin >> m;
	std::cout << m << "\n";

	return 0;
}

}

}

8. Date class modification (used Date class wrote for COP 3330 assignment 2)
{

1) .h 
{

#ifndef DATE_H
#define DATE_H
#include <iostream>

class Date
{
private:
	int day;
	int month;
	int year;
	char format; //hold format setting, Show function will check this value first, then call different function to show date
	bool CheckLeap(int y) const; //check if the year is leap year. Yes: return true; No: return false
	bool CheckDate(int m, int d, int y); //check if the date is valid, valid: return true, invalid: return false
	int MonthDay(int m, int y) const; //input month and year, return the number of days in that month, year (consider leap year)
	int YearDay(int y); //input year, return the number of days in that year (leap or common)
	int AD_Day(int m, int d, int y) const; //input a date, return total days since AD
	void AD_Day_to_Date(int total_day, int &m, int &d, int &y); //input a total day, transfer to the corresponding date
	void ShowD() const; //show date in default format 
	void ShowT() const; //show date in two-digit format 
	void ShowL() const; //show date in long format
	void ShowJ() const; //show date in Julian Day form
public:
	/* Constructor */
	Date(); //default constructor, initialize with 1/1/2000
	Date(int m, int d, int y); //constructor used to initialize date value, if value is invalid, initialize date with 1/1/2000
	
	/* Mutator */
	void Input(); //prompt user to input a date, then input date in the format month/day/year, validate the date, if it is not valid, display error message and ask the user to input again. Store the date in corresponding variable
	bool Set(int m, int d, int y); //set the date to the specified values. If the date is invalid, private variable will not be modified and this function should return false. If the date is valid, private variable will be modified, this function should return true
	bool SetFormat(char f); //change format code (char format), only accept D, T, L, J. If other invalid setting code is passed in, do not alter the current format setting. Return true if modification is succeed, false otherwise
	void Increment(int numDays = 1); //move the date forward by the number of calendar days given in the argument. Default value on the parameter is 1 day 
	
	/* Accessor */
	void Show() const; //display date to the screen, first check format setting indicator (char format), then call the corresponding private member function to display the date: ShowD(), ShowT(), ShowL()
	int GetMonth() const; //return month 
	int GetDay() const; //return day 
	int GetYear() const; //return year 
	
	/* Method */
	int Compare(const Date &d) const; //compare two Date objects: the calling object and the parameter. 1) if the calling object comes first chronologically, return -1; 2) if they equal, return 0; 3) if the parameter object comes first, return 1
	
	/* Operator */
	// ++ (day increment)
	Date operator++ ();
	Date operator++ (int);
	// -- (day decrement)
	Date operator-- ();
	Date operator-- (int);
	// - (subtract date, return the number of days between two dates)
	int operator- (const Date& lhs);
	// << (call Show() function to print the date)
	friend std::ostream& operator<< (std::ostream& out, const Date& obj);
	// >> (prompt user to input a date and store in day, month and year)
	friend std::istream& operator>> (std::istream& in, Date& obj);
};

#endif


}

2) .cpp 
{

#include "Date.h"
#include <iostream>
#include <iomanip>

/* Private member function */
bool Date::CheckLeap(int y) const //check if the year is leap year. Yes: return true; No: return false
{
	if (y%4 != 0)
		return false;
	else if (y%100 != 0)
		return true;
	else if (y%400 !=0)
		return false;
	else
		return true;
}

bool Date::CheckDate(int m, int d, int y) //check if the date is valid, valid: return true, invalid: return false
{
	//check if year is negative 
	if (y < 0)
		return false;
	
	//check if month is not within 1~12
	if (m < 1 || m > 12)
		return false;
	
	//check number of days in different month and leap/non-leap year
	switch (m)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (d <= 31 && d >= 1)
			return true;
		else
			return false;
		break;
	
	case 4:
	case 6:
	case 9:
	case 11:
		if (d <= 30 && d >= 1)
			return true;
		else 
			return false;
		break;
	
	case 2: //should consider leap year or not
		if (CheckLeap(y))
		{
			if (d <= 29 && d >= 1)
				return true;
			else
				return false;
		}
		else 
		{
			if (d <= 28 && d >= 1)
				return true;
			else
				return false;			
		}
	}
	
}

int Date::MonthDay(int m, int y) const //input month and year, return the number of days in that month, year (consider leap year)
{
	switch (m)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	
	case 2:
		if (CheckLeap(y))
			return 29;
		else
			return 28;
	}
}

int Date::YearDay(int y) //input year, return the number of days in that year (leap or common)
{
	if (CheckLeap(y))
		return 366;
	else
		return 365;	
}

int Date::AD_Day(int m, int d, int y) const //input a date, return total days since AD
{
	int total_day = 0;
	//calculate year_days
	for (int i = y - 1; i > 0; i--)
	{
		if (CheckLeap(i))
			total_day += 366;
		else
			total_day += 365;
	}
	//calculate month_days
	for (int i = 1; i < m; i++)
		total_day += MonthDay(i, y);
	//add up days
	total_day += d;
	
	return total_day;
}

void Date::AD_Day_to_Date(int total_day, int &m, int &d, int &y) //input a total day, transfer to the corresponding date
{
	int counter = 0;
	//calculate how many years
	while (total_day > 365)
	{
		counter++;
		total_day -= YearDay(counter);
	}

	y = ++counter;

	m = 1;
	while (total_day > 0)
	{
		total_day -= MonthDay(m, y);
		m++;
	}
	
	m--;
	total_day += MonthDay(m, y);

	d = total_day;
}

void Date::ShowD() const //show date in default format, M/D/Y
{
	std::cout << month << "/" << day << "/" << year;
}
void Date::ShowT() const //show date in two-digit format, mm/dd/yy
{
	//backup original output stream settings 
	char oldfill = std::cout.fill();
	
	//re-format
	std::cout.fill('0');
	
	//get last two digit of year 
	int y_2 = year % 100;
	
	//display date in two digit format
	std::cout << std::setw(2) << month << "/" << std::setw(2) << day << "/" << std::setw(2) << y_2;
	
	//return to original format 
	std::cout.fill(oldfill);
} 

void Date::ShowL() const //show date in long format
{
	switch (month)
	{
	case 1: std::cout << "Jan " << day << ", " << year; break;
	case 2: std::cout << "Feb " << day << ", " << year; break;
	case 3: std::cout << "Mar " << day << ", " << year; break;
	case 4: std::cout << "Apr " << day << ", " << year; break;
	case 5: std::cout << "May " << day << ", " << year; break;
	case 6: std::cout << "June " << day << ", " << year; break;
	case 7: std::cout << "July " << day << ", " << year; break;
	case 8: std::cout << "Aug " << day << ", " << year; break;
	case 9: std::cout << "Sept " << day << ", " << year; break;
	case 10: std::cout << "Oct " << day << ", " << year; break;
	case 11: std::cout << "Nov " << day << ", " << year; break;
	case 12: std::cout << "Dec " << day << ", " << year; break;
	}
}

void Date::ShowJ() const //show date in Julian Day form
{
	//get last two digit of the year 
	int y_2 = year % 100;
	
	/* calculate number of days before the month */
	//define a running total 
	int total_days = 0;
	//calculate number of days before this month
	for (int i=1; i<month; i++)
		total_days += MonthDay(i, year);
	//add up number of days this month
	total_days += day;
	
	//backup original fill character
	char oldfill = std::cout.fill();
	
	//apply new fill character
	std::cout.fill('0');
	
	//display date
	std::cout << std::setw(2) << y_2 << "-" << std::setw(3) << total_days;
	
	//return to original fill character 
	std::cout.fill(oldfill);
}

/* Constructor */
Date::Date() //default constructor, initialize with 1/1/2000
{
	day = 1;
	month = 1;
	year = 2000;
	format = 'D'; //default format 
}

Date::Date(int m, int d, int y) //constructor used to initialize date value, if value is invalid, initialize date with 1/1/2000
{
	if (CheckDate(m,d,y))
	{
		month = m;
		day = d;
		year = y;
		format = 'D';
	}
	else
	{
		std::cout << "Invalid input, the date is initialized with 1/1/2000.\n";
		month = 1;
		day = 1;
		year = 2000;
		format = 'D';
	}
}

/* Mutator */
void Date::Input() //prompt user to input a date, then input date in the format month/day/year, validate the date, if it is not valid, display error message and ask the user to input again. Store the date in corresponding variable
{
	std::cout << "Please input the date in month/day/year format: ";
	std::cin >> month;
	std::cin.ignore();
	std::cin >> day;
	std::cin.ignore();
	std::cin >> year;
	
	while (!CheckDate(month, day, year))
	{
		std::cout << "Invalid date, please input the date in month/day/year format: ";
		std::cin >> month;
		std::cin.ignore();
		std::cin >> day;
		std::cin.ignore();
		std::cin >> year;
	}
}

bool Date::Set(int m, int d, int y) //set the date to the specified values. If the date is invalid, private variable will not be modified and this function should return false. If the date is valid, private variable will be modified, this function should return true
{
	if (CheckDate(m,d,y))
	{
		month = m;
		day = d;
		year = y;
		return true;
	}
	else 
		return false;
}

bool Date::SetFormat(char f) //change format code (char format), only accept D, T, L, J. If other invalid setting code is passed in, do not alter the current format setting. Return true if modification is succeed, false otherwise
{
	if (f != 'D' && f != 'T' && f != 'L' && f != 'J')
		return false;
	else
	{
		format = f;
		return true;
	}
}

void Date::Increment(int numDays) //move the date forward by the number of calendar days given in the argument. Default value on the parameter is 1 day
{
	/* Calculate the total day since AD */
	int total_day = AD_Day(month, day, year);
	
	/* Update the number of days */
	total_day += numDays;
	if (total_day >= 1)
		AD_Day_to_Date(total_day, month, day, year);
	else
		std::cout << "Only works with AD year.\n";
}

/* Accessor */
void Date::Show() const //display date to the screen, first check format setting indicator (char format), then call the corresponding private member function to display the date: ShowD(), ShowT(), ShowL()
{
	switch (format)
	{
	case 'D': ShowD(); break;
	case 'T': ShowT(); break;
	case 'L': ShowL(); break;
	case 'J': ShowJ(); break;
	}
}

int Date::GetMonth() const //return month 
{
	return month;
}

int Date::GetDay() const //return day 
{
	return day;
}

int Date::GetYear() const //return year 
{
	return year;
}

/* Method */
int Date::Compare(const Date &d) const //compare two Date objects: the calling object and the parameter. 1) if the calling object comes first chronologically, return -1; 2) if they equal, return 0; 3) if the parameter object comes first, return 1
{
	int total_day_call = AD_Day(month, day, year);
	int total_day_parameter = AD_Day(d.GetMonth(), d.GetDay(), d.GetYear());
	
	int result = total_day_call - total_day_parameter;
	
	if (result < 0)
		return -1;
	if (result == 0)
		return 0;
	if (result > 0)
		return 1;
}

/* Operator */
// ++ (day increment)
Date Date::operator++ ()
{
	Increment();
	return *this;
}

Date Date::operator++ (int)
{
	Date temp = *this;
	Increment();
	return temp;
}

// -- (day decrement)
Date Date::operator-- ()
{
	Increment(-1);
	return *this;	
}

Date Date::operator-- (int)
{
	Date temp = *this;
	Increment(-1);
	return temp;	
}

// - (subtract date, return the number of days between two dates)
int Date::operator- (const Date& lhs)
{
	return AD_Day(month, day, year) - AD_Day(lhs.month, lhs.day, lhs.year);
}

// << (call Show() function to print the date)
std::ostream& operator<< (std::ostream& out, const Date& obj)
{
	obj.Show();
	return out;
}

// >> (prompt user to input a date and store in day, month and year)
std::istream& operator>> (std::istream& in, Date& obj)
{
	int m, d, y;
	std::cout << "Please input month, day and year in the format of mm/dd/yyyy: ";
	std::cin >> m;
	std::cin >> d;
	std::cin >> y;
	
	if (obj.Set(m, d, y))
		std::cout << "Date input succeed!\n";
	else 
		std::cout << "Invalid date, date not stored.\n";
	
	return in;

}



}

3) main program 
{

#include "Month.h"
#include "Date.h"

int main()
{
	Date b;
	std::cin >> b;
	std::cout <<"b = " << b << "\n";
	std::cout << "++b = " << ++b << "\n";
	std::cout << "b++ = " << b++ << "\n";
	std::cout << "b-- = " << b-- << "\n";
	std::cout << "--b = " << --b << "\n";

	Date c(5, 5, 1990);
	std::cout << "b - c = " << b - c << "\n";
	return 0;
}

}


}

9. Feet_inch modification
{

1) .h 
{


#ifndef FEETINCHE_H
#define FEETINCHE_H

class Feet_inch
{
private:
	int feet; //hold value of feet 
	int inch; //hold value of inch 
	void Simplify(); //to simplify feet and inch value. It will check if inch >= 12 or < 0. If inch >= 12, transfer to corresponding value of feet; if inch < 0, subtract from feet and get the final value 
public:
	//constructor 
	Feet_inch(int f = 0, int i = 0) //constructor, initialize values for feet and inch 
	{
		feet = f; inch = i; Simplify();
	}

	/* Mutator */
	void SetFeet(int f)
	{
		feet = f;
	}
	void SetInch(int i)
	{
		inch = i; Simplify(); //after each setting, has to be simplified
	}

	/* Accessor */
	int GetFeet() const
	{
		return feet;
	}
	int GetInch() const
	{
		return inch;
	}

	/* Operator function */
	//+, - operator, add or subtract an int value to inches, then call simplify function to simplify. Return the simplified 
	Feet_inch operator+ (int i);
	Feet_inch operator+ (const Feet_inch &d);
	Feet_inch operator- (int i);
	Feet_inch operator- (const Feet_inch &d);
	//++ operator
	Feet_inch operator++ ();
	Feet_inch operator++ (int);
	Feet_inch operator-- ();
	Feet_inch operator-- (int);
	// >=
	bool operator>= (const Feet_inch& rhs); 
	// <=
	bool operator<= (const Feet_inch& rhs);
	// !=
	bool operator!= (const Feet_inch& rhs);
	
};

#endif

}

2) .cpp 
{

#include "Feet_inch.h"

void Feet_inch::Simplify()
{
	if (inch < 0) //when inch is less than zero, subtract from feet or inch
	{
		feet -= (-inch) / 12 + 1;
		inch += ((-inch) / 12 + 1) * 12;
	}

	else if (inch >= 12) //when inch is greater than 12, add to feet
	{
		feet += inch / 12;
		inch = inch % 12;
	}
}

Feet_inch Feet_inch::operator+ (int i)
{
	Feet_inch temp;
	temp.feet = feet;
	temp.inch = inch + i;
	if (temp.inch < 0 || temp.inch >= 12)
		temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator+ (const Feet_inch &d)
{
	Feet_inch temp;
	temp.feet = feet + d.feet;
	temp.inch = inch + d.inch;
	temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator- (int i)
{
	Feet_inch temp;
	temp.feet = feet;
	temp.inch = inch - i;
	if (temp.inch < 0 || temp.inch >= 12)
		temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator- (const Feet_inch &d)
{
	Feet_inch temp;
	temp.feet = feet - d.feet;
	temp.inch = inch - d.inch;
	temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator++ ()
{
	inch++;
	if (inch < 0 || inch >= 12)
		Simplify();
	return *this;
}

Feet_inch Feet_inch::operator++ (int)
{
	Feet_inch temp = *this; //temp object to hold current value
	inch++;
	if (inch < 0 || inch >= 12)
		Simplify();
	return temp;
}

Feet_inch Feet_inch::operator-- ()
{
	inch--;
	if (inch < 0 || inch >= 12)
		Simplify();
	return *this;
}

Feet_inch Feet_inch::operator-- (int)
{
	Feet_inch temp = *this;
	inch--;
	if (inch < 0 || inch >= 12)
		Simplify();
	return temp;
}

// >=
bool Feet_inch::operator>= (const Feet_inch& rhs)
{
	if (feet * 12 + inch >= rhs.feet * 12 + rhs.inch)
		return true;
	else
		return false;
}

// <=
bool Feet_inch::operator<= (const Feet_inch& rhs)
{
	if (feet * 12 + inch <= rhs.feet * 12 + rhs.inch)
		return true;	
	else
		return false;	
}
// !=
bool Feet_inch::operator!= (const Feet_inch& rhs)
{
	if (feet * 12 + inch != rhs.feet * 12 + rhs.inch)
		return true;	
	else
		return false;	
}



}


}

10. Corporate sales
{

1) .h 
{

#ifndef DIVSALES
#define DIVSALES

class Divsale
{
private:
	static double total_sale;
	double sale[4];
public:
	/* Constructor */
	//add the s1 ~ s4 to total
	Divsale(double s1=0.0, double s2=0.0, double s3=0.0, double s4=0.0);
	
	/* Mutator */
	void SetSale(double s1, double s2, double s3, double s4);
	
	/* Accessor */
	double GetTotal() const
	{ return total_sale; }
	
	/* Operator */
	double& operator[] (int index); //to display sale[i], do boundary check
	
};


#endif

}

2) .cpp 
{

#include "Divsale.h"
#include <iostream>

double Divsale::total_sale = 0.0; //initialize static variable

/* Constructor */
//add the s1 ~ s4 to total
Divsale::Divsale(double s1, double s2, double s3, double s4)
{
	sale[0] = s1;
	sale[1] = s2;
	sale[2] = s3;
	sale[3] = s4;
	
	total_sale += s1 + s2 + s3 + s4;
}

/* Mutator */
void Divsale::SetSale(double s1, double s2, double s3, double s4)
{
	//remove old sale figure from total sale 
	total_sale -= sale[0] + sale[1] + sale[2] + sale[3];
	//assign new value 
	sale[0] = s1;
	sale[1] = s2;
	sale[2] = s3;
	sale[3] = s4;	
	//add to total_sale 
	total_sale += s1 + s2 + s3 + s4;
}


/* Operator */
double& Divsale::operator[] (int index) //to display sale[i], do boundary check
{
	while (index < 0 || index > 3)
	{
		std::cout << "Invalid index, please input another index (0~3): ";
		std::cin >> index;
	}
	
	return sale[index];
}

}

3) main program 
{

#include <iostream>
#include "Divsale.h"
#include <iomanip>

void PrintReport(Divsale s[]);

int main()
{
	Divsale divsale[6];

	double s1, s2, s3, s4;
	//data input
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Please input sale figure for four quarters for each division, separate by space: ";
		std::cin >> s1 >> s2 >> s3 >> s4;
		divsale[i].SetSale(s1, s2, s3, s4);
	}

	//print
	PrintReport(divsale);
	
	return 0;
}

void PrintReport(Divsale s[])
{
	using namespace std;
	
	cout << "Division sale figure\n"
	<< "---------------------\n\n"
	<< "Division#               Q1               Q2               Q3               Q4\n"
	<< "----------------------------------------------------------------------------------\n";
	
	cout << setprecision(2) << fixed;
	
	for (int i=0; i<6; i++)
	{
		cout << setw(5) << i+1 << setw(20) << "$" << setw(11) << s[i][0] << setw(7) << "$" << setw(11) << s[i][1] << setw(7) << "$" << setw(11) << s[i][2] << setw(7) << "$" << setw(11) << s[i][3] << endl;
	}
	
	cout << "----------------------------------------------------------------------------------\n\n";
	cout << "Total sale: " << s[0].GetTotal() << "\n\n";
}

}

}

11. Feet_inch class copy constructor and multiply function 
{

1) .h
{

#ifndef FEETINCHE_H
#define FEETINCHE_H

class Feet_inch
{
private:
	int feet; //hold value of feet 
	int inch; //hold value of inch 
	void Simplify(); //to simplify feet and inch value. It will check if inch >= 12 or < 0. If inch >= 12, transfer to corresponding value of feet; if inch < 0, subtract from feet and get the final value 
public:
	//constructor 
	Feet_inch(int f = 0, int i = 0) //constructor, initialize values for feet and inch 
	{
		feet = f; inch = i; Simplify();
	}

	//copy-constructor 
	Feet_inch(const Feet_inch& obj)
	{
		feet = obj.feet;
		inch = obj.inch;
	}
	
	/* Mutator */
	void SetFeet(int f)
	{
		feet = f;
	}
	void SetInch(int i)
	{
		inch = i; Simplify(); //after each setting, has to be simplified
	}

	/* Accessor */
	int GetFeet() const
	{
		return feet;
	}
	int GetInch() const
	{
		return inch;
	}

	/* Operator function */
	//+, - operator, add or subtract an int value to inches, then call simplify function to simplify. Return the simplified 
	Feet_inch operator+ (int i);
	Feet_inch operator+ (const Feet_inch &d);
	Feet_inch operator- (int i);
	Feet_inch operator- (const Feet_inch &d);
	//++ operator
	Feet_inch operator++ ();
	Feet_inch operator++ (int);
	Feet_inch operator-- ();
	Feet_inch operator-- (int);
	// >=
	bool operator>= (const Feet_inch& rhs); 
	// <=
	bool operator<= (const Feet_inch& rhs);
	// !=
	bool operator!= (const Feet_inch& rhs);
	// *
	Feet_inch operator* (const Feet_inch& rhs);
	
};

#endif

}

2) .cpp 
{

#include "Feet_inch.h"

void Feet_inch::Simplify()
{
	if (inch < 0) //when inch is less than zero, subtract from feet or inch
	{
		feet -= (-inch) / 12 + 1;
		inch += ((-inch) / 12 + 1) * 12;
	}

	else if (inch >= 12) //when inch is greater than 12, add to feet
	{
		feet += inch / 12;
		inch = inch % 12;
	}
}

Feet_inch Feet_inch::operator+ (int i)
{
	Feet_inch temp;
	temp.feet = feet;
	temp.inch = inch + i;
	if (temp.inch < 0 || temp.inch >= 12)
		temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator+ (const Feet_inch &d)
{
	Feet_inch temp;
	temp.feet = feet + d.feet;
	temp.inch = inch + d.inch;
	temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator- (int i)
{
	Feet_inch temp;
	temp.feet = feet;
	temp.inch = inch - i;
	if (temp.inch < 0 || temp.inch >= 12)
		temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator- (const Feet_inch &d)
{
	Feet_inch temp;
	temp.feet = feet - d.feet;
	temp.inch = inch - d.inch;
	temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator++ ()
{
	inch++;
	if (inch < 0 || inch >= 12)
		Simplify();
	return *this;
}

Feet_inch Feet_inch::operator++ (int)
{
	Feet_inch temp = *this; //temp object to hold current value
	inch++;
	if (inch < 0 || inch >= 12)
		Simplify();
	return temp;
}

Feet_inch Feet_inch::operator-- ()
{
	inch--;
	if (inch < 0 || inch >= 12)
		Simplify();
	return *this;
}

Feet_inch Feet_inch::operator-- (int)
{
	Feet_inch temp = *this;
	inch--;
	if (inch < 0 || inch >= 12)
		Simplify();
	return temp;
}

// >=
bool Feet_inch::operator>= (const Feet_inch& rhs)
{
	if (feet * 12 + inch >= rhs.feet * 12 + rhs.inch)
		return true;
	else
		return false;
}

// <=
bool Feet_inch::operator<= (const Feet_inch& rhs)
{
	if (feet * 12 + inch <= rhs.feet * 12 + rhs.inch)
		return true;	
	else
		return false;	
}
// !=
bool Feet_inch::operator!= (const Feet_inch& rhs)
{
	if (feet * 12 + inch != rhs.feet * 12 + rhs.inch)
		return true;	
	else
		return false;	
}

Feet_inch Feet_inch::operator* (const Feet_inch& rhs)
{
	Feet_inch temp;
	temp.SetFeet(feet*rhs.feet);
	temp.SetInch(inch*rhs.inch);
	return temp;
}


}

3) main program 
{

#include <iostream>
#include "Feet_inch.h"

int main()
{
	Feet_inch d1(2, -12);
	std::cout << d1.GetFeet() << " feet " << d1.GetInch() << " inch.\n";
	Feet_inch d2(2, 4);
	Feet_inch d3;
	d3 = d1 * d2;
	std::cout << d3.GetFeet() << " feet " << d3.GetInch() << " inch.\n";
	return 0;
}

}

}

12. Land_tract class 
{

1) .h 
{

#ifndef LANDTRACT_H
#define LANDTRACT_H

#include "Feet_inch.h"

class Land_tract
{
private:
	Feet_inch width;
	Feet_inch length;
public:
	void SetWidth(int f, int i);
	void SetLength(int f, int i);
	
	int Land_tract::GetAreaFeet() const;
	int Land_tract::GetAreaInch() const;
};

#endif

}

2) .cpp 
{

#include "Land_tract.h"

void Land_tract::SetWidth(int f, int i)
{
	width.SetFeet(f);
	width.SetInch(i);
}

void Land_tract::SetLength(int f, int i)
{
	length.SetFeet(f);
	length.SetInch(i);
}

int Land_tract::GetAreaFeet() const
{
	int area_feet;
	
	area_feet = width.GetFeet() * length.GetFeet();
	
	return area_feet;
}

int Land_tract::GetAreaInch() const
{
	int area_inch;
	
	area_inch = width.GetInch() * length.GetInch();
	
	return area_inch;
}

}

3) main program 
{

#include "Land_tract.h"
#include <iostream>

int main()
{
	Land_tract land1;
	land1.SetLength(1, 11);
	land1.SetWidth(2, 11);

	std::cout << "Area is: " << land1.GetAreaFeet() << " square feet and " << land1.GetAreaInch() << " square inch.\n";

	return 0;
}

}

}

13. Carpet calculator (Feet_inch modified)
{

1) Feet_inch class 
{

.h 
{

#ifndef FEETINCHE_H
#define FEETINCHE_H

class Feet_inch
{
private:
	int feet; //hold value of feet 
	int inch; //hold value of inch 
	void Simplify(); //to simplify feet and inch value. It will check if inch >= 12 or < 0. If inch >= 12, transfer to corresponding value of feet; if inch < 0, subtract from feet and get the final value 
public:
	//constructor 
	Feet_inch(int f = 0, int i = 0) //constructor, initialize values for feet and inch 
	{
		feet = f; inch = i; Simplify();
	}

	//copy-constructor 
	Feet_inch(const Feet_inch& obj)
	{
		feet = obj.feet;
		inch = obj.inch;
	}
	
	/* Mutator */
	void SetFeet(int f)
	{
		feet = f;
	}
	void SetInch(int i)
	{
		inch = i; Simplify(); //after each setting, has to be simplified
	}

	/* Accessor */
	int GetFeet() const
	{
		return feet;
	}
	int GetInch() const
	{
		return inch;
	}

	/* Operator function */
	//+, - operator, add or subtract an int value to inches, then call simplify function to simplify. Return the simplified 
	Feet_inch operator+ (int i);
	Feet_inch operator+ (const Feet_inch &d);
	Feet_inch operator- (int i);
	Feet_inch operator- (const Feet_inch &d);
	//++ operator
	Feet_inch operator++ ();
	Feet_inch operator++ (int);
	Feet_inch operator-- ();
	Feet_inch operator-- (int);
	// >=
	bool operator>= (const Feet_inch& rhs); 
	// <=
	bool operator<= (const Feet_inch& rhs);
	// !=
	bool operator!= (const Feet_inch& rhs);
	// * (two Feet_inch objec multiply will give the area, unit: square inch)
	double operator* (const Feet_inch& rhs);
	
};

#endif







}

.cpp 
{

#include "Feet_inch.h"

void Feet_inch::Simplify()
{
	if (inch < 0) //when inch is less than zero, subtract from feet or inch
	{
		feet -= (-inch) / 12 + 1;
		inch += ((-inch) / 12 + 1) * 12;
	}

	else if (inch >= 12) //when inch is greater than 12, add to feet
	{
		feet += inch / 12;
		inch = inch % 12;
	}
}

Feet_inch Feet_inch::operator+ (int i)
{
	Feet_inch temp;
	temp.feet = feet;
	temp.inch = inch + i;
	if (temp.inch < 0 || temp.inch >= 12)
		temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator+ (const Feet_inch &d)
{
	Feet_inch temp;
	temp.feet = feet + d.feet;
	temp.inch = inch + d.inch;
	temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator- (int i)
{
	Feet_inch temp;
	temp.feet = feet;
	temp.inch = inch - i;
	if (temp.inch < 0 || temp.inch >= 12)
		temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator- (const Feet_inch &d)
{
	Feet_inch temp;
	temp.feet = feet - d.feet;
	temp.inch = inch - d.inch;
	temp.Simplify();
	return temp;
}

Feet_inch Feet_inch::operator++ ()
{
	inch++;
	if (inch < 0 || inch >= 12)
		Simplify();
	return *this;
}

Feet_inch Feet_inch::operator++ (int)
{
	Feet_inch temp = *this; //temp object to hold current value
	inch++;
	if (inch < 0 || inch >= 12)
		Simplify();
	return temp;
}

Feet_inch Feet_inch::operator-- ()
{
	inch--;
	if (inch < 0 || inch >= 12)
		Simplify();
	return *this;
}

Feet_inch Feet_inch::operator-- (int)
{
	Feet_inch temp = *this;
	inch--;
	if (inch < 0 || inch >= 12)
		Simplify();
	return temp;
}

// >=
bool Feet_inch::operator>= (const Feet_inch& rhs)
{
	if (feet * 12 + inch >= rhs.feet * 12 + rhs.inch)
		return true;
	else
		return false;
}

// <=
bool Feet_inch::operator<= (const Feet_inch& rhs)
{
	if (feet * 12 + inch <= rhs.feet * 12 + rhs.inch)
		return true;	
	else
		return false;	
}
// !=
bool Feet_inch::operator!= (const Feet_inch& rhs)
{
	if (feet * 12 + inch != rhs.feet * 12 + rhs.inch)
		return true;	
	else
		return false;	
}

double Feet_inch::operator* (const Feet_inch& rhs)
{
	//first calculate total area (unit: square inches), then return
	return (feet * 12 + inch) * (rhs.feet * 12 + rhs.inch);
}




}


}

2) Room_area class 
{

.h 
{

#ifndef ROOMAREA
#define ROOMAREA
#include "Feet_inch.h"
#include <iostream>

class Room_area
{
private:
	Feet_inch width;
	Feet_inch length;
public:
	/* Mutator */
	void SetWidth(int f, int i)
	{ width.SetFeet(f); width.SetInch(i); }
	
	void SetLength(int f, int i)
	{ length.SetFeet(f); length.SetInch(i); }
	
	/* Accessor */
	Feet_inch GetWidth() const
	{ return width; }
	
	Feet_inch GetLength() const
	{ return length; }
	
	/* Operator */
	// << (for printing)
	friend std::ostream& operator<< (std::ostream& out, const Room_area& obj); //print out area, xxx square feet xxx square inches
	
	/* Conversion */
	//convert to double (unit: square foot)
	operator double()
	{
		return width*length;
	}
};


#endif

}

.cpp 
{

#include "Room_area.h"

/* Operator */
// << (for printing)
std::ostream& operator<< (std::ostream& out, const Room_area& obj) //print out area, xxx square feet xxx square inches
{
	int square_feet = obj.GetLength() * obj.GetWidth()/144;
	int square_inches = (obj.GetLength() * obj.GetWidth()) - square_feet * 144;

	out << square_feet << " square feet and " << square_inches << " square inches";

	return out;
}

}


}

3) Roomcarpet class 
{

.h 
{

#ifndef ROOMCARPET_H
#define ROOMCARPET_H
#include "Room_area.h"

class Roomcarpet
{
private:
	Room_area area;
	double cost_per_inch2;
public:
	/* Constructor */
	Roomcarpet(double cost = 0)
	{
		cost_per_inch2 = cost;
	}

	double GetCost(); //return the cost for the carpet

	void SetWidth(int f, int i);
	void SetLength(int f, int i);

	void SetCost(double cost)
	{
		cost_per_inch2 = cost;
	}
};

#endif

}


.cpp 
{

#include "Roomcarpet.h"

double Roomcarpet::GetCost() //return the cost for the carpet
{
	return cost_per_inch2 * area;
}

void Roomcarpet::SetWidth(int f, int i)
{
	area.SetWidth(f, i);
}

void Roomcarpet::SetLength(int f, int i)
{
	area.SetLength(f, i);
}

}



}

4) main program 
{

#include "Roomcarpet.h"
#include <iostream>

int main()
{
	Roomcarpet r1;
	r1.SetCost(10);
	r1.SetLength(15,5);
	r1.SetWidth(11, 3);

	std::cout << r1.GetCost() << " dollars.\n";

	return 0;
}

}


}

14. Parking ticket simulator
{

1) Parked_car class 
{

.h 
{

#ifndef PARKEDCAR_H
#define PARKEDCAR_H
#include "Mystring.h"
#include "Police.h"

class Park_meter;
class Park_ticket;

class Parked_car
{
private:
	Mystring make;
	Mystring model;
	Mystring color;
	Mystring plate;
	int parked_time; //number of minute that the car has been parked
public:
	/* Constructor */
	//initialize the car
	Parked_car(Mystring ma, Mystring mo, Mystring co, Mystring pl, int t);
	
	/* Friend */
	friend bool Police::CheckCar(const Parked_car& car, const Park_meter& meter);
	friend void Police::WriteTicket(const Parked_car& car, const Park_meter& meter, Park_ticket& ticket);
};


#endif

}

.cpp 
{

#include "Parked_car.h"
/* Constructor */
//initialize the car
Parked_car::Parked_car(Mystring ma, Mystring mo, Mystring co, Mystring pl, int t)
{
	make = ma;
	model = mo;
	color = co;
	plate = pl;
	parked_time = t;
}

}

}

2) Park_meter class 
{

.h 
{

#ifndef PARKMETER_H
#define PARKMETER_H
#include "Police.h"

class Parked_car;
class Park_ticket;

class Park_meter
{
private:
	int purchased_time;
public:
	/* Constructor */
	Park_meter(int t);

	/* Friend */
	friend bool Police::CheckCar(const Parked_car& car, const Park_meter& meter); //grant access to this function
	friend void Police::WriteTicket(const Parked_car& car, const Park_meter& meter, Park_ticket& ticket);
};


#endif

}

.cpp 
{

#include "Park_meter.h"

/* Constructor */
Park_meter::Park_meter(int t)
{
	purchased_time = t;
}

}

}

3) Park_ticket class 
{

.h 
{

#ifndef PARKTICKET_H
#define PARKTICKET_H
#include "Mystring.h"
#include <iostream>
#include "Police.h"

class Parked_car;
class Park_meter;


class Park_ticket
{
private:
	//car info 
	Mystring make;
	Mystring model;
	Mystring color;
	Mystring plate;
	//park info
	int purchased_time;
	int parked_time;
	double fine;
	//police info 
	Mystring name;
	Mystring badge;
	//fine rate 
	static const int base_fine; //$25 for the first hour
	static const int rate; //$10 for every hour
	
	/* Ticket written status */
	bool written;
		
public:
	/* Constructor */
	//initialize with blank info. Park_ticket can only be modified by Police object
	Park_ticket();
	
	/* Accessor */
	bool GetStatus() const
	{ return written; }
	
	/* Friend */
	//only police object can modify private member of ticket
	friend void Police::WriteTicket(const Parked_car& car, const Park_meter& meter, Park_ticket& ticket);
	
	/* Operator */
	// << (to display the content of the ticket)
	friend std::ostream& operator<< (std::ostream& out, const Park_ticket& t);
	
};

#endif

}

.cpp 
{

#include "Park_ticket.h"

//define static variable
const int Park_ticket::base_fine = 25;
const int Park_ticket::rate = 10;

/* Constructor */
//initialize with blank info. Park_ticket can only be modified by Police object
Park_ticket::Park_ticket()
{
	make = "N/A";
	model = "N/A";
	color = "N/A";
	plate = "N/A";
	purchased_time = 0;
	parked_time = 0;
	fine = 0.0;
	name = "N/A";
	badge = "N/A";
	written = false;
}

/* Operator */
// << (to display the content of the ticket)
std::ostream& operator<< (std::ostream& out, const Park_ticket& t)
{
	out << "Car info:\n";
	out << "Make: " << t.make << "\n"
	<< "Model: " << t.model << "\n"
	<< "Color: " << t.color << "\n"
	<< "Plate number: " << t.plate << "\n";
	
	out << "Park info: \n"
	<< "Purchased time: " << t.purchased_time << "\n"
	<< "Parked time: " << t.parked_time << "\n"
	<< "Fine: $ " << t.fine << "\n";
	
	out << "Police officer:\n"
	<< "Name: " << t.name << "\n"
	<< "Badge: " << t.badge << "\n\n";
	
	return out;
	
}

}

}

4) Police class 
{

.h 
{

#ifndef POLICE_H
#define POLICE_H
#include "Mystring.h"

class Parked_car;
class Park_meter;
class Park_ticket;

class Police
{
private:
	//police info 
	Mystring name;
	Mystring badge;
	
public:
	/* Constructor */
	//initialize the police officer
	Police(Mystring n, Mystring b);
	
	/* Function */
	bool CheckCar(const Parked_car& car, const Park_meter& meter); //check park time and purchased time, if expired, return true 
	
	void WriteTicket(const Parked_car& car, const Park_meter& meter, Park_ticket& ticket); //write a ticket for an illegally parked car, can access private members of a ticket
};


#endif

}

.cpp 
{

#include "Police.h"
#include "Parked_car.h"
#include "Park_meter.h"
#include "Park_ticket.h"

/* Constructor */
//initialize the police officer
Police::Police(Mystring n, Mystring b)
{
	name = n;
	badge = b;
}

/* Function */
bool Police::CheckCar(const Parked_car& car, const Park_meter& meter) //check park time and purchased time, if expired, return true
{
	if (car.parked_time > meter.purchased_time)
		return true;
	else 
		return false;
}

void Police::WriteTicket(const Parked_car& car, const Park_meter& meter, Park_ticket& ticket) //write a ticket for an illegally parked car, can access private members of a ticket
{
	/* Check ticket content */
	if (ticket.written == true)
	{
		std::cout << "Ticket already written, please change a ticket and try again.\n";
		return;
	}
	
	ticket.written = true;
	
	/* Calculate fine */
	int exceed_time = car.parked_time - meter.purchased_time;
	
	if (exceed_time <= 60)
		ticket.fine = ticket.base_fine;
	else
	{
		ticket.fine += ticket.base_fine;
		int exceed_hour = exceed_time/60;
		if (exceed_time % 60 != 0)
			exceed_hour++;
		ticket.fine += exceed_hour * ticket.rate;
	}
	
	/* Write info onto the ticket */
	ticket.make = car.make;
	ticket.model = car.model;
	ticket.color = car.color;
	ticket.plate = car.plate;
	ticket.purchased_time = meter.purchased_time;
	ticket.parked_time = car.parked_time;
	ticket.name = name;
	ticket.badge = badge;
	
}

}

}


}

15. Car Instrument Simulator
{

1) Fuel_gauge class 
{

.h 
{

#ifndef FUELGAUGE_H
#define FUELGAUGE_H
#include "Odometer.h"

class Fuel_gauge
{
private:
	int fuel;
	static int maximum_fuel; //define = 15
public:
	/* Constructor */
	Fuel_gauge() //initialize with 15 gallon
	{ fuel = maximum_fuel; }
	
	/* Accessor */
	int GetFuel() const
	{ return fuel; }
	
	/* Mutator */
	void Fill(int gas = 1); //fill the gas tank, maximum = maximum_fuel
	void Burn(); //burn 1 gallon fuel
	
	/* Friend */
	friend void Odometer::Increment(Fuel_gauge& fuel); 
};

#endif

}

.cpp 
{

#include "Fuel_gauge.h"
#include <iostream>

int Fuel_gauge::maximum_fuel = 15;

/* Mutator */
void Fuel_gauge::Fill(int gas) //fill up the gas tank, maximum = maximum_fuel
{
	if (gas + fuel > maximum_fuel)
	{
		std::cout << "The car's gas tank can only hold 15 gallon gas. Added to 15 gallon.\n";
		fuel = 15;
	}
	
	else 
		fuel += gas;
}

void Fuel_gauge::Burn() //burn 1 gallon fuel
{
	fuel--;
}

}


}

2) Odometer class 
{

.h 
{


#ifndef ODOMETER_H
#define ODOMETER_H

class Fuel_gauge;

class Odometer
{
private:
	int mileage;
	int gallon_mile; //hold the mileage of current fuel cycle, if it is >= fuel_economy, subtract fuel_economy and decrease fuel gauge by 1 (24 mile per gallon)
	
	static int fuel_economy; //24 mile per gallon
	static int max_mileage; //999999
	
public:
	/* Constructor */
	Odometer(int m = 10000)
	{
		mileage = m;
		gallon_mile = 0;
	}
	
	/* Accessor */
	int GetMileage() const 
	{ return mileage; }
	
	/* Mutator */
	// increase mileage by 1, if mileage > 999999, mileage -= 999999; Check fuel first before  do the increment. If gallon_mile >= 24 after increment, burn 1 gallon fuel
	void Increment(Fuel_gauge& f); 

	
};


#endif

}


.cpp 
{

#include "Odometer.h"
#include "Fuel_gauge.h"
#include <iostream>

// define static member variable
int Odometer::fuel_economy = 24;
int Odometer::max_mileage = 999999;

/* Mutator */
// increase mileage by 1, if mileage > 999999, mileage -= 999999; Check fuel first before  do the increment. If gallon_mile >= 24 after increment, burn 1 gallon fuel
void Odometer::Increment(Fuel_gauge& f)
{
	if (f.fuel == 0)
	{
		std::cout << "No fuel! Please re-fill the car.\n";
		return;
	}
	
	mileage++;
	gallon_mile++;
	if (mileage > max_mileage)
		mileage = 0;
	
	if (gallon_mile == fuel_economy)
	{
		f.Burn(); //call Burn() function to burn 1 gallon fuel 
		gallon_mile = 0; //re-set gallon mile
	}
	
}

}


}

3) main program 
{

#include "Fuel_gauge.h"
#include "Odometer.h"
#include <iostream>

int main()
{
	Fuel_gauge f1;
	Odometer o1;

	while (f1.GetFuel() > 0)
	{
		//increase distance
		o1.Increment(f1);

		//print current mileage and amount of fuel
		std::cout << "Current mileage: " << o1.GetMileage() << "\n";
		std::cout << "Current fuel: " << f1.GetFuel() << "\n\n";
	}
	return 0;
}

}

}









































/**********************************************************/
/** Patience and diligence, like faith, remove mountains **/
/**********************************************************/



