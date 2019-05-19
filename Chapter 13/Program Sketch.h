/* Chapter 13. Introduction to Classes */

/*********************/
/***Program Example***/
/*********************/

1.2. A Class Demonstration Program (multiple class objects)
{

#include <iostream>

const double PI = 3.1415926535;

class Circle
{
private:
	double radius; //hold the radius of the circle 
public:
	void set_radius(); //ask for radius of the circle
	double display_volume() const; //return the area of the circle 	
};

int main()
{
	Circle sun; //define a Circle class object
	Circle earth; //define another Circle class object

	std::cout << "Sun's data:\n";
	sun.set_radius(); //call sun's member function to get the radius 
	std::cout << "Earth's data:\n";
	earth.set_radius(); //call earth's member function to get the radius

	std::cout << "The Sun's volume is: " << sun.display_volume() << "\n";
	std::cout << "The Earth's volume is: " << earth.display_volume() << "\n";

	return 0;
}

void Circle::set_radius()
{
	std::cout << "Please input the radius: ";
	std::cin >> radius;
}

double Circle::display_volume() const
{
	return 4.0 / 3 * PI*radius*radius*radius;
}



}

3. Practice using Pointers to Objects
{

#include <iostream>

const double PI = 3.1415926535;

class Circle
{
private:
	double radius; //hold the radius of the circle 
public:
	void set_radius(); //ask for radius of the circle
	double display_volume() const; //return the area of the circle 	
	double radius2;
};

int main()
{
	//define Circle pointers, and allocate them memory space
	Circle *moon_ptr = new Circle;
	Circle *sun_ptr = new Circle;
	Circle *earth_ptr = new Circle;

	//get data
	std::cout << "Sun data:\n";
	sun_ptr->set_radius();
	std::cout << "Earth data:\n";
	earth_ptr->set_radius();
	std::cout << "Moon data:\n";
	moon_ptr->set_radius();

	//display volume
	std::cout << "Sun's volume: " << sun_ptr->display_volume() << "\n";
	std::cout << "Earth's volume: " << earth_ptr->display_volume() << "\n";
	std::cout << "Moon's volume: " << moon_ptr->display_volume() << "\n";
	std::cout << "The total volume is: " << sun_ptr->display_volume + earth_ptr->display_volume + moon_ptr->display_volume << "\n";
	
	//destroy allocated memory spaces
	delete sun_ptr;
	delete earth_ptr;
	delete moon_ptr;
	sun_ptr = nullptr;
	earth_ptr = nullptr;
	moon_ptr = nullptr;

	return 0;
}

void Circle::set_radius()
{
	std::cout << "Please input the radius: ";
	std::cin >> radius;
}

double Circle::display_volume() const
{
	return 4.0 / 3 * PI*radius*radius*radius;
}



}

4. Practice using smart pointer to objects
{

#include <iostream>
#include <memory>

class Student
{
private:
	double score1;
	double score2;
	double score3;
public:
	void set_score1(double score);
	void set_score2(double score);
	void set_score3(double score);
	double average() const;
	double highest() const;
	double lowest() const;
};

int main()
{
	std::unique_ptr<Student> student1_ptr(new Student); //define a pointer, allocate memory space
	
	/* Ask for score, and store in object */
	double score;
	//score 1
	std::cout << "What is score 1 for this student: ";
	std::cin >> score;
	student1_ptr->set_score1(score);
	//score 2
	std::cout << "What is score 2 for this student: ";
	std::cin >> score;
	student1_ptr->set_score2(score);
	//score 3
	std::cout << "What is score 3 for this student: ";
	std::cin >> score;
	student1_ptr->set_score3(score);
	
	/* Show result */
	//average
	std::cout << "The average score is: " << student1_ptr->average() << "\n";
	//highest score 
	std::cout << "The highest score is: " << student1_ptr->highest() << "\n";
	//lowest score 
	std::cout << "The lowest score is: " << student1_ptr->lowest() << "\n";
	
	return 0;	
	
}

//set score function
void Student::set_score1(double score)
{
	score1 = score;
}

void Student::set_score2(double score)
{
	score2 = score;
}

void Student::set_score3(double score)
{
	score3 = score;
}

//calculate and return average value
double Student::average() const
{
	return (score1+score2+score3)/3;
}

//find high score
double Student::highest() const
{
	double high = score1;
	if (high < score2)
		high = score2;
	if (high < score3)
		high = score3;
	
	return high;
}

//find low score 
double Student::lowest() const 
{
	double low = score1;
	if (low > score2)
		low = score2;
	if (low > score3)
		low = score3;
	
	return low;
}


}

Checkpoint 13.5
{

1) Test if definition of member function can call other functions
{
#include <iostream>
#include <memory>

//class declaration
class Date
{
private:
	char date[11]; //hold character form of date
public:
	void set_date(); //to ask user to input date and store into date[11]
	void display_date() const; //display date stored in date[11]
};

//function prototype
bool date_check(char *date);

int main()
{
	std::unique_ptr<Date> birthday_ptr(new Date);
	birthday_ptr->set_date();
	std::cout << "The birthday is set to: ";
	birthday_ptr->display_date();
	std::cout << "\n";

	return 0;
}

bool date_check(char *date)
{
	/* Check if the date array has 10 characters */
	if (strlen(date) != 10)
		return 0;

	/* Check if the third, sixth element is '/' */
	if (date[2] != '/' && date[5] != '/')
		return 0;

	/* Extract month, days and years */
	char month_ch[2] = { date[0], date[1] };
	char day_ch[2] = { date[3], date[4] };
	char year_ch[4] = { date[6], date[7], date[8], date[9] };
	int month = atoi(month_ch);
	int day = atoi(day_ch);
	int year = atoi(year_ch);

	/*
	Check month, day and year:
	1) check month: within 1~12;
	2) month 1, 3, 5, 7, 8, 10, 12 should have days between 1~31;
	3) month 4, 6, 9, 11 should have days between 1~30;
	4) month 2: check year. If its a leap year, day should between 1~29, otherwise 1~28;
	*/
	if (month > 12 || month < 1)
		return 0;

	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day < 1 || day > 31)
			return 0;
		else
			return 1;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day < 1 || day > 30)
			return 0;
		else
			return 1;
		break;
	case 2:
		//check the year is leap year or not
		bool leap_year; //hold wether the year is leap year
		if (year % 4 != 0)
			leap_year = false;
		else if (year % 100 != 0)
			leap_year = true;
		else if (year % 400 != 0)
			leap_year = false;
		else
			leap_year = true;

		//check number of days in Feburary
		if (leap_year)
		{
			if (day < 1 || day > 29)
				return 0;
		}

		else
			if (day < 1 || day > 28)
				return 0;

		return 1;
	}


}

void Date::set_date()
{
	//prompt user to input 
	std::cout << "Please input the date in mm/dd/yyyy format: ";
	std::cin.getline(date, 11);
	//date format check 
	while (!date_check(date))
	{
		std::cout << "Invalid format, please input the date in mm/dd/yyyy: ";
		std::cin.getline(date, 11);
	}
}

void Date::display_date() const
{
	std::cout << date;
}


}

2) Test if definition of member function can call member function in same class 
{

#include <iostream>
#include <memory>


class Date
{
private:
	char date[11]; //hold character form of date
public:
	void set_date(); //to ask user to input date and store into date[11]
	void display_date() const; //display date stored in date[11]
	bool date_check() const; //check the date format 
};

int main()
{
	std::unique_ptr<Date> birthday_ptr(new Date);
	birthday_ptr->set_date();
	std::cout << "The birthday is set to: ";
	birthday_ptr->display_date();
	std::cout << "\n";

	return 0;
}

bool Date::date_check() const
{
	/* Check if the date array has 10 characters */
	if (strlen(date) != 10)
		return 0;

	/* Check if the third, sixth element is '/' */
	if (date[2] != '/' && date[5] != '/')
		return 0;

	/* Extract month, days and years */
	char month_ch[2] = { date[0], date[1] };
	char day_ch[2] = { date[3], date[4] };
	char year_ch[4] = { date[6], date[7], date[8], date[9] };
	int month = atoi(month_ch);
	int day = atoi(day_ch);
	int year = atoi(year_ch);

	/*
	Check month, day and year:
	1) check month: within 1~12;
	2) month 1, 3, 5, 7, 8, 10, 12 should have days between 1~31;
	3) month 4, 6, 9, 11 should have days between 1~30;
	4) month 2: check year. If its a leap year, day should between 1~29, otherwise 1~28;
	*/
	if (month > 12 || month < 1)
		return 0;

	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day < 1 || day > 31)
			return 0;
		else
			return 1;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day < 1 || day > 30)
			return 0;
		else
			return 1;
		break;
	case 2:
		//check the year is leap year or not
		bool leap_year; //hold wether the year is leap year
		if (year % 4 != 0)
			leap_year = false;
		else if (year % 100 != 0)
			leap_year = true;
		else if (year % 400 != 0)
			leap_year = false;
		else
			leap_year = true;

		//check number of days in Feburary
		if (leap_year)
		{
			if (day < 1 || day > 29)
				return 0;
		}

		else
			if (day < 1 || day > 28)
				return 0;

		return 1;
	}


}

void Date::set_date()
{
	//prompt user to input 
	std::cout << "Please input the date in mm/dd/yyyy format: ";
	std::cin.getline(date, 11);
	//date format check 
	while (!date_check())
	{
		std::cout << "Invalid format, please input the date in mm/dd/yyyy: ";
		std::cin.getline(date, 11);
	}
}

void Date::display_date() const
{
	std::cout << date;
}



}

3) Test if definition of member function can call public member function in other class (failed to compile)
{

#include <iostream>
#include <memory>


class Date
{
private:
	char date[11]; //hold character form of date
public:
	void set_date(); //to ask user to input date and store into date[11]
	void display_date() const; //display date stored in date[11]
};

class Date_check
{
public:
	bool date_check(char *date); //check the date format 
};

int main()
{
	std::unique_ptr<Date> birthday_ptr(new Date);
	birthday_ptr->set_date();
	std::cout << "The birthday is set to: ";
	birthday_ptr->display_date();
	std::cout << "\n";

	return 0;
}

bool Date_check::date_check(char *date)
{
	/* Check if the date array has 10 characters */
	if (strlen(date) != 10)
		return 0;

	/* Check if the third, sixth element is '/' */
	if (date[2] != '/' && date[5] != '/')
		return 0;

	/* Extract month, days and years */
	char month_ch[2] = { date[0], date[1] };
	char day_ch[2] = { date[3], date[4] };
	char year_ch[4] = { date[6], date[7], date[8], date[9] };
	int month = atoi(month_ch);
	int day = atoi(day_ch);
	int year = atoi(year_ch);

	/*
	Check month, day and year:
	1) check month: within 1~12;
	2) month 1, 3, 5, 7, 8, 10, 12 should have days between 1~31;
	3) month 4, 6, 9, 11 should have days between 1~30;
	4) month 2: check year. If its a leap year, day should between 1~29, otherwise 1~28;
	*/
	if (month > 12 || month < 1)
		return 0;

	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day < 1 || day > 31)
			return 0;
		else
			return 1;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day < 1 || day > 30)
			return 0;
		else
			return 1;
		break;
	case 2:
		//check the year is leap year or not
		bool leap_year; //hold wether the year is leap year
		if (year % 4 != 0)
			leap_year = false;
		else if (year % 100 != 0)
			leap_year = true;
		else if (year % 400 != 0)
			leap_year = false;
		else
			leap_year = true;

		//check number of days in Feburary
		if (leap_year)
		{
			if (day < 1 || day > 29)
				return 0;
		}

		else
			if (day < 1 || day > 28)
				return 0;

		return 1;
	}


}

void Date::set_date()
{
	//prompt user to input 
	std::cout << "Please input the date in mm/dd/yyyy format: ";
	std::cin.getline(date, 11);
	//date format check 
	while (!Date_check::date_check(Date::date))
	{
		std::cout << "Invalid format, please input the date in mm/dd/yyyy: ";
		std::cin.getline(date, 11);
	}
}

void Date::display_date() const
{
	std::cout << date;
}



}

}

5. Practice using class specification and class implementation file
{

1) class specification
{

//This is the specification of class Student

//this ifndef section is served as include guard, it can ensure that the declaration of class Student will only occur once
//if a certain constant has been found defined, it means the class has already been defined before, just skip that 

#ifndef Student_h
#define Student_h

//class declaration
class Student
{
private:
	double score1;
	double score2;
	double score3;
public:
	void set_score(double s1, double s2, double s3);
	double get_average() const;
};

#endif

}

2) class implementation
{

//This is the implementation file of the class Student, it contains the definition of member functions
#include "Student.h"

//set score function 
void Student::set_score(double s1, double s2, double s3)
{
	score1 = s1;
	score2 = s2;
	score3 = s3;
}


double Student::get_average() const
{
	return (score1 + score2 + score3) / 3;
}

}

3) main program
{

#include <iostream>
#include "Student.h"

int main()
{
	//define a Student object
	Student Zack;

	//call set_score function to set scores for Zack
	Zack.set_score(59.9, 58, 44.4);

	//call get_average function to display the average score for Zack
	std::cout << "The average score for Zack is: " << Zack.get_average() << "\n";

	return 0;
}

}

}

6. Practice using constructor
{

#include <iostream>
#include "Student.h"

class Demo
{
public:
	Demo(); //constructor
};

int main()
{
	Demo demo1;

	return 0;
}

Demo::Demo()
{
	std::cout << "Welcome to the constructor!\n";
}

}

7. Practice using constructor II: with parameter to initialize a private member variable (attributes)
{

1) class specification
{

//This is the specification of class Student

//this ifndef section is served as include guard, it can ensure that the declaration of class Student will only occur once
//if a certain constant has been found defined, it means the class has already been defined before, just skip that 

#ifndef Student_h
#define Student_h

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
	void set_score(double s1, double s2, double s3);
	double get_average() const
	{
		return (score1 + score2 + score3) / 3;
	}
	void display_name() const;
};

#endif

}

2) class implementation
{

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

//constructor
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


}

3) main program
{

#include <iostream>
#include "Student.h"

int main()
{
	Student student1("Zack");
	student1.display_name();

	return 0;
}

}

}

8. Practice using constructor III: same as II
{

1) class specification
{

#ifndef Rectangle_h
#define Rectangle_h

class Rectangle
{
private:
	double width;
	double length;
public:
	Rectangle(double w=0.0, double l=0.0);
	void set_width(double w);
	void set_length(double l);
	double get_width() const
	{
		return width;
	}
	double get_length() const
	{
		return length;
	}
	double get_area() const
	{
		return width*length;
	}
};

#endif

}

2) class implementation
{

#include "Rectangle.h"

//constructor definition
Rectangle::Rectangle(double w, double l)
{
	width = w;
	length = l;
}

void Rectangle::set_width(double w)
{
	width = w;
}

void Rectangle::set_length(double l)
{
	length = l;
}


}

3) main program
{

#include <iostream>
#include "Rectangle.h"

int main()
{
	Rectangle *rec1_ptr = new Rectangle(1, 2);
	std::cout << "The length is: " << rec1_ptr->get_length() << "\n";
	rec1_ptr->set_length(3);
	std::cout << "The length is: " << rec1_ptr->get_length() << "\n";

	return 0;
}

}

}

9. Practice using constructor IV: another example, Sale class 
{

1) class specification 
{

#ifndef Sale_h
#define Sale_h

class Sale
{
private:
	double item_cost;
	double tax_rate;
public:
	//constructor
	Sale(double price, double rate);
	//return price
	double get_price() const
	{
		return item_cost;
	}
	//return tax rate 
	double get_rate() const
	{
		return tax_rate;
	}
	//show tax 
	double get_tax() const
	{
		return item_cost*tax_rate;
	}
	//show retail price 
	double get_retail_price() const
	{
		return item_cost + get_tax();
	}
};

#endif

}

2) class implementation 
{

#include "Sale.h"


Sale::Sale(double price, double rate)
{
	item_cost = price;
	tax_rate = rate;
}


}

3) main program 
{

#include <iostream>
#include "Sale.h"

int main()
{
	Sale item1(2.5, 0.25);
	std::cout << "The price for item1 is: $" << item1.get_retail_price() << "\n";
	std::cout << "Item cost: $" << item1.get_price() << "\n";
	std::cout << "Tax: $" << item1.get_tax() << "\n";

	return 0;
}

}

}

10. Practice using constructor V: using default argument 
{

(same as 8)

}

11. Demonstration of destructor I
{

1) class specification
{

#ifndef SPHERE_H
#define SPHERE_H
#include <iostream>

class Sphere
{
private:
	double radius; //the radius of the sphere
	char name[20]; //the name of the sphere
public:

	Sphere(char *str); //constructor
	~Sphere() //destructor
	{
		std::cout << name << " has been destroyed.\n";
	}

	char *show_name();
	void set_radius(double r);
	double get_radius() const;
};


#endif

}

2) class implementation
{

#include "Sphere.h"
#include <iostream>

void strcpy2(char *destination, const char *source); //function prototype for strcpy function

void Sphere::set_radius(double r)
{
	if (r > 0)
		radius = r;
	else
	{
		std::cout << "Invalid input, program exit...\n";
		exit(EXIT_FAILURE);
	}

}


double Sphere::get_radius() const
{
	return radius;
}

Sphere::Sphere(char *str) //constructor
{
	strcpy2(name, str); //copy string stored in str to name, to initialize the name of ab object
}


char *Sphere::show_name()
{
	return name;
}

void strcpy2(char *destination, const char *source)
{
	int i = 0;
	while (source[i] != '\0')
		destination[i] = source[i++];
	destination[i] = '\0';
}

}

3) main function 
{

#include <iostream>
#include "Sphere.h"

void check_destroy();

int main()
{
	Sphere sph1("Sun");
	std::cout << sph1.show_name() << "\n";
	check_destroy();

	return 0;
}

void check_destroy()
{
	Sphere sph2("Earth");
}

}


}

12. Demonstration of destructor II: delete dynamically allocated memory
{

1) class specification
{

#ifndef CONTACT_H
#define CONTACT_H

class Contact
{
private:
	char *name;
	char *phone;
public:
	Contact(char *n, char *p);
	~Contact();
	char *get_name();
	char *get_phone();
};

#endif

}

2) class implementation 
{

#include "Contact.h"
#include <iostream>

//C-string copy function, should include the function body if none included
void strcpy2(char *destination, const char *source);
//constructor
Contact::Contact(char *n, char *p)
{
	int length_name = strlen(n) + 1;
	int length_phone = strlen(p) + 1; //+1 is for the null terminator

									  //allocate memory
	name = new char[length_name];
	phone = new char[length_phone];

	//copy the content
	strcpy2(name, n);
	strcpy2(phone, p);
}
//destructor
Contact::~Contact()
{
	//delete the dynamically allocated memory
	delete[] name;
	delete[] phone;
	std::cout << "Name and phone deleted.\n";
}
//get name function
char *Contact::get_name()
{
	//allocate new memory space
	int length_name = strlen(name) + 1;
	char *name_ptr = new char[length_name];
	//copy name to the new space 
	strcpy2(name_ptr, name);
	//return the newly defined address 
	return name_ptr;
}
//get phone function
char *Contact::get_phone()
{
	//allocate new memory space 
	int length_phone = strlen(phone) + 1;
	char *phone_ptr = new char[length_phone];
	//copy phone to the new space 
	strcpy2(phone_ptr, phone);
	//return the newly defined address 
	return phone_ptr;
}


}

3) main function 
{

#include <iostream>
#include "Contact.h"

int main()
{
	Contact c1("Yu Miao", "8505245269");
	std::cout << "Name: " << c1.get_name() << "\n";
	c1.~Contact();
	std::cout << "Phone: " << c1.get_phone() << "\n";

	return 0;
}


}

}

13. Overload constructor
{

1) class specification
{

#ifndef INVENTORY_ITEM_H
#define INVENTORY_ITEM_H

#include <string>

class Inventory_item
{
private:
	std::string description; //the item description
	double cost; //the item's cost 
	int stock; //the number of stock 
public:
	/* Overload constructor */
	//constructor 1
	Inventory_item()
	{
		description = "";
		cost = 0;
		stock = 0;
	}
	//constructor 2
	Inventory_item(std::string str)
	{
		description = str;
		cost = 0;
		stock = 0;
	}
	//constructor 3
	Inventory_item(std::string str, double cost_input)
	{
		description = str;
		cost = cost_input;
		stock = 0;
	}
	//constructor 4
	Inventory_item(std::string str, double cost_input, int stock_input)
	{
		description = str;
		cost = cost_input;
		stock = stock_input;
	}

	/* Mutator function */
	//set description 
	void set_description(std::string str)
	{
		description = str;
	}
	//set price
	void set_cost(double cost_input)
	{
		cost = cost_input;
	}
	//set stock number 
	void set_stock(int stock_input)
	{
		stock = stock_input;
	}

	/* Accessor function */
	//get description
	std::string get_description() const
	{
		return description;
	}
	//get cost 
	double get_cost() const
	{
		return cost;
	}
	//get stock 
	int get_stock() const
	{
		return stock;
	}

};

#endif




}

2) main program 
{

#include <iostream>
#include "Inventory_item.h"

int main()
{
	Inventory_item ruler("ruler", 25.5);
	Inventory_item apple("apple", 12.5, 5);
	std::cout << "Ruler price: " << ruler.get_cost() << "\n";
	std::cout << "Apple number: " << apple.get_stock() << "\n";


	return 0;

}

}

}

14. Array of Objects 
{

1) class specification 
{


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

}

2) class implementation 
{


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


}

3) main program 
{

#include <iostream>
#include "Student.h"

const int NUM = 5;
int main()
{
	//create an array of objects
	Student class_083[NUM] = { "Yu Miao", "Yingying" };

	//set score for each object
	for (int i = 0; i<NUM; i++)
		class_083[i].set_score(90 + i, 90 - i, 85 + 2 * i);

	//display score and name
	for (int i = 0; i<NUM; i++)
	{
		std::cout << "\nName: ";
		class_083[i].display_name();
		std::cout << "\n";
		class_083[i].display_score();
	}

	return 0;

}

}

}

15. Case study: bank account object
{
	
1) class specification 
{

//class specification 
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account
{
private:
	std::string name; //name of account holder
	double balance; //balance of the account
	double interest_rate; //interest rate, will be initialized by constructor: 0.045
	double interest; //current interest earned, will be calculated by calc_interest function
	int transactions; //record the number of transactions done total for this account, withdraw and deposit is considered as transaction, while calc interest is not
public:
	//constructor 
	Account(); //default constructor if no names are provided, name will be: N/A 
	Account(std::string name_input); //constructor, will initialize name, balance, interest rate, interest and number of transaction

									 //mutator
	void set_interest_rate(double rate_input); //set the interest rate for the account
	void deposit(double deposit_amount); //deposit to bank account, counted as transaction
	void withdraw(double withdraw_amount); //withdraw from account, show an error if withdrawal amount is greater than the balance. counted as transaction 
	void calc_interest(int num_period); //calculate amount of interest after num_period

										//accessor
	std::string get_name() const; //returns the name of the account holder 
	double get_interest_rate() const; //returns the current interest rate
	double get_balance() const; //returns the current balance of the account 
	double get_interest() const; //returns the current interest
	int get_transactions() const; //returns the current transaction number
};

#endif


}

2) class implementation 
{

//class implementation
#include "Account.h"
#include <string>
#include <iostream>

//constructor 
Account::Account() //default constructor if no names are provided, name will be: N/A
{
	name = "N/A";
	balance = 0.0;
	interest_rate = 0.045;
	interest = 0.0;
	transactions = 0;
}

Account::Account(std::string name_input) //constructor, will initialize name, balance, interest rate, interest and number of transaction
{
	name = name_input;
	balance = 0.0;
	interest_rate = 0.045;
	interest = 0.0;
	transactions = 0;
}


//mutator
void Account::set_interest_rate(double rate_input) //set the interest rate for the account
{
	interest_rate = rate_input;
}

void Account::deposit(double deposit_amount) //deposit to bank account, counted as transaction
{
	balance += deposit_amount;
	transactions++;
}

void Account::withdraw(double withdraw_amount) //withdraw from account, show an error if withdrawal amount is greater than the balance. counted as transaction
{
	if (withdraw_amount > balance)
		std::cout << "Insufficient balance, you only have $" << get_balance() << "\n";
	else
	{
		balance -= withdraw_amount;
		transactions++;
	}

}

void Account::calc_interest(int num_period) //calculate amount of interest after num_period
{
	interest = num_period * interest_rate * balance;
	balance += interest;
}

//accessor
std::string Account::get_name() const //returns the name of the account holder 
{
	return name;
}

double Account::get_interest_rate() const //returns the current interest rate
{
	return interest_rate;
}

double Account::get_balance() const //returns the current balance of the account 
{
	return balance;
}

double Account::get_interest() const //returns the current interest
{
	return interest;
}

int Account::get_transactions() const //returns the current transaction number
{
	return transactions;
}

}

3) main function 
{

#include <iostream>
#include "Account.h"

const int NUM = 3;
void display_menu(char &choice);

int main()
{
	Account bank_account("Yu Miao"); //create an account, account name = Yu Miao
	
	char choice; //hold choice of the user
	double deposit_amount; //deposit
	double withdraw_amount; //withdraw
	double rate_input; //interest rate
	int num_period; //used to calculate interest

	do
	{
		display_menu(choice);
		switch (choice)
		{
		case '1':
			std::cout << "What is the deposit amount: ";
			std::cin >> deposit_amount;
			while (deposit_amount < 0)
			{
				std::cout << "Please input deposit amount that is greater than zero: ";
				std::cin >> deposit_amount;
			}
			std::cin.ignore();
			bank_account.deposit(deposit_amount);
			std::cin.get();
			break;
		case '2':
			std::cout << "What is the withdrawal amount: ";
			std::cin >> withdraw_amount;
			while (withdraw_amount < 0)
			{
				std::cout << "Please input withdrawal amount that is greater than zero: ";
				std::cin >> withdraw_amount;
			}
			std::cin.ignore();
			bank_account.withdraw(withdraw_amount);
			std::cin.get();
			break;
		case '3':
			std::cout << "What is the interest rate: ";
			std::cin >> rate_input;
			while (rate_input < 0)
			{
				std::cout << "Please input interest rate that is greater than zero: ";
				std::cin >> rate_input;
			}
			std::cin.ignore();
			bank_account.set_interest_rate(rate_input);
			std::cin.get();
			break;
		case '4':
			std::cout << "What is the number of period: ";
			std::cin >> num_period;
			while (num_period < 0)
			{
				std::cout << "Please input period number that is greater than zero: ";
				std::cin >> num_period;
			}
			std::cin.ignore();
			bank_account.calc_interest(num_period);
			std::cin.get();
			break;
		case '5':
			std::cout << "\nInterest rate: " << bank_account.get_interest_rate() << "\n";
			std::cin.get();
			break;
		case '6':
			std::cout << "\nInterest: $" << bank_account.get_interest() << "\n";
			std::cin.get();
			break;
		case '7':
			std::cout << "\nBalance: $" << bank_account.get_balance() << "\n";
			std::cin.get();
			break;
		case '8':
			std::cout << "\nNumber of transactions: " << bank_account.get_transactions() << "\n";
			std::cin.get();
			break;
		case '9':
			std::cout << "You quited.\n";
			break;
		}
	} while (choice != '9');

	return 0;

}

void display_menu(char &choice)
{
	//print out menu
	std::cout << "Bank account management system\n";
	std::cout << "(please select one term below:\n\n";
	std::cout << "1) Deposit\n"
		<< "2) Withdrawal\n"
		<< "3) Set interest rate\n"
		<< "4) Calculate interest\n"
		<< "5) Display interest rate\n"
		<< "6) Display interest\n"
		<< "7) Display balance\n"
		<< "8) Display transaction number\n"
		<< "9) quit\n";

	//input choice
	std::cin >> choice;
	while (choice < 49 || choice > 57)
	{
		std::cout << "Invalid input, please input again: ";
		std::cin >> choice;
	}

	//skip '\n'
	std::cin.ignore();
}


}

}

16. Case study: dice simulator
{

1) class specification 
{

#ifndef DICE_H
#define DICE_H

#include <cstdlib>
#include <ctime>

class Dice
{
private:
	int sides; //hold the number of sides of the dice object
	int number_rolled; //hold the total number this dice has been rolled

public:
	//constructor
	Dice() //default constructor, will initialize sides with 6
	{
		sides = 6;
		number_rolled = 0;

		//initialize the random number
		int seed;
		seed = time(0);
		srand(seed);
	}
	Dice(int num_sides) //will initiate number of sides
	{
		sides = num_sides;
		number_rolled = 0;

		//initialize the random number
		int seed;
		seed = time(0);
		srand(seed);
	}

	//methods
	int roll(); //roll the dice, will return a random value between 1 to maximum number of sides, number of rolled will be incremented
	int display_rolled() const; //show number of this dice rolled
};

#endif


}

2) class implementation 
{

#include "Dice.h"
#include <cstdlib>

int Dice::roll()
{
	number_rolled++; //update number rolled
	return rand() % (sides)+1; //return random result
}

int Dice::display_rolled() const
{
	return number_rolled;
}

}

3) main function 
{

#include <iostream>
#include "Dice.h"

void display_menu(char &choice);

int main()
{
	Dice dice20(20);
	Dice dice20_2(20);

	for (int i = 0; i < 20; i++)
		std::cout << "Roll-1 " << i + 1 << ": " << dice20.roll() << "\n";
	
	std::cout << "\n";

	for (int i = 0; i < 20; i++)
		std::cout << "Roll-2 " << i + 1 << ": " << dice20_2.roll() << "\n";

	//char choice;

	//do
	//{
	//	display_menu(choice);
	//	switch (choice)
	//	{
	//	case '1':
	//		std::cout << "Rolling: " << dice20.roll() << "\n";
	//		break;
	//	case '2':
	//		std::cout << "Number of rolling: " << dice20.display_rolled() << "\n";
	//		break;
	//	default:
	//		break;
	//	}
	//} while (choice != '3');

	
	return 0;
}

void display_menu(char &choice)
{
	std::cout << "\n1) Roll the dice\n"
		<< "2) Show rolled times\n"
		<< "3) quit\n";

	std::cin >> choice;
	std::cin.ignore();
}

}

}

17. Case study: creating an abstract array data type 
{

1) class specification
{

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
	int get_element(int index); //show the element stored in position index

									  //mutator
	void set_element(int index, int value); //set the element in position index to value provided
};

#endif

}

2) class implementation 
{

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
int Integer_array::get_element(int index) //show the element stored in position index
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




}

3) main function 
{

#include <iostream>
#include "Integer_array.h"

int main()
{
	Integer_array list(5);
	list.set_element(1, 3);
	std::cout << list.get_element(1) << "\n";

	return 0;
}

}

}


/****************************/
/***Programming Challenges***/
/****************************/

1. Date 
{

1) class specification
{

#ifndef DATE_H
#define DATE_H

class Date
{
private:
	char month[3];
	char day[3];
	char year[5];
	void strcpy2(char *destination, const char *source);
	void display_month_name() const;
public:
	/* Constructor */
	Date(); //default constructor, store 05/05/1990	
	Date(char *date_input); //constructor, specify month, day and year 

	/* Member function */
	void display_form1() const; //display 5/5/1990
	void display_form2() const; //display May 5, 1990
	void display_form3() const; //display 5 May 1990
};

#endif

}

2) class implementation 
{

#include <iostream>
#include "Date.h"

/* Private member function */
void Date::strcpy2(char *destination, const char *source)
{
	int i = 0;
	while (source[i] != '\0')
		destination[i] = source[i++];
	destination[i] = '\0';
}

void Date::display_month_name() const
{
	if (month[0] == '1')
	{
		switch (month[1])
		{
		case '0': std::cout << "October"; break;
		case '1': std::cout << "November"; break;
		case '2': std::cout << "December"; break;
		}
	}
	else
	{
		switch (month[1])
		{
		case '1': std::cout << "Janurary"; break;
		case '2': std::cout << "Feburary"; break;
		case '3': std::cout << "March"; break;
		case '4': std::cout << "April"; break;
		case '5': std::cout << "May"; break;
		case '6': std::cout << "June"; break;
		case '7': std::cout << "July"; break;
		case '8': std::cout << "August"; break;
		case '9': std::cout << "September"; break;
		}
	}

}


/* Constructor */
Date::Date() //default constructor, store 05/05/1990	
{
	strcpy2(month, "05");
	strcpy2(day, "05");
	strcpy2(year, "1990");
}

Date::Date(char *date_input) //constructor, specify month, day and year 
{
	month[0] = date_input[0];
	month[1] = date_input[1];
	month[2] = '\0';

	day[0] = date_input[3];
	day[1] = date_input[4];
	day[2] = '\0';

	for (int i = 0; i<5; i++)
		year[i] = date_input[i + 6];
	year[4] = '\0';

}

/* Public member function */
void Date::display_form1() const //display 05/05/1990
{
	std::cout << month << "/" << day << "/" << year;
}

void Date::display_form2() const //display May 5, 1990
{
	display_month_name();
	std::cout << " " << day << ", " << year;
}

void Date::display_form3() const //display 5 May 1990
{
	std::cout << day << " ";
	display_month_name();
	std::cout << " " << year;
}

}

3) main program 
{

#include <iostream>
#include "Date.h"

bool date_check(char *date);

int main()
{
	/* Input date */
	//define container
	char date_input[11]; 
	//input and input validate
	std::cout << "Please input a date in mm/dd/yyyy formate: ";
	std::cin.getline(date_input, 11);
	while (!date_check(date_input))
	{
		std::cout << "Please input a valid date in mm/dd/yyyy formate: ";
		std::cin.getline(date_input, 11);
	}

	/* Create object and print the date in different form */
	Date date(date_input);
	std::cout << "Format 1: ";
	date.display_form1();
	std::cout << "\nFormat 2: ";
	date.display_form2();
	std::cout << "\nFormat 3: ";
	date.display_form3();
	std::cout << "\n";

	return 0;

	
}

bool date_check(char *date)
{
	/* Check if the date array has 10 characters */
	if (strlen(date) != 10)
		return 0;

	/* Check if the third, sixth element is '/' */
	if (date[2] != '/' && date[5] != '/')
		return 0;

	/* Extract month, days and years */
	char month_ch[2] = { date[0], date[1] };
	char day_ch[2] = { date[3], date[4] };
	char year_ch[4] = { date[6], date[7], date[8], date[9] };
	int month = atoi(month_ch);
	int day = atoi(day_ch);
	int year = atoi(year_ch);

	/*
	Check month, day and year:
	1) check month: within 1~12;
	2) month 1, 3, 5, 7, 8, 10, 12 should have days between 1~31;
	3) month 4, 6, 9, 11 should have days between 1~30;
	4) month 2: check year. If its a leap year, day should between 1~29, otherwise 1~28;
	*/
	if (month > 12 || month < 1)
		return 0;

	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day < 1 || day > 31)
			return 0;
		else
			return 1;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day < 1 || day > 30)
			return 0;
		else
			return 1;
		break;
	case 2:
		//check the year is leap year or not
		bool leap_year; //hold wether the year is leap year
		if (year % 4 != 0)
			leap_year = false;
		else if (year % 100 != 0)
			leap_year = true;
		else if (year % 400 != 0)
			leap_year = false;
		else
			leap_year = true;

		//check number of days in Feburary
		if (leap_year)
		{
			if (day < 1 || day > 29)
				return 0;
		}

		else
			if (day < 1 || day > 28)
				return 0;

		return 1;
	}


}



}

4) bug
{

>1 forgot to add a '\0' at the end of a C-string

}

}

2. Employee class
{

1) class specification 
{

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
private:
	std::string name; //store the name of the employee
	int id_num; //store employee's id number 
	std::string department; //store department info for the employee
	std::string position; //store the job title of the employee
public:
	/* Constructor */
	//default constructor 
	Employee();
	//constructor 1 (name, id)
	Employee(std::string name_input, int id_input);
	//constructor 2 (name, id, department, position)
	Employee(std::string name_input, int id_input, std::string department_input, std::string position_input);

	/* Member function */
	//mutator
	void set_name(std::string name_input)
	{
		name = name_input;
	}
	void set_id_num(int id_input)
	{
		id_num = id_input;
	}
	void set_department(std::string department_input)
	{
		department = department_input;
	}
	void set_position(std::string position_input)
	{
		position = position_input;
	}
	//accessor
	std::string get_name() const
	{
		return name;
	}
	int get_id() const
	{
		return id_num;
	}
	std::string get_department() const
	{
		return department;
	}
	std::string get_position() const
	{
		return position;
	}
};

#endif

}

2) class implementation 
{

#include "Employee.h"
#include <string>

/* Constructor */
//default constructor 
Employee::Employee()
{
	name = "";
	id_num = 0;
	department = "";
	position = "";
}
//constructor 1 (name, id)
Employee::Employee(std::string name_input, int id_input)
{
	name = name_input;
	id_num = id_input;
	department = "";
	position = "";
}
//constructor 2 (name, id, department, position)
Employee::Employee(std::string name_input, int id_input, std::string department_input, std::string position_input)
{
	name = name_input;
	id_num = id_input;
	department = department_input;
	position = position_input;
}

}

3) main function 
{

#include "Employee.h"
#include <iostream>

int main()
{
	Employee employee[3] = { Employee("Susan Meyers", 47899, "Accounting", "Vice President"), Employee("Mark Jones", 39119, "IT", "Programmer"), Employee("Joy Rogers", 81774, "Manufacturing", "Engineer") };

	for (int i = 0; i<3; i++)
	{
		std::cout << "Record " << i + 1 << ": \n"
			<< "Name: " << employee[i].get_name() << "\n"
			<< "ID number: " << employee[i].get_id() << "\n"
			<< "Department: " << employee[i].get_department() << "\n"
			<< "Position: " << employee[i].get_position() << "\n\n";
	}

	return 0;
}

}

}

3. Car class 
{

1) class specification
{

#ifndef CAR_H
#define CAR_H

#include <string>

class Car
{
private:
	int year_model;
	std::string make;
	int speed;

public:
	/* Constructor */
	Car(int year_model_input, std::string make_input)
	{
		year_model = year_model_input;
		make = make_input;
		speed = 0;
	}

	/* Accessor */
	int get_year_model() const
	{
		return year_model;
	}
	std::string get_make() const
	{
		return make;
	}
	int get_speed() const
	{
		return speed;
	}

	/* Mutator */
	void accelerate()
	{
		speed += 5;
	}
	void brake()
	{
		speed -= 5;
	}
};

#endif


}

2) main program
{

#include <iostream>
#include "Car.h"

int main()
{
	Car my_car(2010, "Accord");

	for (int i = 0; i<5; i++)
	{
		my_car.accelerate();
		std::cout << "Accelerated, current speed: " << my_car.get_speed() << "\n";
	}

	for (int i = 0; i<5; i++)
	{
		my_car.brake();
		std::cout << "Braked, current speed: " << my_car.get_speed() << "\n";
	}

	return 0;
}

}

}

4. Personal information class 
{

1) class specification
{

#ifndef PERSONAL_H
#define PERSONAL_H

class Personal
{
private:
	char *name;
	char *address;
	char *age;
	char *phone;
	void strcpy2(char *destination, const char *source);
public:
	Personal();
	Personal(char *name_input, char *address_input, char *age_input, char *phone_input);
	~Personal();

	/* Mutator */
	void set_name(char *name_input);
	void set_address(char *address_input);
	void set_age(char *age_input);
	void set_phone(char *phone_input);

	/* Accessor */
	const char *get_name() const
	{
		return name;
	}
	const char *get_address() const
	{
		return address;
	}
	const char *get_age() const
	{
		return age;
	}
	const char *get_phone() const
	{
		return phone;
	}
};

#endif

}

2) class implementation
{

#include "Personal.h"
#include <cstring>

void Personal::strcpy2(char *destination, const char *source)
{
	int i = 0;
	while (source[i] != '\0')
		destination[i] = source[i++];
	destination[i] = '\0';
}

/* Constructor */
//default constructor
Personal::Personal()
{
	name = new char[4];
	address = new char[4];
	age = new char[4];
	phone = new char[4];

	strcpy2(name, "N/A");
	strcpy2(address, "N/A");
	strcpy2(age, "N/A");
	strcpy2(phone, "N/A");
}

Personal::Personal(char *name_input, char *address_input, char *age_input, char *phone_input)
{
	name = new char[strlen(name_input) + 1];
	address = new char[strlen(address_input) + 1];
	age = new char[strlen(age_input) + 1];
	phone = new char[strlen(phone_input) + 1];

	strcpy2(name, name_input);
	strcpy2(address, address_input);
	strcpy2(age, age_input);
	strcpy2(phone, phone_input);
}

Personal::~Personal()
{
	delete[] name;
	delete[] address;
	delete[] age;
	delete[] phone;
}

/* Mutator */
void Personal::set_name(char *name_input)
{
	delete[] name;
	name = new char[strlen(name_input) + 1];
	strcpy2(name, name_input);
}

void Personal::set_address(char *address_input)
{
	delete[] address;
	address = new char[strlen(address_input) + 1];
	strcpy2(address, address_input);
}

void Personal::set_age(char *age_input)
{
	delete[] age;
	age = new char[strlen(age_input) + 1];
	strcpy2(age, age_input);
}

void Personal::set_phone(char *phone_input)
{
	delete[] phone;
	phone = new char[strlen(phone_input) + 1];
	strcpy2(phone, phone_input);
}

}

3) main program 
{

#include <iostream>
#include "Personal.h"

int main()
{
	Personal contact[3] = { Personal("Yu Miao", "1839 Portland Ave", "27", "850-524-5269"), Personal("Yingying Cheng", "1839 Portland Ave", "27", "15928831762"), Personal("Wenhao Cheng", "1722 Yee tree road", "25", "8509230123") };

	contact[2].set_name("Stum Brightblade");

	for (int i = 0; i<3; i++)
	{
		std::cout << "Contact " << i + 1 << "\n";
		std::cout << "Name: " << contact[i].get_name() << "\n"
			<< "Address: " << contact[i].get_address() << "\n"
			<< "Age: " << contact[i].get_age() << "\n"
			<< "Phone: " << contact[i].get_phone() << "\n\n";
	}

	return 0;
}

}

}

5. Retail_item class 
{

1) class specification 
{

#ifndef RETAIL_ITEM_H
#define RETAIL_ITEM_H

#include <string>

class Retail_item
{
private:
	std::string description;
	int stock;
	double price;

public:
	/* Constructor */
	//default constructor
	Retail_item()
	{
		description = "N/A";
		stock = 0;
		price = 0.0;
	}
	//constructor 
	Retail_item(std::string description_input, int stock_input, double price_input)
	{
		description = description_input;
		stock = stock_input;
		price = price_input;
	}

	/* Mutator */
	void set_description(std::string description_input);
	void set_stock(int stock);
	void set_price(double price_input);

	/* Accessor */
	std::string get_description() const
	{
		return description;
	}
	int get_stock() const
	{
		return stock;
	}
	double get_price() const
	{
		return price;
	}
};

#endif


}

2) class implementation 
{

#include "Retail_item.h"

void Retail_item::set_description(std::string description_input)
{
	description = description_input;
}

void Retail_item::set_stock(int stock_input)
{
	stock = stock_input;
}

void Retail_item::set_price(double price_input)
{
	price = price_input;
}

}

3) main program 
{

#include <iostream>
#include "Retail_item.h"

int main()
{
	Retail_item inventory[3] = { Retail_item("Jacket", 12, 59.95), Retail_item("Designer Jeans", 40, 34.95), Retail_item("Shirt", 20, 24.95) };

	for (int i = 0; i<3; i++)
	{
		std::cout << "Item #" << i + 1 << "\n"
			<< "Description: " << inventory[i].get_description() << "\n"
			<< "Stock: " << inventory[i].get_stock() << "\n"
			<< "Price: $" << inventory[i].get_price() << "\n\n";
	}

	return 0;
}

}

}

6. Inventory class 
{

1) class specification
{

#ifndef INVENTORY_H
#define INVENTORY_H

#include <cstdlib> //for exit(EXIT_FAILURE) function
#include <iostream>

class Inventory
{
private:
	int item_number;
	int stock;
	double cost_unit;
	double cost_total;

public:
	Inventory()
	{
		item_number = 0;
		stock = 0;
		cost_unit = 0;
		cost_total = 0;
	}

	Inventory(int item_number_input, int stock_input, double cost_unit_input)
	{
		if (item_number_input <= 0 || stock_input < 0 || cost_unit_input <0)
		{
			std::cout << "Invalid input...quitting...\n";
			exit(EXIT_FAILURE);
		}

		else
		{
			item_number = item_number_input;
			stock = stock_input;
			cost_unit = cost_unit_input;

			set_total_cost();
		}

	}

	/* Mutator */
	void set_item_number(int item_number_input)
	{
		if (item_number_input < 0)
		{
			std::cout << "Invalid input...quitting...\n";
			exit(EXIT_FAILURE);
		}

		item_number = item_number_input;
	}

	void set_stock(int stock_input)
	{
		if (stock_input < 0)
		{
			std::cout << "Invalid input...quitting...\n";
			exit(EXIT_FAILURE);
		}

		stock = stock_input;
	}

	void set_cost(double cost_unit_input)
	{
		if (cost_unit_input < 0)
		{
			std::cout << "Invalid input...quitting...\n";
			exit(EXIT_FAILURE);
		}

		cost_unit = cost_unit_input;
	}

	void set_total_cost()
	{
		cost_total = stock * cost_unit;
	}

	/* Accessor */
	int get_item_number() const
	{
		return item_number;
	}
	int get_stock() const
	{
		return stock;
	}
	double get_cost_unit() const
	{
		return cost_unit;
	}
	double get_cost_total() const
	{
		return cost_total;
	}

};

#endif


}

2) main program 
{

#include <iostream>
#include "Inventory.h"

int main()
{
	
	Inventory ruler(12203, 5, 4.5);

	ruler.set_cost(10);
	ruler.set_total_cost();
	std::cout << ruler.get_cost_total() << "\n";
	return 0;
}

}

}

7. Test_score class 
{

1) class specification
{

#ifndef SCORE_H
#define SCORE_H

class Score
{
private:
	double score1;
	double score2;
	double score3;

public:
	Score(); //default constructor, assign score to 0.0
	Score(double s1, double s2, double s3); //constructor-1, assign score to three score variable；


	/* Mutator */
	void set_score1(double s1)
	{
		score1 = s1;
	}
	void set_score2(double s2)
	{
		score2 = s2;
	}
	void set_score3(double s3)
	{
		score3 = s3;
	}
	
	/* Accessor */
	double get_score1() const
	{
		return score1;
	}
	double get_score2() const 
	{
		return score2;
	}
	double get_score3() const 
	{
		return score3;
	}	
	double get_average() const 
	{
		return (score1+score2+score3)/3;
	}
	
};

#endif

}

2) class implementation
{

#include "Score.h"

Score::Score() //default constructor, assign score to 0.0
{
	score1 = 0.0;
	score2 = 0.0;
	score3 = 0.0;
}
Score::Score(double s1, double s2, double s3) //constructor-1, assign score to three score variable
{
	score1 = s1;
	score2 = s2;
	score3 = s3;
}


}

3) main function 
{

#include <iostream>
#include "Score.h"

int main()
{
	Score Yu(99.9, 98.5, 100);
	std::cout << "Average score is: " << Yu.get_average() << "\n";

	return 0;
}

}

}

8. Circle class 
{

1) class specification
{

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
private:
	double radius;
	const double PI = 3.1415926;
public:
	/* Constructor */
	Circle(); //default constructor, assign radius to zero
	Circle(double r); //constructor, assign radius with r
	
	/* Mutator */
	void set_radius(double r); //assign radius with r
	
	/* Accessor */
	double get_radius() const; //return radius 
	double get_area() const; //return area
	double get_diameter() const; //return diameter
	double get_circumference() const; //return circumference
};

#endif



}

2) class implementation
{

#include "Circle.h"

/* Constructor */
Circle::Circle() //default constructor, assign radius to zero
{
	radius = 0;
}

Circle::Circle(double r) //constructor, assign radius with r
{
	radius = r;
}

/* Mutator */
void Circle::set_radius(double r) //assign radius with r
{
	radius = r;
}

/* Accessor */
double Circle::get_radius() const //return radius 
{
	return radius;
}
double Circle::get_area() const //return area
{
	return PI*radius*radius;
}
double Circle::get_diameter() const //return diameter
{
	return 2 * radius;
}
double Circle::get_circumference() const //return circumference
{
	return 2 * PI*radius;
}


}

3) main function 
{

#include <iostream>
#include "Circle.h"

int main()
{
	Circle sun(1);
	std::cout << "Area is: " << sun.get_area() << "\n";
	return 0;
}

}

}

9. Population class 
{

1) class specification 
{

#ifndef POPULATION_H
#define POPULATION_H

class Population
{
private:
	int population;
	int birth;
	int death;

public:
	Population(int p, int b, int d)
	{
		population = p;
		birth = b;
		death = d;
	}

	double get_birth_rate() const
	{
		return static_cast<double>(birth) / population;
	}

	double get_death_rate() const
	{
		return static_cast<double>(death) / population;
	}
};

#endif



}

2) main program 
{

#include "Population.h"
#include <iostream>

int main()
{
	Population luzhou(10000, 500, 400);
	std::cout << "Birth rate: " << luzhou.get_birth_rate() << "\n";
	std::cout << "Death rate: " << luzhou.get_death_rate() << "\n";

	return 0;
}

}

}

10. Number array class 
{

1) class specification
{

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


}

2) class implementation 
{

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



}

3) main program 
{

#include <iostream>
#include "Number.h"

int main()
{
	Number array(5);

	for (int i = 0; i<5; i++)
		array.set_value(i, i);

	std::cout << "Highest value: " << array.get_value(array.get_highest()) << "\n";
	std::cout << "Lowest value: " << array.get_value(array.get_lowest()) << "\n";
	std::cout << "Average: " << array.get_average() << "\n";

	return 0;
}

}

4) debug
{

My definition of constructor was like this:

Number::Number(int size_input)
	num = new double[size];
	size = size_input;

I changed the name of argument, but forget to change in the following line, that is why I got an error. Fix:
num = new double[size_input];

}

}

11. Payroll
{

1) class specification
{

#ifndef PAYROLL_H
#define PAYROLL_H

class Payroll
{
private:
	double pay_rate;
	int hour;
	double total_pay;
public:
	/* Constructor */
	Payroll()
	{
		pay_rate = 55;
	}
	
	/* Mutator */
	void set_hour(int hour_input); //set work hour and calculate total pay, store to total_pay
	
	/* Accessor */
	double get_total_pay() const;
};

#endif



}

2) class implementation 
{

#include "Payroll.h"
#include <cstdlib>
#include <iostream>

/* Mutator */
void Payroll::set_hour(int hour_input) //set work hour and calculate total pay, store to total_pay
{
	if (hour_input < 0)
	{
		std::cout << "Invalid input, program quitting...\n";
		exit(EXIT_FAILURE);
	}
	
	hour = hour_input;
	total_pay = hour * pay_rate;
}

/* Accessor */
double Payroll::get_total_pay() const
{
	return total_pay;
}


}

3) main function 
{

#include <iostream>
#include "Payroll.h"

const int NUM = 7;

int main()
{
	Payroll gross_pay[NUM];
	int hour_input;

	for (int i = 0; i<NUM; i++)
	{
		std::cout << "Please input the working hour for employee " << i + 1 << ": ";
		std::cin >> hour_input;
		gross_pay[i].set_hour(hour_input);
	}

	std::cout << "The gross pay is as follows:\n";

	for (int i = 0; i<NUM; i++)
	{
		std::cout << "Employee " << i + 1 << ": $" << gross_pay[i].get_total_pay() << "\n";
	}

	return 0;
}

}

}

12. Coin toss similator
{

1) class specification 
{

#ifndef COIN_H
#define COIN_H

#include <string>
#include <cstdlib>
#include <ctime>

const int N_max = 2, N_min = 1;

class Coin
{
private:
	std::string sideup; //hold either "heads" or "tails", result of tossing
public:
	/* Constructor */
	Coin() //seed random generator, create a result for the side of the coin 
	{
		int result;
		int seed = time(0);
		srand(seed);
		
		result = rand() % (N_max + N_min - 1) + N_min;
		
		switch (result)
		{
		case 1:
			sideup = "heads"; break;
		case 2:
			sideup = "tails"; break;
		}
	}
	
	/* Mutator */
	void toss(); //toss coin, get a random number between 1 and 2, save result to sideup: 1-heads, 2-tails
	
	/* Accessor */
	std::string get_sideup() const; //check result of the side 
	
};

#endif

}

2) class implementation 
{

#include "Coin.h"
#include <cstdlib>

/* Mutator */
void Coin::toss() //toss coin, get a random number between 1 and 2, save result to sideup: 1-heads, 2-tails
{

	int result;
	result = rand() % (N_max + N_min - 1) + N_min;

	switch (result)
	{
	case 1:
		sideup = "heads"; break;
	case 2:
		sideup = "tails"; break;
	}

}

/* Accessor */
std::string Coin::get_sideup() const //check result of the side 
{
	return sideup;
}


}

3) main program 
{

#include <iostream>
#include "Coin.h"

int main()
{
	Coin coin;

	std::cout << "Initial side: " << coin.get_sideup() << "\n";

	std::cout << "Tossing 20 times...\n";
	for (int i = 0; i<20; i++)
	{
		coin.toss();
		std::cout << i + 1 << ": " << coin.get_sideup() << "\n";
	}

	return 0;
}

}

}

13. Tossing coins for a dollar
{

Code (not including the class specification and implementation)
{

#include <iostream>
#include "Coin.h"

int main()
{
	Coin quarter; //25 cents coin
	Coin dime; //10 cents coin 
	Coin nickel; //5 cents coin 
	
	int balance = 0; //starting balance is 0
	
	//show welcome information
	std::cout << "Your initial balance is: " << balance << " cents, press enter to begin game.";
	std::cin.get();
	
	//game round 
	do
	{
		//round begin, tossing three coins
		quarter.toss();
		dime.toss();
		nickel.toss();
		
		//display result
		std::cout << "Tossing result:\n"
		<< "Quarter: " << quarter.get_sideup() << std::endl
		<< "Dime: " << dime.get_sideup() << std::endl
		<< "Nickel: " << nickel.get_sideup() << "\n\n";
		
		//update balance, if it's heads, add value to balance 
		if (quarter.get_sideup() == "heads")
			balance += 25;
		if (dime.get_sideup() == "heads")
			balance += 10;
		if (nickel.get_sideup() == "heads")
			balance += 5;
		
		//show result of this round, and press enter to continue
		if (balance < 100)
		{
			std::cout << "Balance after first round: " << balance << " cents, press enter to begin next round.\n";
			std::cin.get();			
		}
		
	} while (balance < 100);

	//show result 
	std::cout << "Your balance is: " << balance << " cents. ";	
	if (balance == 100)
		std::cout << "You win!\n";
	else 
		std::cout << "You lose!\n";
	
	return 0;
}

}

Code (calculate how many rounds can win)
{

#include <iostream>
#include "Coin.h"

int main()
{
	Coin quarter; //25 cents coin
	Coin dime; //10 cents coin 
	Coin nickel; //5 cents coin 
	
	int balance = 0; //starting balance is 0
	
	//show welcome information
	std::cout << "Your initial balance is: " << balance << " cents, press enter to begin game.";
	std::cin.get();
	
	//game round
	int round_num = 0;
	do
	{
		balance = 0; //to re-initialize balance value 
		do
		{
			//round begin, tossing three coins
			quarter.toss();
			dime.toss();
			nickel.toss();
			
			//display result
			std::cout << "Tossing result:\n"
			<< "Quarter: " << quarter.get_sideup() << std::endl
			<< "Dime: " << dime.get_sideup() << std::endl
			<< "Nickel: " << nickel.get_sideup() << "\n\n";
			
			//update balance, if it's heads, add value to balance 
			if (quarter.get_sideup() == "heads")
				balance += 25;
			if (dime.get_sideup() == "heads")
				balance += 10;
			if (nickel.get_sideup() == "heads")
				balance += 5;
			
			//show result of this round, and press enter to continue
			if (balance < 100)
			{
				std::cout << "Balance after first round: " << balance << " cents\n\n";	
			}
			
		} while (balance < 100);
		
		if (balance != 100)
			round_num++; //game loss, update round number and start over again
	} while (balance != 100);
	
	round_num++; //update for the last round (balance == 100)

	//show result
	std::cout << "Balance is " << balance << " cents. ";
	std::cout << "You played " << round_num << " rounds of games to win.\n";
	
	return 0;
}

}

}

14. Fishing game simulation
{

Code
{

#include "Dice.h"
#include <iostream>
#include <vector>
#include <string>

std::string show_item(int dice_value);
std::string show_score(int dice_value, int &score);
int item_size(int dice_value, int &bag_capacity);


int main()
{
	Dice dice(13);
	std::vector<int> inventory; //to hold the things user has got from fishing
	int score = 0; //hold the final score for the user
	char choice; //hold user's choice if he wants to fish or not
	int bag_content = 0; //hold current content held in user's inventory 
	int rolled; //hold the result of rolling a dice
	int bag_capacity = 16; //hold the bag space, can be expanded by getting a small pouch
	
	/* First fishing */
	//begin roll and show result
	std::cout << "Press enter to begin your first fishing.";
	std::cin.get();
	rolled = dice.roll();
	std::cout << "You got: [" << show_item(rolled) << "], score " << show_score(rolled, score) << ". ";
	//update inventory, bag capacity
	inventory.push_back(rolled); //update inventory
	bag_content += item_size(rolled, bag_capacity); //update bag capacity
	//display current score and bag capacity
	std::cout << "Current score: " << score << ". Bag: " << bag_content << "/" << bag_capacity << "\n";
	
	/* Entering loop, continue until user chose to exit or inventory is full */
	do
	{
		/* Ask user to quit or continue */
		std::cout << "\nPress N to quit, press other keys to fishing again...";
		std::cin >> choice;
		std::cin.ignore();
		
		if (choice == 'N' || choice == 'n')
			break;
		
		/* Continue fishing */
		rolled = dice.roll();
		std::cout << "You got: [" << show_item(rolled) << "], score " << show_score(rolled, score) << ". ";
		//update inventory, bag capacity
		inventory.push_back(rolled); //update inventory
		bag_content += item_size(rolled, bag_capacity); //update bag capacity
		//display current score and bag capacity
		std::cout << "Current score: " << score << ". Bag: " << bag_content << "/" << bag_capacity << "\n";		
		
	} while (bag_content <= bag_capacity);
	
	//show quit info
	if (choice == 'N' || choice == 'n')
		std::cout << "You quitted.\n";
	else 
		std::cout << "Inventory is full.\n";
	
	
	/* Print out the record */
	std::cout << "You got:\n";
	for (int i=0; i<inventory.size(); i++)
		std::cout << "[" << show_item(inventory[i]) << "]\n";
	std::cout << "\nTotal score: " << score << "\n";
	
	return 0;
	
}

//show the description of the item
std::string show_item(int dice_value)
{
	switch (dice_value)
	{
	case 1:
	case 2:
	case 3:
		return "small fish";
	case 4:
	case 5:
		return "medium fish";
	case 6:
		return "large fish";
	case 7:
		return "old shoe";
	case 8:
		return "water grass";
	case 9:
		return "tire piece";
	case 10:
		return "stink worm";
	case 11:
		return "rotten meat";
	case 12:
		return "twisted bolt";
	case 13:
		return "small blue pouch";
	}
}

//show the details of score value for different item, and update score 
std::string show_score(int dice_value, int &score)
{
	switch (dice_value)
	{
	case 1:
	case 2:
	case 3:
		score += 1;
		return "+1";
	case 4:
	case 5:
		score += 3;
		return "+3";
	case 6:
		score += 6;
		return "+6";
	case 7:
		return "+0";
	case 8:
		return "+0";
	case 9:
		return "+0";
	case 10:
		score -= 1;
		return "-1";
	case 11:
		score -= 3;
		return "-3";
	case 12:
		return "+0";
	case 13:
		return "+0";
	}
}

int item_size(int dice_value, int &bag_capacity)
{
	switch (dice_value)
	{
	case 1:
	case 2:
	case 3:
		return 1;
	case 4:
	case 5:
		return 2;
	case 6:
		return 3;
	case 7:
		return 2;
	case 8:
		return 1;
	case 9:
		return 5;
	case 10:
		return 1;
	case 11:
		return 2;
	case 12:
		return 1;
	case 13:
		bag_capacity += 5;
		return 0;
	}
}


}

Dice class specification
{

#ifndef DICE_H
#define DICE_H

#include <cstdlib>
#include <ctime>

class Dice
{
private:
	int sides; //hold the number of sides of the dice object
	int number_rolled; //hold the number this dice has been rolled

public:
	//constructor
	Dice() //default constructor, will initialize sides with 6
	{
		sides = 6;
		number_rolled = 0;

		//initialize the random number
		int seed;
		seed = time(0);
		srand(seed);
	}
	Dice(int num_sides) //will initiate number of sides
	{
		sides = num_sides;
		number_rolled = 0;

		//initialize the random number
		int seed;
		seed = time(0);
		srand(seed);
	}

	//methods
	int roll(); //roll the dice, will return a random value between 1 to maximum number of sides, number of rolled will be incremented
	int display_rolled() const; //show number of this dice rolled
};

#endif


}

Dice class implementation 
{

#include "Dice.h"
#include <cstdlib>

int Dice::roll()
{
	number_rolled++; //update number rolled
	return rand() % (sides)+1; //return random result
}

int Dice::display_rolled() const
{
	return number_rolled;
}

}

}

15. Mortgage payment
{

1) class specification
{

#ifndef MORTGAGE_H
#define MORTGAGE_H


class Mortgage
{
private:
	double loan;
	double rate;
	int year;
public:
	/* Constructor */
	Mortgage(); //to initialize loan, rate and year to zero
	
	/* Mutator */
	void set_loan(double loan_input);
	void set_rate(double rate_input);
	void set_year(int year_input);
	
	/* Accessor */
	double get_payment() const;
	double get_total_payment() const;
};

#endif

}

2) class implementation 
{

#include "Mortgage.h"
#include <cmath>

/* Constructor */
Mortgage::Mortgage() //to initialize loan, rate and year to zero
{
	loan = 0.0;
	rate = 0.0;
	year = 0;
}

/* Mutator */
void Mortgage::set_loan(double loan_input)
{
	loan = loan_input;
}
void Mortgage::set_rate(double rate_input)
{
	rate = rate_input;
}
void Mortgage::set_year(int year_input)
{
	year = year_input;
}

/* Accessor */
double Mortgage::get_payment() const
{
	double term;
	term = pow(1 + rate / 12, 12 * year);

	return (loan*rate*term / (12 * (term - 1)));
}

double Mortgage::get_total_payment() const
{
	return 12 * year*get_payment();
}


}

3) main program 
{

#include <iostream>
#include "Mortgage.h"

int main()
{
	Mortgage miao;
	miao.set_loan(50000);
	miao.set_rate(0.05);
	miao.set_year(1);

	std::cout << "Monthly payment: $" << miao.get_payment() << "\n";
	std::cout << "Total payment: $" << miao.get_total_payment() << "\n";

	return 0;
}

}

}

16. Freezing and boiling points
{

1) class specification 
{

#ifndef TEMPERATURE_CHECK_H
#define TEMPERATURE_CHECK_H

class Temperature_check
{
private:
	int temperature;
	const int freeze_ethanol = -173;
	const int freeze_oxygen = -362;
	const int freeze_water = 32;
	const int boil_ethanol = 172;
	const int boil_oxygen = -306;
	const int boil_water = 212;
public:
	/* Constructor */
	Temperature_check()
	{
		temperature = 0;
	}

	/* Mutator */
	void set_temperature(int t)
	{
		temperature = t;
	}

	/* Accessor */
	int get_temperature() const
	{
		return temperature;
	}
	bool is_ethanol_freezing() const;
	bool is_oxygen_freezing() const;
	bool is_water_freezing() const;
	bool is_ethanol_boiling() const;
	bool is_oxygen_boiling() const;
	bool is_water_boiling() const;

};

#endif

}

2) class implementation 
{

#include "Temperature_check.h"

bool Temperature_check::is_ethanol_freezing() const
{
	if (temperature <= freeze_ethanol)
		return true;
	else
		return false;
}
bool Temperature_check::is_oxygen_freezing() const
{
	if (temperature <= freeze_oxygen)
		return true;
	else
		return false;
}
bool Temperature_check::is_water_freezing() const
{
	if (temperature <= freeze_water)
		return true;
	else
		return false;
}
bool Temperature_check::is_ethanol_boiling() const
{
	if (temperature >= boil_ethanol)
		return true;
	else
		return false;
}
bool Temperature_check::is_oxygen_boiling() const
{
	if (temperature >= boil_oxygen)
		return true;
	else
		return false;
}
bool Temperature_check::is_water_boiling() const
{
	if (temperature >= boil_water)
		return true;
	else
		return false;
}

}

3) main program 
{

#include <iostream>
#include "Temperature_check.h"

int main()
{
	Temperature_check temperature;

	temperature.set_temperature(-120);

	if (temperature.is_ethanol_boiling())
		std::cout << "Ethanol is boiling.\n";
	if (temperature.is_oxygen_boiling())
		std::cout << "Oxygen is boiling.\n";
	if (temperature.is_water_boiling())
		std::cout << "Water is boiling.\n";
	if (temperature.is_ethanol_freezing())
		std::cout << "Ethanol is freezing.\n";
	if (temperature.is_oxygen_freezing())
		std::cout << "Oxygen is freezing.\n";
	if (temperature.is_water_freezing())
		std::cout << "Water is freezing.\n";

	return 0;
}

}

}

17. Cash register 
{

1) class specification 
{

> Cash_register class
{

#ifndef CASH_REGISTER_H
#define CASH_REGISTER_H

#include <string>
#include "Inventory_item.h"

class Cash_register
{
private:
	double cost; //cost of the item, read from corresponding inventory_item object
	double profit_rate; //default 30%, initialized in constructor
	double tax_rate; //default 6%, sales tax rate
	int quantity; //amount of purchase
	std::string item_name; //hold name of the item, used as keyword to search in inventory list
	
public:
	/* Constructor */
	Cash_register(); //default constructor, set profit rate to 0.3, tax rate to 0.06
	
	/* Mutator */
	void set_tax_rate(double rate); //set tax rate 
	void set_profit_rate(double rate); //set profit rate 
	void input_purchase_info(); //ask user to input purchase information, including quantity and item name
	void set_cost(Inventory_item *ptr, int size); //set cost of the item, it is read from inventory list 
	void Cash_register::set_cost(double num); //reset cost of the item, only called after sales info displayed

	/* Accessor */
	void display_sales_detail() const; //display subtotal, tax and total on screen
};

#endif

}

> Inventory_item class 
{

#ifndef INVENTORY_ITEM_H
#define INVENTORY_ITEM_H

#include <string>

class Inventory_item
{
private:
	std::string description; //the item description
	double cost; //the item's cost 
	int stock; //the number of stock 
public:
	/* Overload constructor */
	//constructor 1
	Inventory_item()
	{
		description = "";
		cost = 0;
		stock = 0;
	}
	//constructor 2
	Inventory_item(std::string str)
	{
		description = str;
		cost = 0;
		stock = 0;
	}
	//constructor 3
	Inventory_item(std::string str, double cost_input)
	{
		description = str;
		cost = cost_input;
		stock = 0;
	}
	//constructor 4
	Inventory_item(std::string str, double cost_input, int stock_input)
	{
		description = str;
		cost = cost_input;
		stock = stock_input;
	}

	/* Mutator function */
	//set description 
	void set_description(std::string str)
	{
		description = str;
	}
	//set price
	void set_cost(double cost_input)
	{
		cost = cost_input;
	}
	//set stock number 
	void set_stock(int stock_input)
	{
		stock = stock_input;
	}

	/* Accessor function */
	//get description
	std::string get_description() const
	{
		return description;
	}
	//get cost 
	double get_cost() const
	{
		return cost;
	}
	//get stock 
	int get_stock() const
	{
		return stock;
	}

};

#endif




}

}

2) class implementation 
{

> Cash_register class 
{

#include "Cash_register.h"
#include "Inventory_item.h"

#include <string>
#include <iostream>

/* Constructor */
Cash_register::Cash_register() //default constructor, set profit rate to 0.3, tax rate to 0.06
{
	profit_rate = 0.3;
	tax_rate = 0.06;
	cost = 0.0;
	quantity = 0;
	item_name = "N/A";
}

/* Mutator */
void Cash_register::set_tax_rate(double rate) //set tax rate 
{
	tax_rate = rate;
}
void Cash_register::set_profit_rate(double rate) //set profit rate 
{
	profit_rate = rate;
}
void Cash_register::input_purchase_info() //ask user to input purchase information, including quantity and item name
{
	std::cout << "Input item name of your purchase: ";
	getline(std::cin, item_name);
	std::cout << "How many you want to purchase: ";
	std::cin >> quantity;
	while (quantity <= 0)
	{
		std::cout << "Please input a value greater than zero: ";
		std::cin >> quantity;
	}
	std::cin.ignore();
}
void Cash_register::set_cost(Inventory_item *ptr, int size) //set cost of the item, it is read from inventory list 
{
	//find out the matched item in inventory data base
	bool found = false;
	int i;
	for (i = 0; i<size; i++)
		if (item_name == ptr[i].get_description())
		{
			found = true;
			break;
		}

	if (found && (quantity <= ptr[i].get_stock())) //if record is found, and quantity is less than stock, set cost
	{
		cost = ptr[i].get_cost();
		ptr[i].set_stock(ptr[i].get_stock() - quantity); //update stock number
	}
	else if (found) //quantity is larger than stock 
	{
		std::cout << "Purchase failed. There is only " << ptr[i].get_stock() << " item in stock.\n";
	}
	else if (!found) //item not found
	{
		std::cout << "Purchase failed. Item not found!\n";
	}

}

void Cash_register::set_cost(double num) //set cost back to zero after one purchase
{
	cost = 0.0;
}
/* Accessor */
void Cash_register::display_sales_detail() const //display subtotal, tax and total on screen
{
	if (cost != 0.0)
	{
		std::cout << "Purchase details:\n"
			<< "Unit price: $" << cost * (1 + profit_rate) << "\n"
			<< "Subtotal: $" << cost * (1 + profit_rate) * quantity << "\n"
			<< "Tax: $" << cost * (1 + profit_rate) * quantity * tax_rate << "\n"
			<< "Total: $" << (1 + tax_rate) * (cost * (1 + profit_rate) * quantity) << "\n";

	}
}

}

> Inventory_item class 
{

None, all included in class specification file 

}

} 

3) main function 
{

#include <iostream>
#include "Cash_register.h"
#include "Inventory_item.h"
#include <string>

int main()
{
	/* Define an array of inventory item object */
	Inventory_item shop[5] = { Inventory_item("A", 25.5, 5), Inventory_item("B", 16.3, 4), Inventory_item("C", 27.3, 10), Inventory_item("D", 11.2, 12), Inventory_item("E", 5.7, 55) };

	/* Define a cash_register */
	Cash_register cashier;
	char choice; //hold user's choice: continue or not
	do
	{
		/* Purchase */
		cashier.input_purchase_info(); //input purchase info
		cashier.set_cost(shop, 5); //search for item, set cost
		cashier.display_sales_detail(); //display purchase detail
		cashier.set_cost(0.0); //reset cost to zero, marks new round

		/* Ask if user wants to continue */
		std::cout << "Make another purchase? Y/N ";
		std::cin >> choice;
		std::cin.ignore();


	} while (choice != 'N' && choice != 'n');

	std::cout << "You quited.\n";

	return 0;

}

}


}

18. A game of 21
{

Dice class 
{

> class specification
{

#ifndef DICE_H
#define DICE_H

#include <ctime>
#include <cstdlib>

class Dice
{
private:
	int side; //maximum side of the dice
	int sideup; //current value of the up side 
	int total_rolled; //total number rolled by this dice
public:
	/* Constructor (both constructor will seed random generator) */
	Dice(); //default constructor, will create a 6-sided dice, initialize sideup with 1, total_rolled with 0
	Dice(int side_input); //constructor, to set the dice's side to side_input 
	
	/* Mutator */
	int roll(); //roll the dice 
	
	/* Accessor */
	int get_sideup() const; //return current sideup value of the dice 
	int get_side() const; //return the maximum side of the dice 
	int get_rolled_num() const; //return the number this dice has rolled 
	
};

#endif

}

> class implementation 
{

#include "Dice.h"

#include <ctime>
#include <cstdlib>

/* Constructor (both constructor will seed random generator) */
Dice::Dice() //default constructor, will create a 6-sided dice, initialize sideup with 1, total_rolled with 0
{
	side = 6;
	sideup = 1;
	total_rolled = 0;

	srand((unsigned int)time(0));
}

Dice::Dice(int side_input) //constructor, to set the dice's side to side_input 
{
	side = side_input;
	sideup = 1;
	total_rolled = 0;

	srand((unsigned int)time(0));
}

/* Mutator */
int Dice::roll() //roll the dice 
{
	int N_max = side, N_min = 1;
	sideup = rand() % (N_max + N_min - 1) + N_min;
	total_rolled++;
	return sideup;
}

/* Accessor */
int Dice::get_sideup() const //return current sideup value of the dice 
{
	return sideup;
}
int Dice::get_side() const //return the maximum side of the dice 
{
	return side;
}
int Dice::get_rolled_num() const //return the number this dice has rolled 
{
	return total_rolled;
}


}


}

main program 
{

#include <iostream>
#include "Dice.h"

int main()
{
	int player_score = 0;
	int computer_score = 0;
	char choice_play; //hold user's quit choice
	char choice_acc; //hold user's accumulation choice 

	Dice dice1;
	Dice dice2;

	do
	{
		/* Ask the user whether he wants to roll to increase score */
		std::cout << "Do you want to roll the dice to accumulate points? (y/n) ";
		std::cin >> choice_acc;

		/* Roll the dice based on user's choice */
		if (choice_acc == 'y')
		{
			std::cout << "\nRolling dices for you...\n";
			std::cout << "Dice 1: " << dice1.roll() << "\n";
			std::cout << "Dice 2: " << dice2.roll() << "\n";
			//update player score
			player_score = player_score + dice1.get_sideup() + dice2.get_sideup();
			std::cout << "Your current score: " << player_score << "\n";
			//break loop if player_score is larger than 21
			if (player_score > 21)
				break;
		}

		/* Roll the dice for computer */
		//roll
		std::cout << "\nRolling dices for computer...\n";
		dice1.roll();
		dice2.roll();
		//update computer score
		computer_score = computer_score + dice1.get_sideup() + dice2.get_sideup();

		/* Ask if user wants to quit */
		std::cout << "Do you want another run? y/n";
		std::cin >> choice_play;

	} while (choice_play == 'y');

	/* Display quit information */
	if (player_score > 21)
		std::cout << "Your score has exceeded 21.\n";
	else
		std::cout << "You quited.\n";

	/* Show result */
	std::cout << "Result:\n"
		<< "Your score: " << player_score << "\n"
		<< "Computer score: " << computer_score << "\n";

	if (player_score > 21 && computer_score > 21)
		std::cout << "You both lose!\n";
	else if (player_score > 21 && computer_score < 21)
		std::cout << "Computer wins!\n";
	else if (player_score < 21 && computer_score > 21)
		std::cout << "You win!\n";
	else if (player_score < 21 && computer_score < 21)
	{
		if (player_score > computer_score)
			std::cout << "You win!\n";
		else
			std::cout << "Computer wins!\n";
	}

	return 0;


}

}

}

19. Trivia game 
{

Question class 
{

1) class specification
{

#ifndef QUESTION_H
#define QUESTION_H

#include <string>

class Question
{
private:
	std::string question;
	std::string ans_1;
	std::string ans_2;
	std::string ans_3;
	std::string ans_4;
	int correct; //store the correct answer
public:
	/* Constructor */
	Question(); //initialize each slot with zero or N/A

	/* Mutator */
	void set_question(std::string q);
	void set_a1(std::string a1);
	void set_a2(std::string a2);
	void set_a3(std::string a3);
	void set_a4(std::string a4);
	void set_key(int key);

	/* Accessor */
	std::string get_question() const
	{
		return question;
	}
	std::string get_ans1() const
	{
		return ans_1;
	}
	std::string get_ans2() const
	{
		return ans_2;
	}
	std::string get_ans3() const
	{
		return ans_3;
	}
	std::string get_ans4() const
	{
		return ans_4;
	}
	int get_key() const
	{
		return correct;
	}
};

#endif

}

2) class implementation
{

#include "Question.h"
#include <string>

Question::Question() //contains all text and correct answer 
{
	question = "N/A";
	ans_1 = "N/A";
	ans_2 = "N/A";
	ans_3 = "N/A";
	ans_4 = "N/A";
	correct = 0;
}

void Question::set_question(std::string q)
{
	question = q;
}
void Question::set_a1(std::string a1)
{
	ans_1 = a1;
}
void Question::set_a2(std::string a2)
{
	ans_2 = a2;
}
void Question::set_a3(std::string a3)
{
	ans_3 = a3;
}
void Question::set_a4(std::string a4)
{
	ans_4 = a4;
}
void Question::set_key(int key)
{
	correct = key;
}

}


}

main program 
{

//pay attention to the txt file which stores trivia question 

#include <iostream>
#include "Question.h"
#include <fstream>

const int SIZE = 10;

void initialize_text(std::string *q_text, std::string *a1_text, std::string *a2_text, std::string *a3_text, std::string *a4_text, int *correct_index); //initialize all question, answer text and correct index
void play(Question *questions, int &score_1, int &score_2);
void show_question(Question q, int &selection);

int main()
{
	//define containers for question, answer and correct index
	std::string q_text[SIZE];
	std::string a1_text[SIZE];
	std::string a2_text[SIZE];
	std::string a3_text[SIZE];
	std::string a4_text[SIZE];
	int correct_index[SIZE];
	//initialize these container
	initialize_text(q_text, a1_text, a2_text, a3_text, a4_text, correct_index);

	/* Define a Question object array and store value */
	Question questions[SIZE];
	//use a loop to set value in the array (each object)
	for (int i = 0; i < SIZE; i++)
	{
		questions[i].set_question(q_text[i]);
		questions[i].set_a1(a1_text[i]);
		questions[i].set_a2(a2_text[i]);
		questions[i].set_a3(a3_text[i]);
		questions[i].set_a4(a4_text[i]);
		questions[i].set_key(correct_index[i]);
	}

	/* Define player score, pass to play function */
	int score_1 = 0;
	int score_2 = 0;
	play(questions, score_1, score_2);

	/* Analyze result and show winner */
	//display score
	std::cout << "Player 1 got: " << score_1;
	std::cout << (score_1 > 1 ? " scores\n" : " score\n");
	std::cout << "Player 2 got: " << score_2;
	std::cout << (score_2 > 1 ? " scores\n" : " score\n");

	//display result
	if (score_1 == score_2)
		std::cout << "Player 1 and player 2 are draw\n";
	else if (score_1 > score_2)
		std::cout << "Player 1 win!\n";
	else
		std::cout << "Player 2 win!\n";

	return 0;
}

void initialize_text(std::string *q_text, std::string *a1_text, std::string *a2_text, std::string *a3_text, std::string *a4_text, int *correct_index) //initialize all question, answer text and correct index
{
	/* Create a file stream object */
	std::fstream file;
	file.open("C:\\Users\\cheng yingying\\Desktop\\trivia question\\q_text.txt", std::ios::in);
	//fill q_text[]
	for (int i = 0; i < SIZE; i++)
		getline(file, q_text[i]);
	//reset
	file.close();
	file.open("C:\\Users\\cheng yingying\\Desktop\\trivia question\\a1_text.txt", std::ios::in);
	//fill a1_text
	for (int i = 0; i < SIZE; i++)
		getline(file, a1_text[i]);
	//reset
	file.close();
	file.open("C:\\Users\\cheng yingying\\Desktop\\trivia question\\a2_text.txt", std::ios::in);
	//fill a2_text
	for (int i = 0; i < SIZE; i++)
		getline(file, a2_text[i]);
	//reset
	file.close();
	file.open("C:\\Users\\cheng yingying\\Desktop\\trivia question\\a3_text.txt", std::ios::in);
	//fill a3_text
	for (int i = 0; i < SIZE; i++)
		getline(file, a3_text[i]);
	//reset
	file.close();
	file.open("C:\\Users\\cheng yingying\\Desktop\\trivia question\\a4_text.txt", std::ios::in);
	//fill a4_text
	for (int i = 0; i < SIZE; i++)
		getline(file, a4_text[i]);
	//reset
	file.close();
	file.open("C:\\Users\\cheng yingying\\Desktop\\trivia question\\correct_index.txt", std::ios::in);
	//fill correct_index
	for (int i = 0; i < SIZE; i++)
		file >> correct_index[i];
	//close file stream object
	file.close();
}

void play(Question *questions, int &score_1, int &score_2)
{
	int selection; //hold selection by different player

	/* Use a loop to go over 10 questions */
	for (int i = 0; i < SIZE; i++)
	{
		if (i % 2 == 0)
			std::cout << "Player 1 turn:\n";
		else
			std::cout << "Player 2 turn:\n";

		//show question and get selection
		show_question(questions[i], selection);

		//update score if correct, show correct answer if wrong
		if (selection == questions[i].get_key())
		{
			std::cout << "Correct!\n";

			if (i % 2 == 0)
				score_1++;
			else
				score_2++;
		}
		else
		{
			std::cout << "Wrong! Correct answer: " << static_cast<char>(questions[i].get_key() + 64) << "\n";
		}

		//press enter to continue
		std::cout << "Press enter to continue next turn...";
		std::cin.get();
		std::cout << "\n";
	}
}
//show question and prompt user to input 
void show_question(Question q, int &selection)
{
	char choice;
	std::cout << q.get_question() << "\n"
		<< "A) " << q.get_ans1() << "\n"
		<< "B) " << q.get_ans2() << "\n"
		<< "C) " << q.get_ans3() << "\n"
		<< "D) " << q.get_ans4() << "\n";
	std::cout << "Your choice: ";
	std::cin >> choice;
	while (!((choice >= 65 && choice <= 68) || (choice >= 97 && choice <= 100)))
	{
		std::cout << "Invalid choice, please input A, B, C or D: ";
		std::cin >> choice;
	}
	std::cin.ignore(); //skip '\n'

	switch (choice)
	{
	case 'A':
	case 'a':
		selection = 1; break;
	case 'B':
	case 'b':
		selection = 2; break;
	case 'C':
	case 'c':
		selection = 3; break;
	case 'D':
	case 'd':
		selection = 4; break;
	}
}

}

}

20. Patient fees
{

Patient_account class 
{
1) specification
{

#ifndef PATIENT_ACCOUNT_H
#define PATIENT_ACCOUNT_H

class Patient_account
{
private:
	double total_charge; //hold total charge for the patient, including in-hospital fee, surgery fee and medication fee; should be initialized with zero by constructor
	double daily_rate; //hold the daily charge of the hospital, should be initialized by constructor, used to calculate base fee (daily_rate * num_stay)
	int num_stay; //hold the number of staying days, used to calculate base fee, should be initialized by constructor 
	double surgery_charge; //hold surgery charge 
	double medication_charge; //hold medication charge 
public:
	/* Constructor */
	Patient_account(int stay); //set corresponding daily_rate and num_stay, then calculate the base fee and store into total_charge 
	
	/* Mutator */
	void add_to_total_charge(double cost); //add cost to total_charge, called by member function in Surgery and Pharmacy to add surgery or pharmacy fee to the total charge 
	void set_surgery_charge(double cost); //called by surgery object
	void set_medication_charge(double cost); //called by pharmacy object
	
	/* Accessor */
	void display_charge() const; //display details of the bill 
};

#endif

}

2) implementation 
{

#include "Patient_account.h"
#include <iomanip>
#include <iostream>

/* Constructor */
Patient_account::Patient_account(int stay) //set corresponding daily_rate and num_stay, then calculate the base fee and store into total_charge 
{
	daily_rate = 125.0;
	num_stay = stay;
	surgery_charge = 0.0;
	medication_charge = 0.0;
	total_charge = daily_rate * num_stay;
}

/* Mutator */
void Patient_account::add_to_total_charge(double cost) //add cost to total_charge, called by member function in Surgery and Pharmacy to add surgery or pharmacy fee to the total charge
{
	total_charge += cost;
}

void Patient_account::set_surgery_charge(double cost)
{
	surgery_charge += cost;
}

void Patient_account::set_medication_charge(double cost)
{
	medication_charge += cost;
}

/* Accessor */
void Patient_account::display_charge() const //display details of the bill 
{
	std::cout << std::setprecision(2) << std::fixed;
	std::cout << "Patient bill:\n"
		<< "Daily rate: $" << daily_rate << "\n"
		<< "Days stayed: " << num_stay << "\n"
		<< "Surgery charge: $" << surgery_charge << "\n"
		<< "Medication charge: $" << medication_charge << "\n"
		<< "Total: $" << total_charge << "\n";
}

}

}

Surgery class 
{

1) specification
{

#ifndef SURGERY_H
#define SURGERY_H

#include "Patient_account.h" //to update charges variable stored in Patient_account, by calling add_to_total_charge() member function in Patient_account

class Surgery
{
private:
	double s1; //surgery cost for s1
	double s2; //surgery cost for s2
	double s3; //surgery cost for s3
	double s4; //surgery cost for s4
	double s5; //surgery cost for s5
public:
	/* Constructor */
	Surgery(); //to initialize the cost for each surgery 
	
	/* Accessor */
	void display_surgery_cost() const; //display cost for each surgery, called in choosing surgery menu
	
	/* Method */
	void choose_surgery(Patient_account &p); //ask user to input choice of surgery, then call add_to_total_charge() to add corresponding charge to patient account
};


#endif

}

2) implementation
{

#include <iostream>
#include "Surgery.h"
#include "Patient_account.h"

/* Constructor */
Surgery::Surgery() //to initialize the cost for each surgery 
{
	s1 = 100.0;
	s2 = 200.0;
	s3 = 300.0;
	s4 = 400.0;
	s5 = 500.0;
}

/* Accessor */
void Surgery::display_surgery_cost() const //display cost for each surgery, called in choosing surgery menu
{
	std::cout << "Surgery type and cost:\n"
		<< "Type_1: $" << s1 << "\n"
		<< "Type_2: $" << s2 << "\n"
		<< "Type_3: $" << s3 << "\n"
		<< "Type_4: $" << s4 << "\n"
		<< "Type_5: $" << s5 << "\n"
		<< "\n";
}

/* Method */
void Surgery::choose_surgery(Patient_account &p) //ask user to input choice of surgery, then call add_to_total_charge() to add corresponding charge to patient account
{
	char choice;
	std::cout << "Input the surgery type: ";
	std::cin >> choice;
	std::cin.ignore();

	switch (choice)
	{
	case '1': p.add_to_total_charge(s1); p.set_surgery_charge(s1); break;
	case '2': p.add_to_total_charge(s2); p.set_surgery_charge(s2); break;
	case '3': p.add_to_total_charge(s3); p.set_surgery_charge(s3); break;
	case '4': p.add_to_total_charge(s4); p.set_surgery_charge(s4); break;
	case '5': p.add_to_total_charge(s5); p.set_surgery_charge(s5); break;
	}

	std::cout << "Surgery cost has been recorded, press enter to continue.\n";
	std::cin.get();
}


}

}

Pharmacy class 
{

1) specification
{

#ifndef PHARMACY_H
#define PHARMACY_H

#include "Patient_account.h"

class Pharmacy
{
private:
	double m1;
	double m2;
	double m3;
	double m4;
	double m5;
public:
	/* Constructor */
	Pharmacy(); //to initialize cost of each medication
	
	/* Accessor */
	void display_medication_cost() const; //to display cost for each medication 
	
	/* Method */
	void choose_medication(Patient_account &p) const; //ask user to input choice of medication, then call add_to_total_charge() to add corresponding charge to patient account
};

#endif

}

2) implementation 
{

#include <iostream>
#include "Patient_account.h"
#include "Pharmacy.h"

/* Constructor */
Pharmacy::Pharmacy() //to initialize cost of each medication
{
	m1 = 10.0;
	m2 = 20.0;
	m3 = 30.0;
	m4 = 40.0;
	m5 = 50.0;
}

/* Accessor */
void Pharmacy::display_medication_cost() const //to display cost for each medication 
{
	std::cout << "Pharmacy type and cost:\n"
		<< "Type_1: $" << m1 << "\n"
		<< "Type_2: $" << m2 << "\n"
		<< "Type_3: $" << m3 << "\n"
		<< "Type_4: $" << m4 << "\n"
		<< "Type_5: $" << m5 << "\n"
		<< "\n";
}

/* Method */
void Pharmacy::choose_medication(Patient_account &p) const //ask user to input choice of medication, then call add_to_total_charge() to add corresponding charge to patient account
{
	char choice;
	std::cout << "Input the medication type: ";
	std::cin >> choice;
	std::cin.ignore();

	switch (choice)
	{
	case '1': p.add_to_total_charge(m1); p.set_medication_charge(m1); break;
	case '2': p.add_to_total_charge(m2); p.set_medication_charge(m2); break;
	case '3': p.add_to_total_charge(m3); p.set_medication_charge(m3); break;
	case '4': p.add_to_total_charge(m4); p.set_medication_charge(m4); break;
	case '5': p.add_to_total_charge(m5); p.set_medication_charge(m5); break;
	}

	std::cout << "Pharmacy cost has been recorded, press enter to continue.\n";
	std::cin.get();
}



}

}

Main program 
{

#include <iostream>
#include "Patient_account.h"
#include "Surgery.h"
#include "Pharmacy.h"

void charge_input(Patient_account &p); //used to input charge 
void display_menu(char &choice); //display input menu

int main()
{
	/* Define account object */
	int num_stay;
	std::cout << "How many days stayed: ";
	std::cin >> num_stay;
	Patient_account p1(num_stay);

	/* Call charge_input() function to input surgery and medication charge */
	charge_input(p1);

	/* Call Patient_account's member function display_charge() to display charge */
	std::cout << "\nYour input is complete, press enter to view the patient's bill.\n";
	std::cin.get();
	p1.display_charge();

	return 0;

}

void charge_input(Patient_account &p) //used to input charge 
{
	char choice; //hold user's choice 
	bool surgery_inputed = false; //to indicate whether the surgery cost is recorded
	bool pharmacy_inputed = false; //to indicate whether the pharmacy cost is recorded 
	Surgery s;
	Pharmacy m;

	do
	{
		display_menu(choice);

		switch (choice)
		{
		case '1':
			//Surgery s;
			s.display_surgery_cost();
			s.choose_surgery(p);
			surgery_inputed = true;
			break;
		case '2':
			//Pharmacy m;
			m.display_medication_cost();
			m.choose_medication(p);
			pharmacy_inputed = true;
			break;
		}
	} while (!(surgery_inputed && pharmacy_inputed));


}
void display_menu(char &choice) //display input menu
{
	std::cout << "Please select one term below to input charge info. Program will continue after surgery and pharmacy charges are both inputed.\n"
		<< "1) input surgery charge;\n"
		<< "2) input pharmacy charge;\n";
	std::cin >> choice;
	while (choice != '1' && choice != '2')
	{
		std::cout << "Invalid input, please choose 1 or 2: ";
		std::cin >> choice;
	}
	std::cin.ignore();
}

}

}






































/**********************************************************/
/** Patience and diligence, like faith, remove mountains **/
/**********************************************************/



