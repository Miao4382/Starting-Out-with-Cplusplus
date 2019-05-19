#ifndef EMPLOYEE_INFO_H
#define EMPLOYEE_INFO_H
#include <string>
#include <iostream>

class EmployeeInfo
{
private:
  int id_; // an integer which holds the employee id number
  std::string name_; // a string object which holds the name of the employee 
public:
  /* Constructor */
  // default constructor 
  EmployeeInfo()
  {
    id_ = 0;
    name_ = "N/A";
  }
  
  // constructor with only id
  EmployeeInfo(int id)
  {
    id_ = id;
    name_ = "N/A";
  }
  
  // constructor with id and name 
  EmployeeInfo(int id, std::string name)
  {
    id_ = id;
    name_ = name;
  }
  
  /* Accessor */
  int id() {
    return id_;
  }
  
  std::string name() {
    return name_;
  }
  
  /* Operator overloading */
  // >
  bool operator>(const EmployeeInfo& right) {
    if (id_ > right.id_)
      return true;
    else 
      return false;
  }
  
  // < 
  bool operator<(const EmployeeInfo& right) {
    if (id_ < right.id_)
      return true;
    else 
      return false;
  }
  
  // ==
  bool operator==(const EmployeeInfo& right) {
    if (id_ == right.id_)
      return true;
    else 
      return false;
  }
  
  // >=
  bool operator>=(const EmployeeInfo& right) {
    if (*this > right || *this == right)
      return true;
    else 
      return false;
  }
  
  // << 
  friend std::ostream& operator<<(std::ostream& out, const EmployeeInfo& obj) {
    out << "ID: " << obj.id_ << ". Name: " << obj.name_ << "\n";
    return out;
  }
  
};

#endif