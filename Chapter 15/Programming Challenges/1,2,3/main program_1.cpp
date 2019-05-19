#include <iostream>
#include "production_worker.h"

int main()
{
  ProductionWorker worker_1("Miao", "00001", "05/05/1990", 1, 1.2);
  std::cout << "Name: " << worker_1.name() << "\n"
    << "EMPID: " << worker_1.empid() << "\n"
    << "Join Date: " << worker_1.hire_date() << "\n"
    << "Shift: ";
  std::cout << (worker_1.shift() == 1 ? "Day Shift" : "Night Shift") << "\n";
  std::cout << "Pay Rate: " << worker_1.hour_pay_rate() << "\n";

  return 0;
}