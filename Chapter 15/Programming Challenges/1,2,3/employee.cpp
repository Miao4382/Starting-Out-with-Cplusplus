#include "employee.h"
#include <string>

/* Constructor */
// default constructor
Employee::Employee()
{
  name_ = "N/A";
  empid_ = "000000";
  hire_date_ = "01/01/1900";
}
// constructor 
Employee::Employee(std::string n, std::string id, std::string date)
{
  name_ = n;
  empid_ = id;
  hire_date_ = date;  
}