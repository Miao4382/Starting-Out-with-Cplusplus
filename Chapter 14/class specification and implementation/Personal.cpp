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