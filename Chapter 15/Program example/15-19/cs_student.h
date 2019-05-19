#ifndef CS_STUDENT_H
#define CS_STUDENT_H
#include "student.h"
#include <string>

/* Constants for required hours */
const int MATH_HOURS = 20;
const int CS_HOURS = 40;
const int GEN_HOURS = 60;

class CsStudent : public Student
{
private:
  int math_hour_; // hold the current math hours 
  int cs_hour_; // hold the current cs hours 
  int gen_hour_; // hold the current gen_ed hours
public:
  /* Constructor */
  // default constructor, will assign zero to each private variable
  // call default constructor of Student class
  CsStudent() : Student();
  
  // accepts math_hour, cs_hour, gen_hour and info of Student
  // call second constructor of Student
  CsStudent(std::string n, std::string id, int year, int m_h, int c_h, int g_h) : Student(n, id, year);
  
  /* Mutator */
  void set_math_hour(int m_h)
  { math_hour_ = m_h; }
  void set_cs_hour(int c_h)
  { cs_hour_ = c_h; }
  void set_gen_hour(int g_h)
  { gen_hour_ = g_h; }
  
  /* Accessor */
  int math_hour() const 
  { return math_hour_; }
  int cs_hour() const 
  { return cs_hour_; }
  int gen_hour() const 
  { return gen_hour_; }
  
  /* Virtual functions */
  virtual void GetRemainingHours() const;
  
};


#endif