#include "cs_student.h"
#include <iostream>

/* Constructor */
// default constructor, will assign zero to each private variable
// call default constructor of Student class
CsStudent::CsStudent() : Student()
{
  math_hour_ = 0;
  cs_hour_ = 0;
  gen_hour_ = 0;
}

// accepts math_hour, cs_hour, gen_hour and info of Student
// call second constructor of Student
CsStudent::CsStudent(std::string n, std::string id, int year, int m_h, int c_h, int g_h) : Student(n, id, year)
{
  math_hour_ = m_h;
  cs_hour_ = c_h;
  gen_hour_ = g_h;  
}


/* Virtual functions */
// this function is specific to this class 
void CsStudent::GetRemainingHours() const
{
  std::cout << "Student name: " << name() << "\n"
  << "Student ID: " << id() << "\n";
  
  if (math_hour_ - MATH_HOURS >= 0)
    std::cout << "Remaining math hours: 0\n";
  else 
    std::cout << "Remaining math hours: " << MATH_HOURS - math_hour_ << "\n";
  
  if (cs_hour_ - CS_HOURS >= 0)
    std::cout << "Remaining cs hours: 0\n";
  else 
    std::cout << "Remaining cs hours: " << CS_HOURS - cs_hour_ << "\n";

  if (gen_hour_ - GEN_HOURS >= 0)
    std::cout << "Remaining general education hours: 0\n";
  else 
    std::cout << "Remaining general education hours: " << GEN_HOURS - gen_hour_ << "\n";  
}