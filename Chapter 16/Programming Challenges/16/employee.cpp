#include "employee.h"
#include <string>

/* Constructor */
// default constructor
Employee::Employee()
{
  name_ = "N/A";
  empid_ = 0;
  hire_date_ = "01/01/1900";
}

// constructor 
Employee::Employee(std::string n, int id, std::string date)
{
  if (id < 0 || id > 9999)
    throw InvalidEmployeeNumber();
  
  name_ = n;
  empid_ = id;
  hire_date_ = date;  
}