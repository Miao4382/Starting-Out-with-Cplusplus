#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee
{
protected:
  std::string name_;
  int empid_;
  std::string hire_date_;
public:
  /* Constructor */
  // default constructor
  Employee();
  // constructor 
  Employee(std::string n, int id, std::string date);
  
  /* Accessor */
  std::string name() const 
  { return name_; }
  int empid() const 
  { return empid_; }
  std::string hire_date() const 
  { return hire_date_; }

  /* Mutator */
  void set_name(std::string n)
  { name_ = n; }
  void set_empid(int id)
  { 
    if (id < 0 || id > 9999)
      throw InvalidEmployeeNumber();
    
    empid_ = id; 
  }
  
  void set_hire_date(std::string date)
  { hire_date_ = date; }
  
  /* Exception class */
  class InvalidEmployeeNumber
  {};
  
};


#endif