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