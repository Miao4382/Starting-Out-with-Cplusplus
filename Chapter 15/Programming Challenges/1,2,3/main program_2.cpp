#include <iostream>
#include "shift_supervisor.h"

int main()
{
  ShiftSupervisor supervisor_1("Miao", "00001", "05/05/1990", 100000, 5000);
  std::cout << "Name: " << supervisor_1.name() << "\n"
    << "EMPID: " << supervisor_1.empid() << "\n"
    << "Join Date: " << supervisor_1.hire_date() << "\n"
    << "Annual Salary: $" << supervisor_1.annual_salary() << "\n"
    << "Annual Bonus: $" << supervisor_1.annual_bonus() << "\n";

  return 0;
}