#include "Date.h"
#include <iostream>
#include <cstdlib>

int main()
{
  try
  {
    Date day(2,3,2012);
    std::cout << "Date: ";
    day.Display();
    std::cout << "\n";
  }
  
  catch (Date::InvalidDay obj)
  {
    std::cout << "Invalid day inputed: " << obj.invalid_day() << "\n";
    exit(0);
  }
  
  catch (Date::InvalidMonth obj)
  {
    std::cout << "Invalid month inputed: " << obj.invalid_month() << "\n";
    exit(0);
  }
  
  std::cout << "Date display complete, exiting...\n";
  
  return 0;
}