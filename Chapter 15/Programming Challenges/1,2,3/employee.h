#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee
{
protected:
  std::string name_;
  std::string empid_;
  std::string hire_date_;
public:
  /* Constructor */
  // default constructor
  Employee();
  // constructor 
  Employee(std::string n, std::string id, std::string date);
  
  /* Accessor */
  std::string name() const 
  { return name_; }
  std::string empid() const 
  { return empid_; }
  std::string hire_date() const 
  { return hire_date_; }

  /* Mutator */
  void set_name(std::string n)
  { name_ = n; }
  void set_empid(std::string id)
  { empid_ = id; }
  void set_hire_date(std::string date)
  { hire_date_ = date; }
  
};


#endif