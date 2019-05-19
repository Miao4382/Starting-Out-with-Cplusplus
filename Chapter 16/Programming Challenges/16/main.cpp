#include "production_worker.h"
#include <iostream>

int main()
{
  ProductionWorker worker1("Yu", 5555, "05/05/1990", 2, 20);
  
  try 
  {
    worker1.set_shift(3);
  }
  catch(ProductionWorker::InvalidShift)
  {
    std::cout << "Invalid shift inputed.\n";
  }
  
  try 
  {
    worker1.set_hour_pay_rate(-2);
  }
  catch(ProductionWorker::InvalidPayRate)
  {
    std::cout << "Invalid pay rate.\n";
  }
  
  try 
  {
    worker1.set_empid(10000);
  }
  catch(Employee::InvalidEmployeeNumber)
  {
    std::cout << "Invalid employee number.\n";
  }
  
  return 0;
}