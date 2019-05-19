#include "team_leader.h"
#include <iostream>

int main()
{
  TeamLeader leader_1("Miao", "00001", "May 5, 1990", 1, 20.5, 120, 100, 55);
  std::cout << "Name: " << leader_1.name() << "\n"
    << "EMPID: " << leader_1.empid() << "\n"
    << "Join Date: " << leader_1.hire_date() << "\n"
    << "Shift: ";
  std::cout << (leader_1.shift() == 1 ? "Day Shift" : "Night Shift") << "\n";
  std::cout << "Pay Rate: $" << leader_1.hour_pay_rate() << "\n";
  
  std::cout << "Monthly Bonus: $" << leader_1.monthly_bonus() << "\n"
  << "Required Annual Training Hour: " << leader_1.annual_training_hour_required() << "\n"
  << "Finished Annual Training Hour: " << leader_1.annual_training_hour() << "\n";
  
  return 0;
  
}