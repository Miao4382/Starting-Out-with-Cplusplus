#include "shift_supervisor.h"

/* Constructor */
// default constructor
ShiftSupervisor::ShiftSupervisor() : Employee()
{
  annual_salary_ = 0.0;
  annual_bonus_ = 0.0;
}
// constructor 
ShiftSupervisor::ShiftSupervisor(std::string n, std::string id, std::string date, double a_s, double a_b) : Employee(n, id, date)
{
  annual_salary_ = a_s;
  annual_bonus_ = a_b;
}
