// this is ab abstract base class 
#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student
{
protected:
  std::string name_; // hold student name 
  std::string id_; // hold student ID
  int year_admitted_; // hold the year of admission
public:
  /* Constructor */
  // default constructor
  Student()
  {
    name_ = "N/A";
    id_ = "LG00000";
    year_admitted_ = 0;
  }
  
  // initialize with info 
  Student(std::string n, std::string id, int year)
  {
    name_ = n;
    id_ = id;
    year_admitted_ = year;
  }
  
  /* Accessor */
  std::string name() const 
  { return name_; }
  std::string id() const 
  { return id_; }
  int year_admitted() const 
  { return year_admitted_; }
  
  /* Mutator */
  void set_name(std::string n)
  { name_ = n; }
  void set_id(std::string id)
  { id_ = id; }
  void set_year(int y)
  { year_admitted_ = y; }
  
  /* Pure virtual function */
  virtual void GetRemainingHours() const = 0;
};


#endif