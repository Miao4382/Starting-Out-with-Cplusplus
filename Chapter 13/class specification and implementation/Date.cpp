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