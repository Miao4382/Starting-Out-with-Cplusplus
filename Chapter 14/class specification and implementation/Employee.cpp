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