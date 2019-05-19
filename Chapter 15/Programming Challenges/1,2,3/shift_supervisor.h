#ifndef SHIFT_SUPERVISOR_H
#define SHIFT_SUPERVISOR_H
#include "employee.h"

class ShiftSupervisor : public Employee
{
private:
  double annual_salary_;
  double annual_bonus_;
public:
  /* Constructor */
  // default constructor
  ShiftSupervisor();
  // constructor 
  ShiftSupervisor(std::string n, std::string id, std::string date, double a_s, double a_b);
  
  /* Mutator */
  void set_annual_salary(double a_s)
  { annual_salary_ = a_s; }
  void set_annual_bonus(double a_b)
  { annual_bonus_ = a_b; }
  
  /* Accessor */
  double annual_salary() const 
  { return annual_salary_; }
  double annual_bonus() const 
  { return annual_bonus_; }
  
};


#endif