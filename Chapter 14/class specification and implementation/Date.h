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