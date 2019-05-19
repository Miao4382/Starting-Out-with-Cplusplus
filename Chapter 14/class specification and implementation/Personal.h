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