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
const char *Contact::get_name()
{
	return name;
}
//get phone function
const char *Contact::get_phone()
{
	return phone;
}






