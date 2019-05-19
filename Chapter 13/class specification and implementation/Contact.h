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
	const char *get_name();
	const char *get_phone();
};

#endif

